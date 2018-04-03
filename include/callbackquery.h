#ifndef CALLBACKQUERY_H
#define CALLBACKQUERY_H

#include <QString>

#include "tarnaobject.h"
#include "message.h"
#include "user.h"

namespace TarnaBot
{
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
        
        //Flag getters
        bool getHasId() const;
        
        bool getHasInlineMessageId() const;
        
        bool getHasChatInstance() const;
        
        bool getHasData() const;
        
        bool getHasGameShortName() const;
        
        bool getHasFrom() const;
        
        bool getHasMessage() const;
        
    private:
        QString id;
        QString inlineMessageId;
        QString chatInstance;
        QString data;
        QString gameShortName;
        
        User from;
        Message message;
        
        //flags
        bool hasId;
        bool hasInlineMessageId;
        bool hasChatInstance;
        bool hasData;
        bool hasGameShortName;
        bool hasFrom;
        bool hasMessage;
    };
}
#endif // CALLBACKQUERY_H
