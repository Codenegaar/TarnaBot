#ifndef INPUTCONTACTMESSAGECONTENT_H
#define INPUTCONTACTMESSAGECONTENT_H

#include <QString>

#include "InputMessageContent"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InputContactMessageContent : public InputMessageContent
    {
    public:
        InputContactMessageContent();
        InputContactMessageContent(QJsonObject jsonObject);
        InputContactMessageContent(QString phoneNumber, QString firstName);
        
        //Getters/Setters
        QString getPhoneNumber() const;
        void setPhoneNumber(const QString &value);
        
        QString getFirstName() const;
        void setFirstName(const QString &value);
        
        QString getLastName() const;
        void setLastName(const QString &value);
        
        //Flag getters
        bool hasPhoneNumber() const;
        
        bool hasFirstName() const;
        
        bool hasLastName() const;
    };
}
#endif // INPUTCONTACTMESSAGECONTENT_H
