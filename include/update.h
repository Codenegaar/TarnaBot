/**
  Note: Setters are for development purposes only.
  */
#ifndef UPDATE_H
#define UPDATE_H

#include <QVariant>

#include "TelegramObject"
#include "Message"
#include "CallbackQuery"
#include "ShippingQuery"
#include "PreCheckoutQuery"
#include "InlineQuery"
#include "ChosenInlineResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT Update : public TelegramObject
    {
    public:
        Update();
        Update(QJsonObject jsonObject);
        Update(qint64 updateId);
        
        //Getters/Setters
        qint64 getUpdateId() const;
        void setUpdateId(const qint64 &value);
        
        Message getMessage() const;
        void setMessage(const Message &value);
        
        Message getEditedMessage() const;
        void setEditedMessage(const Message &value);
        
        Message getChannelPost() const;
        void setChannelPost(const Message &value);
        
        Message getEditedChannelPost() const;
        void setEditedChannelPost(const Message &value);
        
        InlineQuery getInlineQuery() const;
        void setInlineQuery(const InlineQuery &value);
        
        ChosenInlineResult getChosenInlineResult() const;
        void setChosenInlineResult(const ChosenInlineResult &value);
        
        CallbackQuery getCallbackQuery() const;
        void setCallbackQuery(const CallbackQuery &value);
        
        ShippingQuery getShippingQuery() const;
        void setShippingQuery(const ShippingQuery &value);
        
        PreCheckoutQuery getPreCheckoutQuery() const;
        void setPreCheckoutQuery(const PreCheckoutQuery &value);
        
        //Flag getters
        bool hasUpdateId() const;
        
        bool hasMessage() const;
        
        bool hasEditedMessage() const;
        
        bool hasChannelPost() const;
        
        bool hasEditedChannelPost() const;
        
        bool hasInlineQuery() const;
        
        bool hasChosenInlineResult() const;
        
        bool hasCallbackQuery() const;
        
        bool hasShippingQuery() const;
        
        bool hasPreCheckoutQuery() const;
    };
}
#endif //UPDATE_H
