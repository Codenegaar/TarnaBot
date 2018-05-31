#ifndef INPUTMEDIAVIDEO_H
#define INPUTMEDIAVIDEO_H

#include <QVariant>

#include "inputmedia.h"

namespace Telegram
{
    class InputMediaVideo : public InputMedia
    {
    public:
        InputMediaVideo();
        InputMediaVideo(QJsonObject obj);
        
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
        
    private:
        int width;
        int height;
        qint64 duration;
        bool supportsStreaming;
        
        //Flags
        bool _hasWidth;
        bool _hasHeight;
        bool _hasDuration;
    };
}
#endif // INPUTMEDIAVIDEO_H
