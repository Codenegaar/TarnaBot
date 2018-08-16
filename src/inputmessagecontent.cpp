#include "include/inputmessagecontent.h"

using namespace Telegram;
InputMessageContent::InputMessageContent()
{
    
}

InputMessageContent::InputMessageContent(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{
    
}

int InputMessageContent::determineType(QJsonObject jsonObject)
{
    //return values: 1.Text, 2.Location, 3.Venue, 4.Contact
    if(jsonObject.contains("message_text"))
        return 1;
    if(jsonObject.contains("latitude"))
    {
        if(jsonObject.contains("title"))
            return 3;
        return 2;
    }
    return 4;
}
