#include "include/forcereply.h"
using namespace Telegram;

ForceReply::ForceReply(QJsonObject jsonObject) : ReplyMarkup::ReplyMarkup(jsonObject)
{

}

ForceReply::ForceReply()
{
    setForceReply(true);
}

//Getters/setters
bool ForceReply::getForceReply() const
{
    return jsonObject["force_reply"].toBool();
}

void ForceReply::setForceReply(bool value)
{
    jsonObject["force_reply"] = value;
}

bool ForceReply::getSelective() const
{
    return jsonObject["selective"].toBool();
}

void ForceReply::setSelective(bool value)
{
    jsonObject["selective"] = value;
}
