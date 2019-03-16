#include "include/tarnabasicsender.h"

#include <QEventLoop>
#include <QFile>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>

TarnaBasicSender::TarnaBasicSender(const QString &token) :
    TarnaSender(),
    mToken(token)
{
    mUrl = "https://api.telegram.org/bot" + token + '/';
}

QJsonObject TarnaBasicSender::sendJsonRequest(
        const QJsonObject &jsonObject, const QString &apiMethod)
{
    QNetworkAccessManager* manager;
    QNetworkRequest request;
    QUrl url;
    QEventLoop loop;

    url.setUrl(mUrl + apiMethod);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(url);

    QObject::connect(manager, &QNetworkAccessManager::finished,
                     &loop, &QEventLoop::quit);

    QNetworkReply* reply;
    reply = manager->post(request, QJsonDocument(jsonObject).toJson());
    loop.exec();

    QJsonObject result;
    result = QJsonDocument::fromJson(reply->readAll()).object();
    delete reply;
    delete manager;
    return result;
}

QJsonObject TarnaBasicSender::sendMultipartRequest(
        const QString &path, const QString &fileNameParameter,
        const QUrlQuery &urlQuery, const QString &apiMethod)
{
    QHttpMultiPart* multiPart;
    QHttpPart part;
    QFile* file;

    QNetworkRequest request;
    QNetworkAccessManager* manager;
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

    QObject::connect(manager, &QNetworkAccessManager::finished,
                     &loop, &QEventLoop::quit);
    reply = manager->post(request, multiPart);
    loop.exec();

    QJsonObject result;
    result = QJsonDocument(reply->readAll()).object();
    delete reply;
    delete manager;
    file->close();
    delete file;
    delete multiPart;
    return result;
}
