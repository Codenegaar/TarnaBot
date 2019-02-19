#include "include/passportelementerrordatafield.h"
using namespace Telegram;
PassportElementErrorDataField::PassportElementErrorDataField() :
    PassportElementError()
{}

PassportElementErrorDataField::PassportElementErrorDataField
(QJsonObject jsonObject) :
    PassportElementError(jsonObject)
{}

PassportElementErrorDataField::PassportElementErrorDataField(QString source,
                                                             QString fieldName,
                                                             QString dataHash,
                                                             QString message,
                                                             PassportType type)
    : PassportElementError(source, message, type)
{
    setFieldName(fieldName);
    setDataHash(dataHash);
}

void PassportElementErrorDataField::setFieldName(const QString &value)
{
    jsonObject["field_name"] = value;
}

QString PassportElementErrorDataField::getFieldName() const
{
    return jsonObject["field_name"].toString();
}

void PassportElementErrorDataField::setDataHash(const QString &value)
{
    jsonObject["data_hash"] = value;
}

QString PassportElementErrorDataField::getDataHash() const
{
    return jsonObject["data_hash"].toString();
}

bool PassportElementErrorDataField::hasFieldName() const
{
    return jsonObject.contains("field_name");
}

bool PassportElementErrorDataField::hasDataHash() const
{
    return jsonObject.contains("data_hash");
}

