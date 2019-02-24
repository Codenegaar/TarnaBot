#include "include/passportelementerrorfiles.h"
#include <QJsonArray>
using namespace Telegram;

PassportElementErrorFiles::PassportElementErrorFiles() :
    PassportElementError()
{}

PassportElementErrorFiles::PassportElementErrorFiles(QJsonObject jsonObject) :
    PassportElementError(jsonObject)
{}

PassportElementErrorFiles::PassportElementErrorFiles(
        QString message,
        QStringList fileHashes,
        PassportType type) :
    PassportElementError("files", message, type)
{
    setFileHashes(fileHashes);
}

void PassportElementErrorFiles::setFileHashes(const QStringList &value)
{
    QJsonArray array;
    for (QString fileHash : value)
    {
        array.append(fileHash);
    }
    jsonObject["file_hashes"] = array;
}

QStringList PassportElementErrorFiles::getFileHashes() const
{
    QStringList fileHashes;
    for (QJsonValue value : jsonObject["file_hashes"].toArray())
    {
        fileHashes.append(value.toString());
    }
    return fileHashes;
}

bool PassportElementErrorFiles::hasFileHashes() const
{
    return jsonObject.contains("file_hashes");
}

