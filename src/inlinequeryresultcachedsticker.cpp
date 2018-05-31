#include "include/inlinequeryresultcachedsticker.h"

using namespace Telegram;
InlineQueryResultCachedSticker::InlineQueryResultCachedSticker()
{
    
}

InlineQueryResultCachedSticker::InlineQueryResultCachedSticker(QJsonObject obj) : InlineQueryResult::InlineQueryResult(obj)
{
    stickerFileId = root["sticker_file_id"].toString();
    _hasStickerFileId = true;
}

QString InlineQueryResultCachedSticker::getStickerFileId() const
{
    return stickerFileId;
}

void InlineQueryResultCachedSticker::setStickerFileId(const QString &value)
{
    stickerFileId = value;
    root["sticker_file_id"] = stickerFileId;
    _hasStickerFileId = true;
}

bool InlineQueryResultCachedSticker::hasStickerFileId() const
{
    return _hasStickerFileId;
}
