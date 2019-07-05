#include "include/tarnabasicsender.h"

#include <QEventLoop>
#include <QFile>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>

TarnaBasicSender::TarnaBasicSender(const QString &token) :
    TarnaSender(),
    mNam(),
    mToken(token)
{
    mUrl = "https://api.telegram.org/bot" + token + '/';
}

TarnaBasicSender::TarnaBasicSender(const QString &token, const QNetworkProxy &proxy) :
    TarnaBasicSender(token)
{
    mNam.setProxy(proxy);
}

QJsonObject TarnaBasicSender::sendJsonRequest(
        const QJsonObject &jsonObject, const QString &apiMethod)
{
    QNetworkRequest request;
    QUrl url;
    QEventLoop loop;

    url.setUrl(mUrl + apiMethod);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

    QObject::connect(&mNam, &QNetworkAccessManager::finished,
                     &loop, &QEventLoop::quit);

    QNetworkReply* reply;
    reply = mNam.post(request, QJsonDocument(jsonObject).toJson());
    loop.exec();

    QJsonObject result;
    result = QJsonDocument::fromJson(reply->readAll()).object();
    delete reply;
    return result;
}

QJsonObject TarnaBasicSender::sendMultipartRequest(const QString &path, const QString &fileNameParameter,
        const QUrlQuery &urlQuery, const QString &apiMethod)
{
    QHttpMultiPart* multiPart;
    QHttpPart part;
    QFile* file;

    QNetworkRequest request;
    QUrl url;
    QEventLoop loop;
    QNetworkReply* reply;

    file  = new QFile(path);
    if (!file->open(QIODevice::ReadOnly))
    {
        qWarning() << "ERROR: Unable to open file to send: " << path;
        delete file;
        return QJsonObject();
    }

    multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QString dispositionHeader = "form-data; name=\"" + fileNameParameter
            + "\"; filename=\"" + path + "\"";
    part.setHeader(QNetworkRequest::ContentDispositionHeader, dispositionHeader);
    part.setBodyDevice(file);
    multiPart->append(part);

    url.setUrl(mUrl + apiMethod);
    url.setQuery(urlQuery);
    request.setUrl(url);

    QObject::connect(&mNam, &QNetworkAccessManager::finished,
                     &loop, &QEventLoop::quit);
    reply = mNam.post(request, multiPart);
    loop.exec();

    QJsonObject result;
    result = QJsonDocument::fromJson(reply->readAll()).object();
    delete reply;
    file->close();
    delete file;
    delete multiPart;
    return result;
}

QJsonObject TarnaBasicSender::sendMultipartRequest(const QVector<QString> &paths,
                                                   const QVector<QString> &fileNameParameters,
                                                   const QUrlQuery &urlQuery,
                                                   const QString &apiMethod)
{
    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    for (int i = 0; i < paths.size(); i++)
    {
        QHttpPart part;
        QFile* file = new QFile(paths[i], multiPart);
        QString dispositionHeader = "form-data; name=\"" + fileNameParameters[i]
                + "\"; filename=\"" + paths[i] + "\"";
        if (file->open(QIODevice::ReadOnly))
        {
            part.setHeader(QNetworkRequest::ContentDispositionHeader, dispositionHeader);
            part.setBodyDevice(file);
            multiPart->append(part);
        }
    }

    QNetworkRequest request;
    QUrl url;
    QEventLoop loop;
    QNetworkReply* reply;

    url.setUrl(mUrl + apiMethod);
    url.setQuery(urlQuery);
    request.setUrl(url);

    QObject::connect(&mNam, &QNetworkAccessManager::finished,
                     &loop, &QEventLoop::quit);
    reply = mNam.post(request, multiPart);
    multiPart->setParent(reply);
    loop.exec();

    QJsonObject result;
    result = QJsonDocument::fromJson(reply->readAll()).object();
    delete reply;

    return result;
}
