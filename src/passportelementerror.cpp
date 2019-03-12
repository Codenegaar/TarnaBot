#include "include/passportelementerror.h"
#include <QVariant>
using namespace Telegram;

PassportElementError::PassportElementError() :
    TelegramObject()
{

}

PassportElementError::PassportElementError(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

PassportElementError::PassportElementError(QString source, QString message, PassportType type) :
    TelegramObject()
{
    setSource(source);
    setMessage(message);
    setType(type);
}

void PassportElementError::setSource(const QString &value)
{
    jsonObject["source"] = value;
}

QString PassportElementError::getSource() const
{
    return jsonObject["source"].toString();
}

void PassportElementError::setType(const PassportType value)
{
    jsonObject["type"] = QString(
                getTypeNames().value(static_cast<int>(value))
                );
}

PassportType PassportElementError::getType() const
{
    return static_cast<PassportType> (
                getTypeNames().key(
                    jsonObject["type"].toVariant().toByteArray()
                )
            );
}

void PassportElementError::setMessage(const QString &value)
{
    jsonObject["message"] = value;
}

QString PassportElementError::getMessage() const
{
    return jsonObject["message"].toString();
}

bool PassportElementError::hasType() const
{
    return jsonObject.contains("type");
}

bool PassportElementError::hasSource() const
{
    return jsonObject.contains("source");
}

bool PassportElementError::hasMessage() const
{
    return jsonObject.contains("message");
}

