#ifndef INPUTMESSAGECONTENT_H
#define INPUTMESSAGECONTENT_H

#include <QJsonObject>

#include "inputcontactmessagecontent.h"
#include "inputlocationmessagecontent.h"
#include "inputtextmessagecontent.h"
#include "inputvenuemessagecontent.h"

template < class T>
class InputMessageContent
{
public:
    InputMessageContent();
    InputMessageContent(QJsonObject obj);
    static InputMessageContent< T > fromObject(QJsonObject obj);
    QJsonObject toObject();
    
private:
    
    T imc;
};
#include "../src/inputmessagecontent.cpp"
#endif // INPUTMESSAGECONTENT_H
