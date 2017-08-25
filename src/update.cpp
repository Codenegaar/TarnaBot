#include "../include/update.h"

Update::Update(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    updateId = root["update_id"].toVariant().toLongLong(&ok);
}

long long int Update::getUpdateId()
{
    return updateId;
}

QJsonObject Update::getObject()
{
    return root;
}

void Update::setUpdateId(long long int value)
{
    updateId = value;
}

Message *Update::getMessage() const
{
    return message;
}

void Update::setMessage(Message *value)
{
    message = value;
}

Message *Update::getEditedMessage() const
{
    return editedMessage;
}

void Update::setEditedMessage(Message *value)
{
    editedMessage = value;
}

Message *Update::getChannelPost() const
{
    return channelPost;
}

void Update::setChannelPost(Message *value)
{
    channelPost = value;
}

Message *Update::getEditedChannelPost() const
{
    return editedChannelPost;
}

void Update::setEditedChannelPost(Message *value)
{
    editedChannelPost = value;
}
/*
CallbackQuery *Update::getCallbackQuery() const
{
    return callbackQuery;
}

void Update::setCallbackQuery(CallbackQuery *value)
{
    callbackQuery = value;
}

ShippingQuery *Update::getShippingQuery() const
{
    return shippingQuery;
}

void Update::setShippingQuery(ShippingQuery *value)
{
    shippingQuery = value;
}

PreCheckoutQuery *Update::getPreCheckoutQuery() const
{
    return preCheckoutQuery;
}

void Update::setPreCheckoutQuery(PreCheckoutQuery *value)
{
    preCheckoutQuery = value;
}
*/
