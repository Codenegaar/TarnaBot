#ifndef INLINEQUERYRESULT_H
#define INLINEQUERYRESULT_H

#include <QString>
#include <QJsonObject>
#include <QVariant>

#include "inputmessagecontent.h"
#include "inlinekeyboardmarkup.h"

class InlineQueryResult
{
public:
    InlineQueryResult();
    
    QString getType() const;
    void setType(const QString &value);
    
    QString getId() const;
    void setId(const QString &value);
    
    InputMessageContent getInputMessageContent() const;
    void setInputMessageContent(const InputMessageContent &value);
    
    InlineKeyboardMarkup getReplyMarkup() const;
    void setReplyMarkup(const InlineKeyboardMarkup &value);
    
protected:
    QString type;
    QString id;
    
    InputMessageContent inputMessageContent;
    InlineKeyboardMarkup replyMarkup;
    
    QJsonObject root;
};

#endif // INLINEQUERYRESULT_H
