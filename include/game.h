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
        bool getHasTitle() const;
        
        bool getHasDescription() const;
        
        bool getHasText() const;
        
        bool getHasAnimation() const;
        
        bool getHasPhoto() const;
        
        bool getHasTextEntities() const;
        
    private:
        QString title;
        QString description;
        QString text;
        
        Animation animation;
        
        QVector< PhotoSize > photo;
        QVector< MessageEntity > textEntities;
        
        //flags
        bool hasTitle;
        bool hasDescription;
        bool hasText;
        bool hasAnimation;
        bool hasPhoto;
        bool hasTextEntities;
    };
}
#endif // GAME_H
