#ifndef USER_H
#define USER_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT User : public TelegramObject
    {
    public:
        User();
        User(QJsonObject jsonObject);
        User(qint64 id, QString firstName, bool isBot);
    
        //Getters/Setters    
        qint64 getId() const;
        void setId(qint64 &value);
        
        bool getIsBot() const;
        void setIsBot(bool value);
        
        QString getFirstName() const;
        void setFirstName(const QString &value);
        
        QString getLastName() const;
        void setLastName(const QString &value);
        
        QString getUsername() const;
        void setUsername(const QString &value);
        
        QString getLanguageCode() const;
        void setLanguageCode(const QString &value);
        
        //Flag getters
        bool hasId() const;
        
        bool hasFirstName() const;
        
        bool hasLastName() const;
        
        bool hasUsername() const;
        
        bool hasLanguageCode() const;
    };
}
#endif // USER_H
