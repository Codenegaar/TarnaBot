#ifndef INPUTMESSAGECONTENT_H
#define INPUTMESSAGECONTENT_H

#include "tarnaobject.h"

class InputMessageContent : public TarnaObject
{
public:
    InputMessageContent();
    enum ContentType 
    {
        text,
        contact,
        venue,
        location
    }contentType;
};

#endif // INPUTMESSAGECONTENT_H
