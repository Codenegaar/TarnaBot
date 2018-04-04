#include "include/inputmessagecontent.h"

using namespace Telegram;
InputMessageContent::InputMessageContent()
{
    
}

int InputMessageContent::determineType(QJsonObject obj)
{
    //return values: 1.Text, 2.Location, 3.Venue, 4.Contact
    if(obj.contains("message_text"))
        return 1;
    if(obj.contains("latitude"))
    {
        if(obj.contains("title"))
            return 3;
        return 2;
    }
    return 4;
}
