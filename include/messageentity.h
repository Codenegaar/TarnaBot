#ifndef MESSAGEENTITY_H
#define MESSAGEENTITY_H

#include <QString>
#include <QVariant>

#include "TelegramObject"
#include "User"

namespace Telegram
{
    class MessageEntity : public TelegramObject
    {
    public:
        MessageEntity();
        MessageEntity(QJsonObject jsonObject);
        MessageEntity(QString type, qint64 offset, qint64 length);
        
        //Getters/Setters
        qint64 getOffset() const;
        void setOffset(const qint64 &value);
        
        qint64 getLength() const;
        void setLength(const qint64 &value);
        
        QString getType() const;
        void setType(const QString &value);
        
        QString getUrl() const;
        void setUrl(const QString &value);
        
        User getUser() const;
        void setUser(const User &value);
        
        //Flag getters
        bool hasOffset() const;
        
        bool hasLenght() const;
        
        bool hasType() const;
        
        bool hasUrl() const;
        
        bool hasUser() const;
    };
}
#endif // MESSAGEENTITY_H
