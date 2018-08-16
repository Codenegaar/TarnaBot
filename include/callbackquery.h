#ifndef CALLBACKQUERY_H
#define CALLBACKQUERY_H

#include <QString>

#include "TelegramObject"
#include "Message"
#include "User"

namespace Telegram
{
    class CallbackQuery : public TelegramObject
    {
    public:
        CallbackQuery();
        CallbackQuery(QJsonObject jsonObject);
        CallbackQuery(QString id, User from);
    
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
        
        //Flag getters
        bool hasId() const;
        
        bool hasInlineMessageId() const;
        
        bool hasChatInstance() const;
        
        bool hasData() const;
        
        bool hasGameShortName() const;
        
        bool hasFrom() const;
        
        bool hasMessage() const;
    };
}
#endif // CALLBACKQUERY_H
