#include "include/tarnarequest.h"
using namespace Telegram;

TarnaRequest::TarnaRequest()
{
    
}

TarnaRequest::RequestType TarnaRequest::getRequestType() const
{
    return requestType;
}

void TarnaRequest::setRequestType(const RequestType &value)
{
    requestType = value;
}

QJsonObject TarnaRequest::getJsonObject() const
{
    return jsonObject;
}

void TarnaRequest::setJsonObject(const QJsonObject &value)
{
    jsonObject = value;
}

QString TarnaRequest::getFile() const
{
    return file;
}

void TarnaRequest::setFile(const QString &value)
{
    file = value;
}

QString TarnaRequest::getMethod() const
{
    return method;
}

void TarnaRequest::setMethod(const QString &value)
{
    method = value;
}

QString TarnaRequest::getFileNameParameter() const
{
    return fileNameParameter;
}

void TarnaRequest::setFileNameParameter(const QString &value)
{
    fileNameParameter = value;
}

QUrlQuery TarnaRequest::getUrlQuery() const
{
    return urlQuery;
}

void TarnaRequest::setUrlQuery(const QUrlQuery &value)
{
    urlQuery = value;
}
