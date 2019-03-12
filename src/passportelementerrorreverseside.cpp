#include "include/passportelementerrorreverseside.h"
using namespace Telegram;

PassportElementErrorReverseSide::PassportElementErrorReverseSide() :
    PassportElementError()
{}

PassportElementErrorReverseSide::PassportElementErrorReverseSide(QJsonObject jsonObject) :
    PassportElementError(jsonObject)
{}

PassportElementErrorReverseSide::PassportElementErrorReverseSide(QString message,
                                                                 QString fileHash,
                                                                 PassportType type) :
    PassportElementError("reverse_side", message, type)
{
    setFileHash(fileHash);
}

void PassportElementErrorReverseSide::setFileHash(const QString &value)
{
    jsonObject["file_hash"] = value;
}

QString PassportElementErrorReverseSide::getFileHash() const
{
    return jsonObject["file_hash"].toString();
}

bool PassportElementErrorReverseSide::hasFileHash() const
{
    return jsonObject.contains("file_hash");
}
