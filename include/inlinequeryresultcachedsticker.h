#ifndef INLINEQUERYRESULTCACHEDSTICKER_H
#define INLINEQUERYRESULTCACHEDSTICKER_H

#include "inlinequeryresult.h"

class InlineQueryResultCachedSticker : public InlineQueryResult
{
public:
    InlineQueryResultCachedSticker();
    InlineQueryResultCachedSticker(QJsonObject obj);
    
    //Getters/Setters
    QString getStickerFileId() const;
    void setStickerFileId(const QString &value);
    
private:
    QString stickerFileId;
};

#endif // INLINEQUERYRESULTCACHEDSTICKER_H
