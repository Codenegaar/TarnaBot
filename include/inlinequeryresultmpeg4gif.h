#ifndef INLINEQUERYRESULTMPEG4GIF_H
#define INLINEQUERYRESULTMPEG4GIF_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace TarnaBot
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
        bool getHasMpeg4Height() const;
        
        bool getHasMpeg4Width() const;
        
        bool getHasMpeg4Duration() const;
        
        bool getHasMpeg4Url() const;
        
        bool getHasThumbUrl() const;
        
        bool getHasTitle() const;
        
        bool getHasCaption() const;
        
        bool getHasParseMode() const;
        
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
        bool hasMpeg4Height;
        bool hasMpeg4Width;
        bool hasMpeg4Duration;
        bool hasMpeg4Url;
        bool hasThumbUrl;
        bool hasTitle;
        bool hasCaption;
        bool hasParseMode;
    };
}
#endif // INLINEQUERYRESULTMPEG4GIF_H
