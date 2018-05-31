#ifndef GAME_H
#define GAME_H

#include <QJsonArray>
#include <QString>
#include <QVector>

#include "tarnaobject.h"
#include "animation.h"
#include "messageentity.h"
#include "photosize.h"

namespace Telegram
{
    class Game : public TarnaObject
    {
    public:
        Game();
        Game(QJsonObject obj);
        
        //Getters/Setters
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getDescription() const;
        void setDescription(const QString &value);
        
        QString getText() const;
        void setText(const QString &value);
        
        Animation getAnimation() const;
        void setAnimation(const Animation &value);
        
        QVector<PhotoSize> getPhoto() const;
        void setPhoto(const QVector<PhotoSize> &value);
        
        QVector<MessageEntity> getTextEntities() const;
        void setTextEntities(const QVector<MessageEntity> &value);
        
        //Flag getters
        bool hasTitle() const;
        
        bool hasDescription() const;
        
        bool hasText() const;
        
        bool hasAnimation() const;
        
        bool hasPhoto() const;
        
        bool hasTextEntities() const;
        
    private:
        QString title;
        QString description;
        QString text;
        
        Animation animation;
        
        QVector< PhotoSize > photo;
        QVector< MessageEntity > textEntities;
        
        //flags
        bool _hasTitle;
        bool _hasDescription;
        bool _hasText;
        bool _hasAnimation;
        bool _hasPhoto;
        bool _hasTextEntities;
    };
}
#endif // GAME_H
