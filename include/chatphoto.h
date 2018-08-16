#ifndef CHATPHOTO_H
#define CHATPHOTO_H

#include <QString>

#include "TelegramObject"

namespace Telegram
{
    class ChatPhoto : public TelegramObject
    {
    public:
        ChatPhoto();
        ChatPhoto(QJsonObject jsonObject);
        ChatPhoto(QString smallFileId, QString bigFileId);
    
        //Getters/setters
        QString getSmallFileId() const;
        void setSmallFileId(const QString &value);
        
        QString getBigFileId() const;
        void setBigFileId(const QString &value);
        
        //Flag getters
        bool hasSmallFileId() const;
        bool hasBigFileId() const;
    };
}
#endif // CHATPHOTO_H
