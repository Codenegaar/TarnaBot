#ifndef INPUTMESSAGECONTENT_H
#define INPUTMESSAGECONTENT_H

#include "tarnaobject.h"


class InputMessageContent : public TarnaObject
{
public:
    InputMessageContent();
    
    static int determineType(QJsonObject obj);
};

#endif // INPUTMESSAGECONTENT_H
