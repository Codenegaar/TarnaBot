#ifndef MESSAGEENTITY_H
#define MESSAGEENTITY_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "user.h"

namespace Telegram
{
    class MessageEntity : public TarnaObject
    {
    public:
        MessageEntity(QJsonObject obj);
        MessageEntity();
        
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
        
    private:
        qint64 offset;
        qint64 length;
        
        QString type;
        QString url;
        
        User user;
        
        //Flags
        bool _hasOffset;
        bool _hasLenght;
        bool _hasType;
        bool _hasUrl;
        bool _hasUser;
    };
}
#endif // MESSAGEENTITY_H
