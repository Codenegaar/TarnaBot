#ifndef INLINEQUERYRESULT_H
#define INLINEQUERYRESULT_H

#include <QString>

#include "TelegramObject"
#include "InputMessageContent"
#include "InputTextMessageContent"
#include "InputContactMessageContent"
#include "InputLocationMessageContent"
#include "InputVenueMessageContent"

#include "InlineKeyboardMarkup"

namespace Telegram
{
    class InlineQueryResult : public TelegramObject
    {
    public:
        InlineQueryResult();
        InlineQueryResult(QJsonObject jsonObject);
        InlineQueryResult(QString type, QString id);
        
        //Getters/Setters
        QString getType() const;
        void setType(const QString &value);
        
        QString getId() const;
        void setId(const QString &value);
        
        InputMessageContent getInputMessageContent() const;
        void setInputMessageContent(const InputMessageContent& value);
        
        InlineKeyboardMarkup getReplyMarkup() const;
        void setReplyMarkup(const InlineKeyboardMarkup &value);
        
        //Flag getters
        bool hasType() const;
        
        bool hasId() const;
        
        bool hasInputMessageContent() const;
        
        bool hasReplyMarkup() const;
    };
}
#endif // INLINEQUERYRESULT_H
