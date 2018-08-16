#ifndef INLINEQUERYRESULTMPEG4GIF_H
#define INLINEQUERYRESULTMPEG4GIF_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class InlineQueryResultMpeg4Gif : public InlineQueryResult
    {
    public:
        InlineQueryResultMpeg4Gif();
        InlineQueryResultMpeg4Gif(QJsonObject jsonObject);
        InlineQueryResultMpeg4Gif(QString id, QString mpeg4Url, QString thumbUrl);
        
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
    };
}
#endif // INLINEQUERYRESULTMPEG4GIF_H
