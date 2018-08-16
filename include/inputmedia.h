#ifndef INPUTMEDIA_H
#define INPUTMEDIA_H

#include <QString>

#include "TelegramObject"

namespace Telegram
{
    class InputMedia : public TelegramObject
    {
    public:
        InputMedia();
        InputMedia(QJsonObject jsonObject);
        
        //Getters/Setters
        QString getType() const;
        void setType(const QString &value);
        
        QString getMedia() const;
        void setMedia(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool hasType() const;
        
        bool hasMedia() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
    };
}
#endif // INPUTMEDIA_H
