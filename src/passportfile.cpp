#include "include/passportfile.h"
using namespace Telegram;

PassportFile::PassportFile()
{

}

Telegram::PassportFile::PassportFile(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

Telegram::PassportFile::PassportFile(QString fileId,
                                     qint64 fileSize,
                                     QDateTime fileDate)
{
    setFileId(fileId);
    setFileSize(fileSize);
    setFileDate(fileDate);
}

QString Telegram::PassportFile::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void Telegram::PassportFile::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

qint64 Telegram::PassportFile::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void Telegram::PassportFile::setFileSize(qint64 value)
{
    jsonObject["file_size"] = value;
}

QDateTime Telegram::PassportFile::getFileDate() const
{
    return QDateTime::fromSecsSinceEpoch(
                jsonObject["file_date"].toVariant().toLongLong());
}

void Telegram::PassportFile::setFileDate(const QDateTime &value)
{
    jsonObject["file_date"] = value.toSecsSinceEpoch();
}

bool Telegram::PassportFile::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool Telegram::PassportFile::hasFileSize() const
{
    return jsonObject.contains("file_size");
}

bool Telegram::PassportFile::hasFileDate() const
{
    return jsonObject.contains("file_date");
}
