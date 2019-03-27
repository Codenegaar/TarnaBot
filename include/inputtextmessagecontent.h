#ifndef INPUTTEXTMESSAGECONTENT_H
#define INPUTTEXTMESSAGECONTENT_H

#include <QString>

#include "InputMessageContent"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InputTextMessageContent : public InputMessageContent
    {
    public:
        InputTextMessageContent();
        InputTextMessageContent(QJsonObject jsonObject);
        InputTextMessageContent(QString messageText);
        
        //Getters/Setters
        QString getMessageText() const;
        void setMessageText(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        bool getDisableWebPagePreview() const;
        void setDisableWebPagePreview(bool value);
        
        //Flag getters
        bool hasMessageText() const;
        
        bool hasParseMode() const;
    };
}
#endif // INPUTTEXTMESSAGECONTENT_H
