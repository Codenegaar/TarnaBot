#include "include/passportelementerrorfile.h"
using namespace Telegram;

PassportElementErrorFile::PassportElementErrorFile() :
    PassportElementError()
{}

PassportElementErrorFile::PassportElementErrorFile(QJsonObject jsonObject) :
    PassportElementError(jsonObject)
{}

PassportElementErrorFile::PassportElementErrorFile(
        QString message,
        QString fileHash,
        PassportType type) :
    PassportElementError("file", message, type)
{
    setFileHash(fileHash);
}

void PassportElementErrorFile::setFileHash(const QString &value)
{
    jsonObject["file_hash"] = value;
}

QString PassportElementErrorFile::getFileHash() const
{
    return jsonObject["file_hash"].toString();
}

bool PassportElementErrorFile::hasFileHash() const
{
    return jsonObject.contains("file_hash");
}
