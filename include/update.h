/**
  Note: Setters are for development purposes only.
  */
#ifndef UPDATE_H
#define UPDATE_H

#include <QVariant>

#include "tarnaobject.h"
#include "message.h"
#include "callbackquery.h"
#include "shippingquery.h"
#include "precheckoutquery.h"
#include "inlinequery.h"
#include "choseninlineresult.h"

namespace Telegram
{
    class Update : public TarnaObject
    {
    public:
        Update(QJsonObject obj);
        Update();
        
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
        
        bool hasPrecheckoutQuery() const;
        
    private:
        qint64 updateId;
        
        Message message;
        Message editedMessage;
        Message channelPost;
        Message editedChannelPost;
        
        InlineQuery inlineQuery;
        ChosenInlineResult chosenInlineResult;
        CallbackQuery callbackQuery;
        ShippingQuery shippingQuery;
        PreCheckoutQuery preCheckoutQuery;
        
        //flags
        bool _hasUpdateId;
        bool _hasMessage;
        bool _hasEditedMessage;
        bool _hasChannelPost;
        bool _hasEditedChannelPost;
        bool _hasInlineQuery;
        bool _hasChosenInlineResult;
        bool _hasCallbackQuery;
        bool _hasShippingQuery;
        bool _hasPrecheckoutQuery;
    };
}
#endif //UPDATE_H
