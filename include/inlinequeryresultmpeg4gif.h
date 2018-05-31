#ifndef INLINEQUERYRESULTMPEG4GIF_H
#define INLINEQUERYRESULTMPEG4GIF_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultMpeg4Gif : public InlineQueryResult
    {
    public:
        InlineQueryResultMpeg4Gif();
        InlineQueryResultMpeg4Gif(QJsonObject obj);
        
        //Getters/Setters
        int getMpeg4Height() const;
        void setMpeg4Height(int value);
        
        int getMpeg4Width() const;
        void setMpeg4Width(int value);
        
        qint64 getMpeg4Duration() const;
        void setMpeg4Duration(const qint64 &value);
        
        QString getMpeg4Url() const;
        void setMpeg4Url(const QString &value);
        
        QString getThumbUrl() const;
        void setThumbUrl(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool hasMpeg4Height() const;
        
        bool hasMpeg4Width() const;
        
        bool hasMpeg4Duration() const;
        
        bool hasMpeg4Url() const;
        
        bool hasThumbUrl() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasParseMode() const;
        
    private:
        int mpeg4Height;
        int mpeg4Width;
        qint64 mpeg4Duration;
        
        QString mpeg4Url;
        QString thumbUrl;
        QString title;
        QString caption;
        QString parseMode;
        
        //Flags
        bool _hasMpeg4Height;
        bool _hasMpeg4Width;
        bool _hasMpeg4Duration;
        bool _hasMpeg4Url;
        bool _hasThumbUrl;
        bool _hasTitle;
        bool _hasCaption;
        bool _hasParseMode;
    };
}
#endif // INLINEQUERYRESULTMPEG4GIF_H
