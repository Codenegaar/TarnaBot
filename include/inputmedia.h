#ifndef INPUTMEDIA_H
#define INPUTMEDIA_H

#include <QString>

#include "tarnaobject.h"

class InputMedia : public TarnaObject
{
public:
    InputMedia();
    
protected:
    QString type;
};

#endif // INPUTMEDIA_H
