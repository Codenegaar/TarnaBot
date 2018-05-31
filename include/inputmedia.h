#ifndef INPUTMEDIA_H
#define INPUTMEDIA_H

#include <QString>

#include "tarnaobject.h"

namespace Telegram
{
    class InputMedia : public TarnaObject
    {
    public:
        InputMedia();
        InputMedia(QJsonObject obj);
        
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
        
    protected:
        QString type;
        QString media;
        QString caption;
        QString parseMode;
        
        //Flags
        bool _hasType;
        bool _hasMedia;
        bool _hasCaption;
        bool _hasParseMode;
    };
}
#endif // INPUTMEDIA_H
