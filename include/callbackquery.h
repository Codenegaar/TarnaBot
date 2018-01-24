#ifndef CALLBACKQUERY_H
#define CALLBACKQUERY_H

#include <QString>

#include "tarnaobject.h"
#include "message.h"
#include "user.h"

class CallbackQuery : public TarnaObject
{
public:
    CallbackQuery(QJsonObject obj);
    CallbackQuery();
    
    static CallbackQuery fromObject(QJsonObject obj);

    //Getters/setters
    QString getId() const;
    void setId(const QString &value);
    
    QString getInlineMessageId() const;
    void setInlineMessageId(const QString &value);
    
    QString getChatInstance() const;
    void setChatInstance(const QString &value);
    
    QString getData() const;
    void setData(const QString &value);
    
    QString getGameShortName() const;
    void setGameShortName(const QString &value);
    
    User getFrom() const;
    void setFrom(const User &value);
    
    Message getMessage() const;
    void setMessage(const Message &value);
    
private:
    QString id;
    QString inlineMessageId;
    QString chatInstance;
    QString data;
    QString gameShortName;
    
    User from;
    Message message;
};

#endif // CALLBACKQUERY_H
