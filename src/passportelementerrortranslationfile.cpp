#include "include/passportelementerrortranslationfile.h"
using namespace Telegram;

PassportElementErrorTranslationFile::PassportElementErrorTranslationFile() :
    PassportElementError()
{}

PassportElementErrorTranslationFile::PassportElementErrorTranslationFile(
        QJsonObject jsonObject) :
    PassportElementError(jsonObject)
{}

PassportElementErrorTranslationFile::PassportElementErrorTranslationFile(
        QString message,
        QString fileHash,
        PassportType type) :
    PassportElementError("translation_file", message, type)
{
    setFileHash(fileHash);
}

void PassportElementErrorTranslationFile::setFileHash(const QString &value)
{
    jsonObject["file_hash"] = value;
}

QString PassportElementErrorTranslationFile::getFileHash() const
{
    return jsonObject["file_hash"].toString();
}

bool PassportElementErrorTranslationFile::hasFileHash() const
{
    return jsonObject.contains("file_hash");
}
