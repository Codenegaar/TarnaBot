#ifndef INLINEQUERYRESULTCACHEDSTICKER_H
#define INLINEQUERYRESULTCACHEDSTICKER_H

#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultCachedSticker : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedSticker();
        InlineQueryResultCachedSticker(QJsonObject obj);
        
        //Getters/Setters
        QString getStickerFileId() const;
        void setStickerFileId(const QString &value);
        
        //Flag getters
        bool hasStickerFileId() const;
        
    private:
        QString stickerFileId;
        
        //Flags
        bool _hasStickerFileId;
    };
}
#endif // INLINEQUERYRESULTCACHEDSTICKER_H
