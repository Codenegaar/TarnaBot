#ifndef TARNAREQUEST_H
#define TARNAREQUEST_H

/**
 * @brief TarnaRequest is the type which TarnaBot uses to
 * communicate with RequestSender.
 */

#include <QJsonObject>
#include <QUrlQuery>

namespace Telegram
{
    class TarnaRequest
    {
    public:
        //Request type
        enum RequestType
        {
            Json,
            Multipart
        };
        
        TarnaRequest();
        
        RequestType getRequestType() const;
        void setRequestType(const RequestType &value);
        
        QJsonObject getJsonObject() const;
        void setJsonObject(const QJsonObject &value);
        
        QString getFile() const;
        void setFile(const QString &value);
        
        QString getMethod() const;
        void setMethod(const QString &value);
        
        QString getFileNameParameter() const;
        void setFileNameParameter(const QString &value);
        
        QUrlQuery getUrlQuery() const;
        void setUrlQuery(const QUrlQuery &value);
        
    private:
        RequestType requestType;
        QJsonObject jsonObject;
        
        QString file;
        QString fileNameParameter;
        QUrlQuery urlQuery;
        
        QString method;
    };
}

#endif // TARNAREQUEST_H
