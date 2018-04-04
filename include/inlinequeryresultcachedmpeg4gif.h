#ifndef INLINEQUERYRESULTCACHEDMPEG4GIF_H
#define INLINEQUERYRESULTCACHEDMPEG4GIF_H

#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultCachedMpeg4Gif : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedMpeg4Gif();
        InlineQueryResultCachedMpeg4Gif(QJsonObject obj);
        
        //Getters/Setters
        QString getMpeg4FileId() const;
        void setMpeg4FileId(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getParseMode() const;
        void setParseMode(const QString &value);
        
        //Flag getters
        bool getHasMpeg4FileId() const;
        
        bool getHasTitle() const;
        
        bool getHasCaption() const;
        
        bool getHasParseMode() const;
        
    private:
        QString mpeg4FileId;
        QString title;
        QString caption;
        QString parseMode;
        
        //Flags
        bool hasMpeg4FileId;
        bool hasTitle;
        bool hasCaption;
        bool hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDMPEG4GIF_H
