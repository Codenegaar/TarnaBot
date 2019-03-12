#include "include/passportelementerrorselfie.h"
using namespace Telegram;

PassportElementErrorSelfie::PassportElementErrorSelfie() :
    PassportElementError()
{}

PassportElementErrorSelfie::PassportElementErrorSelfie(QJsonObject jsonObject) :
    PassportElementError(jsonObject)
{}

PassportElementErrorSelfie::PassportElementErrorSelfie(
        QString message,
        QString fileHash,
        PassportType type) :
    PassportElementError("selfie", message, type)
{
    setFileHash(fileHash);
}

void PassportElementErrorSelfie::setFileHash(const QString &value)
{
    jsonObject["file_hash"] = value;
}

QString PassportElementErrorSelfie::getFileHash() const
{
    return jsonObject["file_hash"].toString();
}

bool PassportElementErrorSelfie::hasFileHash() const
{
    return jsonObject.contains("file_hash");
}
