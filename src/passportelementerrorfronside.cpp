#include "include/passportelementerrorfronside.h"
using namespace Telegram;

PassportElementErrorFronSide::PassportElementErrorFronSide()
    : PassportElementError()
{}

PassportElementErrorFronSide::PassportElementErrorFronSide(QJsonObject jsonObject)
    : PassportElementError(jsonObject)
{}

PassportElementErrorFronSide::PassportElementErrorFronSide(QString message, QString fileHash,
                                                           PassportType type)
    : PassportElementError("front_side", message, type)
{
    setFileHash(fileHash);
}

void PassportElementErrorFronSide::setFileHash(const QString &value)
{
    jsonObject["file_hash"] = value;
}

QString PassportElementErrorFronSide::getFileHash() const
{
    return jsonObject["file_hash"].toString();
}

bool PassportElementErrorFronSide::hasFileHash() const
{
    return jsonObject.contains("file_hash");
}
