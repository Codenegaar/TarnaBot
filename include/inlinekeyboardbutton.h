#ifndef INLINEKEYBOARDBUTTON_H
#define INLINEKEYBOARDBUTTON_H

#include <QString>

#include "TelegramObject"
#include "CallbackGame"

namespace Telegram
{
    class InlineKeyboardButton : public TelegramObject
    {
    public:
        InlineKeyboardButton();
        InlineKeyboardButton(QJsonObject jsonObject);
        InlineKeyboardButton(QString text);
    
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
    };
}

#endif // INLINEKEYBOARDBUTTON_H
