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
        bool getHasStickerFileId() const;
        
    private:
        QString stickerFileId;
        
        //Flags
        bool hasStickerFileId;
    };
}
#endif // INLINEQUERYRESULTCACHEDSTICKER_H
