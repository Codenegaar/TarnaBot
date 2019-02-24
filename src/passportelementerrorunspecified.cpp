#include "include/passportelementerrorunspecified.h"
using namespace Telegram;

PassportElementErrorUnspecified::PassportElementErrorUnspecified() :
    PassportElementError()
{}

PassportElementErrorUnspecified::PassportElementErrorUnspecified(
        QJsonObject jsonObject) :
    PassportElementError(jsonObject)
{}

PassportElementErrorUnspecified::PassportElementErrorUnspecified(
        QString message,
        QString elementHash,
        PassportType type) :
    PassportElementError("unspecified", message, type)
{
    setElementHash(elementHash);
}

void PassportElementErrorUnspecified::setElementHash(const QString &value)
{
    jsonObject["element_hash"] = value;
}

QString PassportElementErrorUnspecified::getElementHash() const
{
    return jsonObject["element_hash"].toString();
}

bool PassportElementErrorUnspecified::hasElementHash() const
{
    return jsonObject.contains("element_hash");
}
