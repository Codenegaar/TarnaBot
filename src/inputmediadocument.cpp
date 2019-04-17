#include "include/inputmediadocument.h"
using namespace Telegram;

InputMediaDocument::InputMediaDocument()
    : InputMedia()
{

}

InputMediaDocument::InputMediaDocument(QJsonObject jsonObject)
    : InputMedia(jsonObject)
{

}

InputMediaDocument::InputMediaDocument(
        const QString &type,
        const QString &media)
    : InputMedia()
{
    setType(type);
    setMedia(media);
}
