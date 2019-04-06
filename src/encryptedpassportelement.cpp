#include "include/encryptedpassportelement.h"
using namespace Telegram;

EncryptedPassportElement::EncryptedPassportElement() :
    TelegramObject()
{}

EncryptedPassportElement::EncryptedPassportElement(QJsonObject jsonObject):
    TelegramObject(jsonObject)
{}

EncryptedPassportElement::EncryptedPassportElement(PassportType type,
                                                   QString hash)
{
    setType(type);
    setHash(hash);
}

PassportType EncryptedPassportElement::getType() const
{
    return static_cast<PassportType>(
                getTypeNames().key(
                    jsonObject["type"].toVariant().toByteArray()
                )
            );
}

void EncryptedPassportElement::setType(PassportType value)
{
    jsonObject["type"] = QString(getTypeNames().value(value));
}

QString EncryptedPassportElement::getData() const
{
    return jsonObject["data"].toString();
}

void EncryptedPassportElement::setDate(const QString &value)
{
    jsonObject["data"] = value;
}

QString EncryptedPassportElement::getPhoneNumber() const
{
    return jsonObject["phone_number"].toString();
}

void EncryptedPassportElement::setPhoneNumber(const QString &value)
{
    jsonObject["phone_number"] = value;
}

QString EncryptedPassportElement::getEmail() const
{
    return jsonObject["email"].toString();
}

void EncryptedPassportElement::setEmail(const QString &value)
{
    jsonObject["email"] = value;
}

QString EncryptedPassportElement::getHash() const
{
    return jsonObject["hash"].toString();
}

void EncryptedPassportElement::setHash(const QString &value)
{
    jsonObject["hash"] = value;
}

QVector<PassportFile> EncryptedPassportElement::getFiles() const
{
    QVector<PassportFile> files;
    for (QJsonValue value : jsonObject["files"].toArray())
    {
        files.append(PassportFile(value.toObject()));
    }
    return files;
}

void EncryptedPassportElement::setFiles(const QVector<PassportFile> &value)
{
    QJsonArray array;
    for (PassportFile file : value)
    {
        array.append(file.toJsonObject());
    }
    jsonObject["files"] = array;
}

PassportFile EncryptedPassportElement::getFrontSide() const
{
    return PassportFile(jsonObject["fron_side"].toObject());
}

void EncryptedPassportElement::setFrontSide(const PassportFile &value)
{
    jsonObject["front_side"] = value.toJsonObject();
}

PassportFile EncryptedPassportElement::getReverseSide() const
{
    return PassportFile(jsonObject["reverse_side"].toObject());
}

void EncryptedPassportElement::setReverseSide(const PassportFile &value)
{
    jsonObject["reverse_side"] = value.toJsonObject();
}

PassportFile EncryptedPassportElement::getSelfie() const
{
    return PassportFile(jsonObject["selfie"].toObject());
}

void EncryptedPassportElement::setSelfie(const PassportFile &value)
{
    jsonObject["selfie"] = value.toJsonObject();
}

QVector<PassportFile> EncryptedPassportElement::getTranslation() const
{
    QVector<PassportFile> translation;
    for (QJsonValue value : jsonObject["translation"].toArray())
    {
        translation.append(value.toObject());
    }
    return translation;
}

void EncryptedPassportElement::setTranslation(const QVector<PassportFile> &value)
{
    QJsonArray array;
    for (PassportFile file : value)
    {
        array.append(file.toJsonObject());
    }
    jsonObject["translation"] = array;
}

bool EncryptedPassportElement::hasType() const
{
    return jsonObject.contains("type");
}

bool EncryptedPassportElement::hasData() const
{
    return jsonObject.contains("data");
}

bool EncryptedPassportElement::hasPhoneNumber() const
{
    return jsonObject.contains("phone_number");
}

bool EncryptedPassportElement::hasEmail() const
{
    return jsonObject.contains("email");
}

bool EncryptedPassportElement::hasHash() const
{
    return jsonObject.contains("hash");
}

bool EncryptedPassportElement::hasFiles() const
{
    return jsonObject.contains("files");
}

bool EncryptedPassportElement::hasFrontSide() const
{
    return jsonObject.contains("front_side");
}

bool EncryptedPassportElement::hasReverseSide() const
{
    return jsonObject.contains("reverse_side");
}

bool EncryptedPassportElement::hasSelfie() const
{
    return jsonObject.contains("selfie");
}

bool EncryptedPassportElement::hasTranslation() const
{
    return jsonObject.contains("translation");
}
