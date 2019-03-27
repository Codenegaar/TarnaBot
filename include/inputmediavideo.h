#ifndef INPUTMEDIAVIDEO_H
#define INPUTMEDIAVIDEO_H

#include <QVariant>

#include "InputMedia"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InputMediaVideo : public InputMedia
    {
    public:
        InputMediaVideo();
        InputMediaVideo(QJsonObject jsonObject);
        
        //Getters/Setters
        int getWidth() const;
        void setWidth(int value);
        
        int getHeight() const;
        void setHeight(int value);
        
        qint64 getDuration() const;
        void setDuration(const qint64 &value);
        
        bool getSupportsStreaming() const;
        void setSupportsStreaming(bool value);
        
        //Flag getters
        bool hasWidth() const;
        
        bool hasHeight() const;
        
        bool hasDuration() const;
    };
}
#endif // INPUTMEDIAVIDEO_H
