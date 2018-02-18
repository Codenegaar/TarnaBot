#ifndef INPUTTEXTMESSAGECONTENT_H
#define INPUTTEXTMESSAGECONTENT_H

#include <QString>

#include "inputmessagecontent.h"

class InputTextMessageContent : public InputMessageContent
{
public:
    InputTextMessageContent();
    InputTextMessageContent(QJsonObject obj);
    
    static InputTextMessageContent fromObject(QJsonObject obj);
    
    //Getters/Setters
    QString getMessageText() const;
    void setMessageText(const QString &value);
    
    QString getParseMode() const;
    void setParseMode(const QString &value);
    
    bool getDisableWebPagePreview() const;
    void setDisableWebPagePreview(bool value);
    
private:
    QString messageText;
    QString parseMode;
    
    bool disableWebPagePreview;
};

#endif // INPUTTEXTMESSAGECONTENT_H
