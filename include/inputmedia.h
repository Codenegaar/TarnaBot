#ifndef INPUTMEDIA_H
#define INPUTMEDIA_H

#include <QString>

#include "tarnaobject.h"

class InputMedia : public TarnaObject
{
public:
    InputMedia();
    
    //Getters/Setters
    QString getType() const;
    void setType(const QString &value);
    
    QString getMedia() const;
    void setMedia(const QString &value);
    
    QString getCaption() const;
    void setCaption(const QString &value);
    
    QString getParseMode() const;
    void setParseMode(const QString &value);
    
protected:
    QString type;
    QString media;
    QString caption;
    QString parseMode;
};

#endif // INPUTMEDIA_H
