#include "include/game.h"
using namespace Telegram;

Game::Game()
{
    
}

Game::Game(QJsonObject jsonObject) : TelegramObject(jsonObject)
{

}

Game::Game(QString title, QString description, QVector<PhotoSize> photo)
{
    setTitle(title);
    setDescription(description);
    setPhoto(photo);
}

//Getters/Setters
QString Game::getTitle() const
{
    return jsonObject["title"].toString();
}

void Game::setTitle(const QString &value)
{
    jsonObject["title"] = value;
}

QString Game::getDescription() const
{
    return jsonObject["description"].toString();
}

void Game::setDescription(const QString &value)
{
    jsonObject["description"] = value;
}

QString Game::getText() const
{
    return jsonObject["text"].toString();
}

void Game::setText(const QString &value)
{
    jsonObject["text"] = value;
}

Animation Game::getAnimation() const
{
    return Animation(jsonObject["animation"].toObject());
}

void Game::setAnimation(const Animation &value)
{
    jsonObject["animation"] = value.toJsonObject();
}

QVector<PhotoSize> Game::getPhoto() const
{
    QVector<PhotoSize> photo;
    QJsonArray jsonArray = jsonObject["photo"].toArray();

    foreach(QJsonValue value, jsonArray)
        photo.append(PhotoSize(value.toObject()));
    return photo;
}

void Game::setPhoto(const QVector<PhotoSize> &value)
{
    QJsonArray jsonArray;
    foreach(PhotoSize p, value)
        jsonArray.append(p.toJsonObject());
    jsonObject["photo"] = jsonArray;
}

QVector<MessageEntity> Game::getTextEntities() const
{
    QVector<MessageEntity> textEntities;
    QJsonArray jsonArray = jsonObject["text_entities"].toArray();

    foreach(QJsonValue value, jsonArray)
        textEntities.append(MessageEntity(value.toObject()));
    return textEntities;
}

void Game::setTextEntities(const QVector<MessageEntity> &value)
{
    QJsonArray jsonArray;
    foreach(MessageEntity m, value)
        jsonArray.append(m.toJsonObject());
    jsonObject["text_entities"] = jsonArray;
}

bool Game::hasTitle() const
{
    return jsonObject.contains("title");
}

bool Game::hasDescription() const
{
    return jsonObject.contains("description");
}

bool Game::hasText() const
{
    return jsonObject.contains("text");
}

bool Game::hasAnimation() const
{
    return jsonObject.contains("animation");
}

bool Game::hasPhoto() const
{
    return jsonObject.contains("photo");
}

bool Game::hasTextEntities() const
{
    return jsonObject.contains("text_entities");
}
