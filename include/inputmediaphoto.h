#ifndef INPUTMEDIAPHOTO_H
#define INPUTMEDIAPHOTO_H

#include "inputmedia.h"

class InputMediaPhoto : public InputMedia
{
public:
    InputMediaPhoto();
    InputMediaPhoto(QJsonObject obj);
    
    static InputMediaPhoto fromObject(QJsonObject obj);
    
    //Getters/Setters
    QString getMedia() const;
    void setMedia(const QString &value);
    
    QString getCaption() const;
    void setCaption(const QString &value);
    
    //Public flags
    bool hasMedia = false;
    bool hasCaption = false;
    
private:
    QString media;
    QString caption;
};

#endif // INPUTMEDIAPHOTO_H
