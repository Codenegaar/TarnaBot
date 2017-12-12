#include "../include/update.h"

Update::Update(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    updateId = root["update_id"].toVariant().toLongLong(&ok);
    
    //Optional types
    if (root.contains("message"))
        message = Message::fromObject(root["message"].toObject());
    
    if (root.contains("edited_message"))
        editedMessage = Message::fromObject(root["edited_message"].toObject());
    
    if (root.contains("channel_post"))
        channelPost = Message::fromObject(root["channel_post"].toObject());
    
    if (root.contains("edited_channel_post"))
        editedChannelPost = Message::fromObject(root["edited_channel_post"].toObject());
    
    if (root.contains("inline_query"))
        inlineQuery = InlineQuery::fromObject(root["inline_query"].toObject());
    
    if (root.contains("chosen_inline_result"))
        chosenInlineResult = ChosenInlineResult::fromObject(root["chosen_inline_result"].toObject());
    
    if (root.contains("callback_query"))
        callbackQuery = CallbackQuery::fromObject(root["callback_query"].toObject());
    
    if (root.contains("shipping_query"))
        shippingQuery = ShippingQuery::fromObject(root["shipping_query"].toObject());
    
    if (root.contains("pre_checkout_query"))
        preCheckoutQuery = PreCheckoutQuery::fromObject(root["pre_checkout_query"].toObject());
}

Update::Update()
{}

Update Update::fromObject(QJsonObject obj)
{
    return Update(obj);
}

qint64 Update::getUpdateId() const
{
    return updateId;
}

void Update::setUpdateId(const qint64 &value)
{
    updateId = value;
}

Message Update::getMessage() const
{
    return message;
}

void Update::setMessage(const Message &value)
{
    message = value;
}

Message Update::getEditedMessage() const
{
    return editedMessage;
}

void Update::setEditedMessage(const Message &value)
{
    editedMessage = value;
}

Message Update::getChannelPost() const
{
    return channelPost;
}

void Update::setChannelPost(const Message &value)
{
    channelPost = value;
}

Message Update::getEditedChannelPost() const
{
    return editedChannelPost;
}

void Update::setEditedChannelPost(const Message &value)
{
    editedChannelPost = value;
}

InlineQuery Update::getInlineQuery() const
{
    return inlineQuery;
}

void Update::setInlineQuery(const InlineQuery &value)
{
    inlineQuery = value;
}

ChosenInlineResult Update::getChosenInlineResult() const
{
    return chosenInlineResult;
}

void Update::setChosenInlineResult(const ChosenInlineResult &value)
{
    chosenInlineResult = value;
}

CallbackQuery Update::getCallbackQuery() const
{
    return callbackQuery;
}

void Update::setCallbackQuery(const CallbackQuery &value)
{
    callbackQuery = value;
    root["callback_query"] = callbackQuery.toObject();
}

ShippingQuery Update::getShippingQuery() const
{
    return shippingQuery;
}

void Update::setShippingQuery(const ShippingQuery &value)
{
    shippingQuery = value;
    root["shipping_query"] = shippingQuery.toObject();
}

PreCheckoutQuery Update::getPreCheckoutQuery() const
{
    return preCheckoutQuery;
}

void Update::setPreCheckoutQuery(const PreCheckoutQuery &value)
{
    preCheckoutQuery = value;
    root["pre_checkout_query"] = preCheckoutQuery.toObject();
}
