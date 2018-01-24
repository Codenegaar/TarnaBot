#ifndef MESSAGEENTITY_H
#define MESSAGEENTITY_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"
#include "user.h"

class MessageEntity : public TarnaObject
{
public:
    MessageEntity(QJsonObject obj);
    MessageEntity();
    static MessageEntity fromObject(QJsonObject obj);
    
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
    
private:
    qint64 offset;
    qint64 length;
    
    QString type;
    QString url;
    
    User user;
};

#endif // MESSAGEENTITY_H
