#ifndef CALLBACKQUERY_H
#define CALLBACKQUERY_H
//
#include <QJsonObject>
#include <QString>

#include "message.h"
#include "user.h"

class CallbackQuery
{
public:
    CallbackQuery(QJsonObject obj);
    CallbackQuery();
    
    static CallbackQuery fromObject(QJsonObject obj);
    QJsonObject toObject();
    void refresh();
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
    
    QJsonObject root;
};

#endif // CALLBACKQUERY_H
