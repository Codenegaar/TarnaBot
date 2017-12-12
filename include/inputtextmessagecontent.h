#ifndef INPUTTEXTMESSAGECONTENT_H
#define INPUTTEXTMESSAGECONTENT_H

#include <QJsonObject>

class InputTextMessageContent
{
public:
    InputTextMessageContent();
    InputTextMessageContent(QJsonObject obj);
    
    static InputTextMessageContent fromObject(QJsonObject obj);
    QJsonObject toObject();
    
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
    
    QJsonObject root;
};

#endif // INPUTTEXTMESSAGECONTENT_H
