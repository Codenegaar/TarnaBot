#ifndef CHATPHOTO_H
#define CHATPHOTO_H

#include <QString>

#include "tarnaobject.h"

namespace Telegram
{
    class ChatPhoto : public TarnaObject
    {
    public:
        ChatPhoto(QJsonObject obj);
        ChatPhoto();
    
        //Getters/setters
        QString getSmallFileId() const;
        void setSmallFileId(const QString &value);
        
        QString getBigFileId() const;
        void setBigFileId(const QString &value);
        
        //Flag getters
        bool getHasSmallFileId() const;
        
        bool getHasBigFileId() const;
        
    private:
        QString smallFileId;
        QString bigFileId;
        
        //flags
        bool hasSmallFileId;
        bool hasBigFileId;
    };
}
#endif // CHATPHOTO_H
