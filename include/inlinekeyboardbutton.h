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
        bool getHasText() const;
        
        bool getHasUrl() const;
        
        bool getHasCallbackData() const;
        
        bool getHasSwitchInlineQuery() const;
        
        bool getHasSwitchInlineQueryCurrentChat() const;
        
        bool getHasCallbackGame() const;
        
    private:
        QString text;
        QString url;
        QString callbackData;
        QString switchInlineQuery;
        QString switchInlineQueryCurrentChat;
        
        bool pay;
        
        CallbackGame callbackGame;
        
        //flags
        bool hasText;
        bool hasUrl;
        bool hasCallbackData;
        bool hasSwitchInlineQuery;
        bool hasSwitchInlineQueryCurrentChat;
        bool hasCallbackGame;
    };
}

#endif // INLINEKEYBOARDBUTTON_H
