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
    description = root["description"].toString();
    
    //initialize "photo"
    temp1 = root["photo"].toArray();
    l = temp1.size();
    
    for(i = 0; i < l; i++)
        photo[i] = PhotoSize::fromObject(temp1.at(0).toObject());
    
    //Optional Types
    if(root.contains("text"))
        text = root["text"].toString();
    
    if(root.contains("text_entities"))
    {
        temp1 = root["text_entities"].toArray();
        l = temp1.size();
        
        for(i = 0; i < l; i++)
            textEntities[i] = MessageEntity::fromObject(temp1.at(i).toObject());
    }
    
    if(root.contains("animation"))
        animation = Animation::fromObject(root["animation"].toObject());
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
}

QString Game::getDescription() const
{
    return description;
}

void Game::setDescription(const QString &value)
{
    description = value;
    root["description"] = description;
}

QString Game::getText() const
{
    return text;
}

void Game::setText(const QString &value)
{
    text = value;
    root["text"] = text;
}

Animation Game::getAnimation() const
{
    return animation;
}

void Game::setAnimation(const Animation &value)
{
    animation = value;
    root["animation"] = animation.toObject();
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
