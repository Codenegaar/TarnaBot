#ifndef INLINEQUERYRESULTCACHEDSTICKER_H
#define INLINEQUERYRESULTCACHEDSTICKER_H

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultCachedSticker : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedSticker();
        InlineQueryResultCachedSticker(QJsonObject jsonObject);
        InlineQueryResultCachedSticker(QString id, QString stickerFileId);
        
        //Getters/Setters
        QString getStickerFileId() const;
        void setStickerFileId(const QString &value);
        
        //Flag getters
        bool hasStickerFileId() const;
    };
}
#endif // INLINEQUERYRESULTCACHEDSTICKER_H
