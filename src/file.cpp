#include "include/file.h"
using namespace Telegram;

File::File(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

File::File(QString fileId)
{
    setFileId(fileId);
}

File::File()
{
    
}

//Getters/setters
QString File::getFileId() const
{
    return jsonObject["file_id"].toString();
}

void File::setFileId(const QString &value)
{
    jsonObject["file_id"] = value;
}

QString File::getFilePath() const
{
    return jsonObject["file_path"].toString();
}

void File::setFilePath(const QString &value)
{
    jsonObject["file_path"] = value;
}

qint64 File::getFileSize() const
{
    return jsonObject["file_size"].toVariant().toLongLong();
}

void File::setFileSize(const qint64 &value)
{
    jsonObject["file_size"] = value;
}

bool File::hasFileId() const
{
    return jsonObject.contains("file_id");
}

bool File::hasFilePath() const
{
    return jsonObject.contains("file_path");
}

bool File::hasFileSize() const
{
    return jsonObject.contains("file_size");
}
