#ifndef GAME_H
#define GAME_H

#include <QJsonArray>
#include <QString>
#include <QVector>

#include "TelegramObject"
#include "Animation"
#include "MessageEntity"
#include "PhotoSize"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT Game : public TelegramObject
    {
    public:
        Game();
        Game(QJsonObject jsonObject);
        Game(QString title, QString description, QVector<PhotoSize> photo);
        
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
    };
}
#endif // GAME_H
