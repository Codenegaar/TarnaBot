#ifndef USER_H
#define USER_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace TarnaBot
{
    class User : public TarnaObject
    {
    public:
        User(QJsonObject obj);
        User();
        
        static User fromObject(QJsonObject obj);
    
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
        
    private:
        qint64 id;
        
        bool isBot;
        
        QString firstName;
        QString lastName;
        QString username;
        QString languageCode;
    };
}
#endif // USER_H
