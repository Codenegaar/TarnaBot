#include "../include/update.h"

using namespace Telegram;
Update::Update(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    updateId = root["update_id"].toVariant().toLongLong();
    _hasUpdateId = true;
    
    //Optional types
    if (root.contains("message"))
    {
        message = Message(root["message"].toObject());
        _hasMessage = true;
    }
    
    if (root.contains("edited_message"))
    {
        editedMessage = Message(root["edited_message"].toObject());
        _hasEditedMessage = true;
    }
    
    if (root.contains("channel_post"))
    {
        channelPost = Message(root["channel_post"].toObject());
        _hasChannelPost = true;
    }
    
    if (root.contains("edited_channel_post"))
    {
        editedChannelPost = Message(root["edited_channel_post"].toObject());
        _hasEditedChannelPost = true;
    }
    
    if (root.contains("inline_query"))
    {
        inlineQuery = InlineQuery(root["inline_query"].toObject());
        _hasInlineQuery = true;
    }
    
    if (root.contains("chosen_inline_result"))
    {
        chosenInlineResult = ChosenInlineResult(root["chosen_inline_result"].toObject());
        _hasChosenInlineResult = true;
    }
    
    if (root.contains("callback_query"))
    {
        callbackQuery = CallbackQuery(root["callback_query"].toObject());
        _hasCallbackQuery = true;
    }
    
    if (root.contains("shipping_query"))
    {
        shippingQuery = ShippingQuery(root["shipping_query"].toObject());
        _hasShippingQuery = true;
    }
    
    if (root.contains("pre_checkout_query"))
    {
        preCheckoutQuery = PreCheckoutQuery(root["pre_checkout_query"].toObject());
        _hasPrecheckoutQuery = true;
    }
}

Update::Update()
{}

//Getters/Setters
qint64 Update::getUpdateId() const
{
    return updateId;
}

void Update::setUpdateId(const qint64 &value)
{
    updateId = value;
    root["update_id"] = updateId;
    _hasUpdateId = true;
}

Message Update::getMessage() const
{
    return message;
}

void Update::setMessage(const Message &value)
{
    message = value;
    root["message"] = message.toObject();
    _hasMessage = true;
}

Message Update::getEditedMessage() const
{
    return editedMessage;
}

void Update::setEditedMessage(const Message &value)
{
    editedMessage = value;
    root["edited_message"] = editedMessage.toObject();
    _hasEditedMessage = true;
}

Message Update::getChannelPost() const
{
    return channelPost;
}

void Update::setChannelPost(const Message &value)
{
    channelPost = value;
    root["channel_post"] = channelPost.toObject();
    _hasChannelPost = true;
}

Message Update::getEditedChannelPost() const
{
    return editedChannelPost;
}

void Update::setEditedChannelPost(const Message &value)
{
    editedChannelPost = value;
    root["edited_channel_post"] = editedChannelPost.toObject();
    _hasEditedChannelPost = true;
}

InlineQuery Update::getInlineQuery() const
{
    return inlineQuery;
}

void Update::setInlineQuery(const InlineQuery &value)
{
    inlineQuery = value;
    root["inline_query"] = inlineQuery.toObject();
    _hasInlineQuery = true;
}

ChosenInlineResult Update::getChosenInlineResult() const
{
    return chosenInlineResult;
}

void Update::setChosenInlineResult(const ChosenInlineResult &value)
{
    chosenInlineResult = value;
    root["chosen_inline_query"] = chosenInlineResult.toObject();
    _hasChosenInlineResult = true;
}

CallbackQuery Update::getCallbackQuery() const
{
    return callbackQuery;
}

void Update::setCallbackQuery(const CallbackQuery &value)
{
    callbackQuery = value;
    root["callback_query"] = callbackQuery.toObject();
    _hasCallbackQuery = true;
}

ShippingQuery Update::getShippingQuery() const
{
    return shippingQuery;
}

void Update::setShippingQuery(const ShippingQuery &value)
{
    shippingQuery = value;
    root["shipping_query"] = shippingQuery.toObject();
    _hasShippingQuery = true;
}

PreCheckoutQuery Update::getPreCheckoutQuery() const
{
    return preCheckoutQuery;
}

void Update::setPreCheckoutQuery(const PreCheckoutQuery &value)
{
    preCheckoutQuery = value;
    root["pre_checkout_query"] = preCheckoutQuery.toObject();
    _hasPrecheckoutQuery = true;
}

bool Update::hasUpdateId() const
{
    return _hasUpdateId;
}

bool Update::hasMessage() const
{
    return _hasMessage;
}

bool Update::hasEditedMessage() const
{
    return _hasEditedMessage;
}

bool Update::hasChannelPost() const
{
    return _hasChannelPost;
}

bool Update::hasEditedChannelPost() const
{
    return _hasEditedChannelPost;
}

bool Update::hasInlineQuery() const
{
    return _hasInlineQuery;
}

bool Update::hasChosenInlineResult() const
{
    return _hasChosenInlineResult;
}

bool Update::hasCallbackQuery() const
{
    return _hasCallbackQuery;
}

bool Update::hasShippingQuery() const
{
    return _hasShippingQuery;
}

bool Update::hasPrecheckoutQuery() const
{
    return _hasPrecheckoutQuery;
}
