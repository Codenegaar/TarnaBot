#include "include/passportelementerrortranslationfiles.h"
#include <QJsonArray>
using namespace Telegram;

PassportElementErrorTranslationFiles::PassportElementErrorTranslationFiles() :
    PassportElementError()
{}

PassportElementErrorTranslationFiles::PassportElementErrorTranslationFiles(
        QJsonObject jsonObject) :
    PassportElementError(jsonObject)
{}

PassportElementErrorTranslationFiles::PassportElementErrorTranslationFiles(
        QString message,
        QStringList fileHashes,
        PassportType type) :
    PassportElementError("translation_files", message, type)
{
    setFileHashes(fileHashes);
}

void PassportElementErrorTranslationFiles::setFileHashes(const QStringList &value)
{
    QJsonArray array;
    for (QString fileHash : value)
        array.append(fileHash);
    jsonObject["file_hashes"] = array;
}

QStringList PassportElementErrorTranslationFiles::getFileHashes() const
{
    QStringList fileHashes;
    for (QJsonValue fileHash : jsonObject["file_hashes"].toArray())
        fileHashes.append(fileHash.toString());
    return fileHashes;
}

bool PassportElementErrorTranslationFiles::hasFileHashes() const
{
    return jsonObject.contains("file_hashes");
}
