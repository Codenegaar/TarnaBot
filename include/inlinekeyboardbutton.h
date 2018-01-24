#ifndef INLINEKEYBOARDBUTTON_H
#define INLINEKEYBOARDBUTTON_H

#include <QString>

#include "tarnaobject.h"
#include "callbackgame.h"

class InlineKeyboardButton : public TarnaObject
{
public:
    InlineKeyboardButton(QJsonObject obj);
    InlineKeyboardButton();
    
    static InlineKeyboardButton fromObject(QJsonObject obj);

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
    
private:
    QString text;
    QString url;
    QString callbackData;
    QString switchInlineQuery;
    QString switchInlineQueryCurrentChat;
    
    bool pay;
    
    CallbackGame callbackGame;
};


#endif // INLINEKEYBOARDBUTTON_H
