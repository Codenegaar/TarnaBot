#include "../include/update.h"

Update::Update(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    updateId = root["update_id"].toVariant().toLongLong(&ok);
    
    //Optional types
    if (root.contains("message"))
        message = new Message(root["message"].toObject());
    
    if (root.contains("edited_message"))
        editedMessage = new Message(root["edited_message"].toObject());
    
    if (root.contains("channel_post"))
        channelPost = new Message(root["channel_post"].toObject());
    
    if (root.contains("edited_channel_post"))
        editedChannelPost = new Message(root["edited_channel_post"].toObject());
    
    if (root.contains("inline_query"))
        inlineQuery = new Message(root["inline_query"].toObject());
    
    if (root.contains("chosen_inline_result"))
        chosenInlineResult = new Message(root["chosen_inline_result"].toObject());
    
    if (root.contains("callback_query"))
        callbackQuery = new Message(root["callback_query"].toObject());
    
    if (root.contains("shipping_query"))
        shippingQuery = new Message(root["shipping_query"].toObject());
    
    if (root.contains("pre_checkout_query"))
        preCheckoutQuery = new Message(root["pre_checkout_query"].toObject());
}

Update::Update()
{}

Update Update::fromObject(QJsonObject obj)
{
    return Update(obj);
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

InlineQuery *Update::getInlineQuery() const
{
    return inlineQuery;
}

void Update::setInlineQuery(InlineQuery *value)
{
    inlineQuery = value;
}

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
