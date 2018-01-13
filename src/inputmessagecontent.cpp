#include "include/inputmessagecontent.h"

template < class T >
InputMessageContent< T >::InputMessageContent()
{
    
}

template < class T >
InputMessageContent< T >::InputMessageContent(QJsonObject obj)
{
    if(obj.contains("message_text"))
        imc = InputTextMessageContent::fromObject(obj);
    
    else if(obj.contains("title"))
        imc = InputVenueMessageContent::fromObject(obj);
    
    else if(obj.contains("latitude"))
        imc = InputLocationMessageContent::fromObject(obj);
    
    else if(obj.contains("phone_number"))
        imc = InputContactMessageContent::fromObject(obj);
}

template < class T >
InputMessageContent< T > InputMessageContent< T >::fromObject(QJsonObject obj)
{
    return InputMessageContent< T >(obj);
}

template < class T >
QJsonObject InputMessageContent< T >::toObject()
{
    return imc.toObject();
}
