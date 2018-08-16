#include "include/inlinequeryresultcachedsticker.h"
using namespace Telegram;

InlineQueryResultCachedSticker::InlineQueryResultCachedSticker()
{
    
}

InlineQueryResultCachedSticker::InlineQueryResultCachedSticker(QJsonObject jsonObject) :
    InlineQueryResult(jsonObject)
{

}

InlineQueryResultCachedSticker::InlineQueryResultCachedSticker(QString id, QString stickerFileId) :
    InlineQueryResult("sticker", id)
{
    setStickerFileId(stickerFileId);
}

QString InlineQueryResultCachedSticker::getStickerFileId() const
{
    return jsonObject["sticker_file_id"].toString();
}

void InlineQueryResultCachedSticker::setStickerFileId(const QString &value)
{
    jsonObject["sticker_file_id"] = value;
}

bool InlineQueryResultCachedSticker::hasStickerFileId() const
{
    return jsonObject.contains("sticker_file_id");
}
