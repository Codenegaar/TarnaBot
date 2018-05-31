#ifndef INLINEKEYBOARDBUTTON_H
#define INLINEKEYBOARDBUTTON_H

#include <QString>

#include "tarnaobject.h"
#include "callbackgame.h"

namespace Telegram
{
    class InlineKeyboardButton : public TarnaObject
    {
    public:
        InlineKeyboardButton(QJsonObject obj);
        InlineKeyboardButton();
    
        //Getters/setters
        QString getText() const;
        void setText(const QString &value);
        
        QString getUrl() const;
        void setUrl(const QString &value);
        
        QString getCallbackData() const;
        void setCallbackData(const QString &value);
        
        QString getSwitchInlineQuery() const;
        void setSwitchInlineQuery(const QString &value);
        
        QString getSwitchInlineQueryCurrentChat() const;
        void setSwitchInlineQueryCurrentChat(const QString &value);
        
        bool getPay() const;
        void setPay(bool value);
        
        CallbackGame getCallbackGame() const;
        void setCallbackGame(const CallbackGame &value);
        
        //Flag getters
        bool hasText() const;
        
        bool hasUrl() const;
        
        bool hasCallbackData() const;
        
        bool hasSwitchInlineQuery() const;
        
        bool hasSwitchInlineQueryCurrentChat() const;
        
        bool hasCallbackGame() const;
        
    private:
        QString text;
        QString url;
        QString callbackData;
        QString switchInlineQuery;
        QString switchInlineQueryCurrentChat;
        
        bool pay;
        
        CallbackGame callbackGame;
        
        //flags
        bool _hasText;
        bool _hasUrl;
        bool _hasCallbackData;
        bool _hasSwitchInlineQuery;
        bool _hasSwitchInlineQueryCurrentChat;
        bool _hasCallbackGame;
    };
}

#endif // INLINEKEYBOARDBUTTON_H
