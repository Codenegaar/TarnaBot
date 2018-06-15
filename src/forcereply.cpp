#include "include/forcereply.h"

using namespace Telegram;
ForceReply::ForceReply(QJsonObject obj) : ReplyMarkup::ReplyMarkup(obj)
{
    forceReply = root["force_reply"].toBool();
    
    if(root.contains("selective"))
        selective = root["selective"].toBool();
}

ForceReply::ForceReply()
{
    
}

//Getters/setters
bool ForceReply::getForceReply() const
{
    return forceReply;
}

void ForceReply::setForceReply(bool value)
{
    forceReply = value;
    root["force_reply"] = forceReply;    
}

bool ForceReply::getSelective() const
{
    return selective;
}

void ForceReply::setSelective(bool value)
{
    selective = value;
    root["selective"] = selective;    
}
