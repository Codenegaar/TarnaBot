#include "include/game.h"

using namespace Telegram;
Game::Game()
{
    
}

Game::Game(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    QJsonArray temp1;
    int l, i;
    
    title = root["title"].toString();
    _hasTitle = true;
    description = root["description"].toString();
    _hasDescription = true;
    
    //initialize "photo"
    foreach(QJsonValue val, root["photo"].toArray())
    {
        photo.append(PhotoSize(val.toObject()));
    }
    _hasPhoto = true;
    
    //Optional Types
    if(root.contains("text"))
    {
        text = root["text"].toString();
        _hasText = true;
    }
    
    if(root.contains("text_entities"))
    {
        temp1 = root["text_entities"].toArray();
        l = temp1.size();
        
        for(i = 0; i < l; i++)
            textEntities[i] = MessageEntity(temp1.at(i).toObject());
        _hasTextEntities = true;
    }
    
    if(root.contains("animation"))
    {
        animation = Animation(root["animation"].toObject());
        _hasAnimation = true;
    }
}

//Getters/Setters
QString Game::getTitle() const
{
    return title;
}

void Game::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
    _hasTitle = true;
}

QString Game::getDescription() const
{
    return description;
}

void Game::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    _hasDescription = true;
}

QString Game::getText() const
{
    return text;
}

void Game::setText(const QString &value)
{
    text = value;
    root["text"] = text;
    _hasText = true;
}

Animation Game::getAnimation() const
{
    return animation;
}

void Game::setAnimation(const Animation &value)
{
    animation = value;
    root["animation"] = animation.toObject();
    _hasAnimation = true;
}

QVector<PhotoSize> Game::getPhoto() const
{
    return photo;
}

void Game::setPhoto(const QVector<PhotoSize> &value)
{
    QJsonArray temp;
    int l, i;
    photo = value;
    
    l = photo.size();
    for(i = 0; i < l; i++)
        temp.insert(i, photo[i].toObject());
    root["photo"] = temp;
    _hasPhoto = true;
}

QVector<MessageEntity> Game::getTextEntities() const
{
    return textEntities;
}

void Game::setTextEntities(const QVector<MessageEntity> &value)
{
    QJsonArray temp;
    int l, i;
    textEntities = value;
    
    l = textEntities.size();
    for(i = 0; i < l; i++)
        temp.insert(i, textEntities[i].toObject());
    root["text_entities"] = temp;
    _hasTextEntities = true;
}

bool Game::hasTitle() const
{
    return _hasTitle;
}

bool Game::hasDescription() const
{
    return _hasDescription;
}

bool Game::hasText() const
{
    return _hasText;
}

bool Game::hasAnimation() const
{
    return _hasAnimation;
}

bool Game::hasPhoto() const
{
    return _hasPhoto;
}

bool Game::hasTextEntities() const
{
    return _hasTextEntities;
}
