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
