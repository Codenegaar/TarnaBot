#ifndef INPUTMEDIAVIDEO_H
#define INPUTMEDIAVIDEO_H

#include <QVariant>

#include "inputmedia.h"

namespace TarnaBot
{
    class InputMediaVideo : public InputMedia
    {
    public:
        InputMediaVideo();
        InputMediaVideo(QJsonObject obj);
        
        static InputMediaVideo fromObject(QJsonObject obj);
        
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
        bool getHasWidth() const;
        
        bool getHasHeight() const;
        
        bool getHasDuration() const;
        
    private:
        int width;
        int height;
        qint64 duration;
        bool supportsStreaming;
        
        //Flags
        bool hasWidth;
        bool hasHeight;
        bool hasDuration;
    };
}
#endif // INPUTMEDIAVIDEO_H
