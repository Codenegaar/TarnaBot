#include "include/replymarkup.h"
using namespace Telegram;

ReplyMarkup::ReplyMarkup()
{
    
}

ReplyMarkup::ReplyMarkup(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{
    
}
