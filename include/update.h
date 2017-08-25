#ifndef UPDATE_H
#define UPDATE_H

#include <QJsonObject>
#include <QVariant>
/**
  Note: Setters are for development purposes only.
  */
#include "message.h"
//#include "callbackquery"
//#include "shippingquery.h"
//#include "precheckoutquery"

class Update
{
public:
    Update(QJsonObject obj);
    
    QJsonObject getObject();
    void setUpdateId(long long int value);
    long long int getUpdateId();
    
    Message *getMessage() const;
    void setMessage(Message *value);
    
    
    Message *getEditedMessage() const;
    void setEditedMessage(Message *value);
    
    
    Message *getChannelPost() const;
    void setChannelPost(Message *value);
    
    
    Message *getEditedChannelPost() const;
    void setEditedChannelPost(Message *value);
    
    /*
    CallbackQuery *getCallbackQuery() const;
    void setCallbackQuery(CallbackQuery *value);
    
    ShippingQuery *getShippingQuery() const;
    void setShippingQuery(ShippingQuery *value);
    
    
    PreCheckoutQuery *getPreCheckoutQuery() const;
    void setPreCheckoutQuery(PreCheckoutQuery *value);
    */
private:
    long long int updateId;
    
    Message *message;
    Message *editedMessage;
    Message *channelPost;
    Message *editedChannelPost;
    
    //CallbackQuery *callbackQuery;
    //ShippingQuery *shippingQuery;
    //PreCheckoutQuery *preCheckoutQuery;
    QJsonObject root;
};

#endif //UPDATE_H
