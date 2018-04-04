#include "../include/update.h"

using namespace Telegram;
Update::Update(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    updateId = root["update_id"].toVariant().toLongLong();
    hasUpdateId = true;
    
    //Optional types
    if (root.contains("message"))
    {
        message = Message::fromObject(root["message"].toObject());
        hasMessage = true;
    }
    
    if (root.contains("edited_message"))
    {
        editedMessage = Message::fromObject(root["edited_message"].toObject());
        hasEditedMessage = true;
    }
    
    if (root.contains("channel_post"))
    {
        channelPost = Message::fromObject(root["channel_post"].toObject());
        hasChannelPost = true;
    }
    
    if (root.contains("edited_channel_post"))
    {
        editedChannelPost = Message::fromObject(root["edited_channel_post"].toObject());
        hasEditedChannelPost = true;
    }
    
    if (root.contains("inline_query"))
    {
        inlineQuery = InlineQuery::fromObject(root["inline_query"].toObject());
        hasInlineQuery = true;
    }
    
    if (root.contains("chosen_inline_result"))
    {
        chosenInlineResult = ChosenInlineResult::fromObject(root["chosen_inline_result"].toObject());
        hasChosenInlineResult = true;
    }
    
    if (root.contains("callback_query"))
    {
        callbackQuery = CallbackQuery::fromObject(root["callback_query"].toObject());
        hasCallbackQuery = true;
    }
    
    if (root.contains("shipping_query"))
    {
        shippingQuery = ShippingQuery::fromObject(root["shipping_query"].toObject());
        hasShippingQuery = true;
    }
    
    if (root.contains("pre_checkout_query"))
    {
        preCheckoutQuery = PreCheckoutQuery::fromObject(root["pre_checkout_query"].toObject());
        hasPrecheckoutQuery = true;
    }
}

Update::Update()
{}

Update Update::fromObject(QJsonObject obj)
{
    return Update(obj);
}

//Getters/Setters
qint64 Update::getUpdateId() const
{
    return updateId;
}

void Update::setUpdateId(const qint64 &value)
{
    updateId = value;
    root["update_id"] = updateId;
    hasUpdateId = true;
}

Message Update::getMessage() const
{
    return message;
}

void Update::setMessage(const Message &value)
{
    message = value;
    root["message"] = message.toObject();
    hasMessage = true;
}

Message Update::getEditedMessage() const
{
    return editedMessage;
}

void Update::setEditedMessage(const Message &value)
{
    editedMessage = value;
    root["edited_message"] = editedMessage.toObject();
    hasEditedMessage = true;
}

Message Update::getChannelPost() const
{
    return channelPost;
}

void Update::setChannelPost(const Message &value)
{
    channelPost = value;
    root["channel_post"] = channelPost.toObject();
    hasChannelPost = true;
}

Message Update::getEditedChannelPost() const
{
    return editedChannelPost;
}

void Update::setEditedChannelPost(const Message &value)
{
    editedChannelPost = value;
    root["edited_channel_post"] = editedChannelPost.toObject();
    hasEditedChannelPost = true;
}

InlineQuery Update::getInlineQuery() const
{
    return inlineQuery;
}

void Update::setInlineQuery(const InlineQuery &value)
{
    inlineQuery = value;
    root["inline_query"] = inlineQuery.toObject();
    hasInlineQuery = true;
}

ChosenInlineResult Update::getChosenInlineResult() const
{
    return chosenInlineResult;
}

void Update::setChosenInlineResult(const ChosenInlineResult &value)
{
    chosenInlineResult = value;
    root["chosen_inline_query"] = chosenInlineResult.toObject();
    hasChosenInlineResult = true;
}

CallbackQuery Update::getCallbackQuery() const
{
    return callbackQuery;
}

void Update::setCallbackQuery(const CallbackQuery &value)
{
    callbackQuery = value;
    root["callback_query"] = callbackQuery.toObject();
    hasCallbackQuery = true;
}

ShippingQuery Update::getShippingQuery() const
{
    return shippingQuery;
}

void Update::setShippingQuery(const ShippingQuery &value)
{
    shippingQuery = value;
    root["shipping_query"] = shippingQuery.toObject();
    hasShippingQuery = true;
}

PreCheckoutQuery Update::getPreCheckoutQuery() const
{
    return preCheckoutQuery;
}

void Update::setPreCheckoutQuery(const PreCheckoutQuery &value)
{
    preCheckoutQuery = value;
    root["pre_checkout_query"] = preCheckoutQuery.toObject();
    hasPrecheckoutQuery = true;
}

bool Update::getHasUpdateId() const
{
    return hasUpdateId;
}

bool Update::getHasMessage() const
{
    return hasMessage;
}

bool Update::getHasEditedMessage() const
{
    return hasEditedMessage;
}

bool Update::getHasChannelPost() const
{
    return hasChannelPost;
}

bool Update::getHasEditedChannelPost() const
{
    return hasEditedChannelPost;
}

bool Update::getHasInlineQuery() const
{
    return hasInlineQuery;
}

bool Update::getHasChosenInlineResult() const
{
    return hasChosenInlineResult;
}

bool Update::getHasCallbackQuery() const
{
    return hasCallbackQuery;
}

bool Update::getHasShippingQuery() const
{
    return hasShippingQuery;
}

bool Update::getHasPrecheckoutQuery() const
{
    return hasPrecheckoutQuery;
}
