/**
  Note: Setters are for development purposes only.
  */
#ifndef UPDATE_H
#define UPDATE_H

#include <QJsonObject>
#include <QVariant>

#include "message.h"
#include "callbackquery"
#include "shippingquery.h"
#include "precheckoutquery.h"
#include "inlinequery.h"
#include "choseninlineresult.h"

class Update
{
public:
    Update(QJsonObject obj);
    Update();
    
    static Update fromObject(QJsonObject obj);
    
    QJsonObject getObject();
    
    
    
private:
    long long int updateId;
    
    Message message;
    Message editedMessage;
    Message channelPost;
    Message editedChannelPost;
    
    InlineQuery inlineQuery;
    ChosenInlineResult chosenInlineResult;
    CallbackQuery callbackQuery;
    ShippingQuery shippingQuery;
    PreCheckoutQuery preCheckoutQuery;
    
    QJsonObject root;
};

#endif //UPDATE_H
