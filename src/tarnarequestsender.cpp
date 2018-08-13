#include "include/tarnarequestsender.h"
using namespace Telegram;

TarnaRequestSender::TarnaRequestSender(QString token) :
    mManager(new QNetworkAccessManager())
{
    baseUrl += token + "/";
    QObject::connect(mManager, &QNetworkAccessManager::finished, &mEventLoop, &QEventLoop::quit);
}

TarnaRequestSender::TarnaRequestSender(QString token, QNetworkProxy proxy) : TarnaRequestSender(token)
{
    mManager->setProxy(proxy);
}

TarnaRequestSender::TarnaRequestSender(const TarnaRequestSender &requestSender) :
    mManager(new QNetworkAccessManager())
{
    baseUrl = requestSender.baseUrl;
    QObject::connect(mManager, &QNetworkAccessManager::finished, 
                     &mEventLoop, &QEventLoop::quit);
}

TarnaRequestSender::~TarnaRequestSender()
{
    delete mManager;
    delete mReply;
}

QJsonObject TarnaRequestSender::sendRequest(TarnaRequest request)
{
    switch(request.getRequestType())
    {
    case TarnaRequest::Json:
        return sendJsonRequest(request);
        
    case TarnaRequest::Multipart:
        return sendMultipartRequest(request);
    }
}

QJsonObject TarnaRequestSender::sendJsonRequest(TarnaRequest request)
{
    QNetworkRequest netRequest;
    QUrl url;
    
    url.setUrl(baseUrl + request.getMethod());
    netRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    netRequest.setUrl(url);
    
    mReply = mManager->post(netRequest, QJsonDocument(request.getJsonObject()).toJson());
    mEventLoop.exec();
    
    return QJsonDocument::fromJson(mReply->readAll()).object();
}

QJsonObject TarnaRequestSender::sendMultipartRequest(TarnaRequest request)
{
    QHttpMultiPart* multiPart;
    QHttpPart part;
    QFile* file;
    
    QNetworkRequest netRequest;
    QUrl url;
    
    QObject::connect(mManager, &QNetworkAccessManager::finished, file, &QFile::close);
    QObject::connect(mManager, &QNetworkAccessManager::finished, multiPart, &QHttpMultiPart::deleteLater);
    
    file = new QFile(request.getFile());
    if(!file->open(QIODevice::ReadOnly))
    {
        qWarning() << "ERROR: Unable to open file to send: " << request.getFile();
        file->deleteLater();
        return QJsonObject();
    }
    
    multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QString dispositionHeader = "form-data; name=\"" + request.getFileNameParameter()
            + "\"; filename=\"" + request.getFile() + "\"";
    part.setHeader(QNetworkRequest::ContentDispositionHeader, dispositionHeader);
    part.setBodyDevice(file);
    multiPart->append(part);
    
    url.setUrl(baseUrl + request.getMethod());
    url.setQuery(request.getUrlQuery());
    netRequest.setUrl(url);
    
    mReply = mManager->post(netRequest, multiPart);
    mEventLoop.exec();
    
    delete file;
    return QJsonDocument::fromJson(mReply->readAll()).object();
}
