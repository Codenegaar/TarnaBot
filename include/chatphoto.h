#ifndef CHATPHOTO_H
#define CHATPHOTO_H

#include <QString>

#include "tarnaobject.h"

class ChatPhoto : public TarnaObject
{
public:
    ChatPhoto(QJsonObject obj);
    ChatPhoto();
    
    static ChatPhoto fromObject(QJsonObject obj);

    //Getters/setters
    QString getSmallFileId() const;
    void setSmallFileId(const QString &value);
    
    QString getBigFileId() const;
    void setBigFileId(const QString &value);
    
private:
    QString smallFileId;
    QString bigFileId;
};

#endif // CHATPHOTO_H
