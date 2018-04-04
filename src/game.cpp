#include "include/game.h"

using namespace TarnaBot;
Game::Game()
{
    
}

Game::Game(QJsonObject obj)
{
    QJsonArray temp1;
    int l, i;
    root = obj;
    
    title = root["title"].toString();
    hasTitle = true;
    description = root["description"].toString();
    hasDescription = true;
    
    //initialize "photo"
    temp1 = root["photo"].toArray();
    l = temp1.size();
    
    for(i = 0; i < l; i++)
        photo[i] = PhotoSize::fromObject(temp1.at(0).toObject());
    hasPhoto = true;
    
    //Optional Types
    if(root.contains("text"))
    {
        text = root["text"].toString();
        hasText = true;
    }
    
    if(root.contains("text_entities"))
    {
        temp1 = root["text_entities"].toArray();
        l = temp1.size();
        
        for(i = 0; i < l; i++)
            textEntities[i] = MessageEntity::fromObject(temp1.at(i).toObject());
        hasTextEntities = true;
    }
    
    if(root.contains("animation"))
    {
        animation = Animation::fromObject(root["animation"].toObject());
        hasAnimation = true;
    }
}

Game Game::fromObject(QJsonObject obj)
{
    return Game(obj);
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
    hasTitle = true;
}

QString Game::getDescription() const
{
    return description;
}

void Game::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
    hasDescription = true;
}

QString Game::getText() const
{
    return text;
}

void Game::setText(const QString &value)
{
    text = value;
    root["text"] = text;
    hasText = true;
}

Animation Game::getAnimation() const
{
    return animation;
}

void Game::setAnimation(const Animation &value)
{
    animation = value;
    root["animation"] = animation.toObject();
    hasAnimation = true;
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
    hasPhoto = true;
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
    hasTextEntities = true;
}

bool Game::getHasTitle() const
{
    return hasTitle;
}

bool Game::getHasDescription() const
{
    return hasDescription;
}

bool Game::getHasText() const
{
    return hasText;
}

bool Game::getHasAnimation() const
{
    return hasAnimation;
}

bool Game::getHasPhoto() const
{
    return hasPhoto;
}

bool Game::getHasTextEntities() const
{
    return hasTextEntities;
}
