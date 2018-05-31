#ifndef USER_H
#define USER_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class User : public TarnaObject
    {
    public:
        User(QJsonObject obj);
        User();
    
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
        
    private:
        qint64 id;
        
        bool isBot;
        
        QString firstName;
        QString lastName;
        QString username;
        QString languageCode;
        
        //Flags
        bool _hasId;
        bool _hasFirstName;
        bool _hasLastName;
        bool _hasUsername;
        bool _hasLanguageCode;
    };
}
#endif // USER_H
