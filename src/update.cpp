#include "../include/update.h"
using namespace Telegram;

Update::Update()
{

}

Update::Update(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Update::Update(qint64 updateId)
{
    setUpdateId(updateId);
}

//Getters/Setters
qint64 Update::getUpdateId() const
{
    return jsonObject["update_id"].toVariant().toLongLong();
}

void Update::setUpdateId(const qint64 &value)
{
    jsonObject["update_id"] = value;
}

Message Update::getMessage() const
{
    return Message(jsonObject["message"].toObject());
}

void Update::setMessage(const Message &value)
{
    jsonObject["message"] = value.toJsonObject();
}

Message Update::getEditedMessage() const
{
    return Message(jsonObject["edited_message"].toObject());
}

void Update::setEditedMessage(const Message &value)
{
    jsonObject["edited_message"] = value.toJsonObject();
}

Message Update::getChannelPost() const
{
    return Message(jsonObject["channel_post"].toObject());
}

void Update::setChannelPost(const Message &value)
{
    jsonObject["channel_post"] = value.toJsonObject();
}

Message Update::getEditedChannelPost() const
{
    return Message(jsonObject["edited_channel_post"].toObject());
}

void Update::setEditedChannelPost(const Message &value)
{
    jsonObject["edited_channel_post"] = value.toJsonObject();
}

InlineQuery Update::getInlineQuery() const
{
    return InlineQuery(jsonObject["inline_query"].toObject());
}

void Update::setInlineQuery(const InlineQuery &value)
{
    jsonObject["inline_query"] = value.toJsonObject();
}

ChosenInlineResult Update::getChosenInlineResult() const
{
    return ChosenInlineResult(jsonObject["chosen_inline_result"].toObject());
}

void Update::setChosenInlineResult(const ChosenInlineResult &value)
{
    jsonObject["chosen_inline_result"] = value.toJsonObject();
}

CallbackQuery Update::getCallbackQuery() const
{
    return CallbackQuery(jsonObject["callback_query"].toObject());
}

void Update::setCallbackQuery(const CallbackQuery &value)
{
    jsonObject["callback_query"] = value.toJsonObject();
}

ShippingQuery Update::getShippingQuery() const
{
    return ShippingQuery(jsonObject["shipping_query"].toObject());
}

void Update::setShippingQuery(const ShippingQuery &value)
{
    jsonObject["shipping_query"] = value.toJsonObject();
}

PreCheckoutQuery Update::getPreCheckoutQuery() const
{
    return PreCheckoutQuery(jsonObject["pre_checkout_query"].toObject());
}

void Update::setPreCheckoutQuery(const PreCheckoutQuery &value)
{
    jsonObject["pre_checkout_query"] = value.toJsonObject();
}

Poll Update::getPoll() const
{
    return Poll(jsonObject["poll"].toObject());
}

void Update::setPoll(const Poll &value)
{
    jsonObject["poll"] = value.toJsonObject();
}

bool Update::hasUpdateId() const
{
    return jsonObject.contains("update_id");
}

bool Update::hasMessage() const
{
    return jsonObject.contains("message");
}

bool Update::hasEditedMessage() const
{
    return jsonObject.contains("edited_message");
}

bool Update::hasChannelPost() const
{
    return jsonObject.contains("channel_post");
}

bool Update::hasEditedChannelPost() const
{
    return jsonObject.contains("edited_channel_post");
}

bool Update::hasInlineQuery() const
{
    return jsonObject.contains("inline_query");
}

bool Update::hasChosenInlineResult() const
{
    return jsonObject.contains("chosen_inline_query");
}

bool Update::hasCallbackQuery() const
{
    return jsonObject.contains("callback_query");
}

bool Update::hasShippingQuery() const
{
    return jsonObject.contains("shipping_query");
}

bool Update::hasPreCheckoutQuery() const
{
    return jsonObject.contains("pre_checkout_query");
}

bool Update::hasPoll() const
{
    return jsonObject.contains("poll");
}
