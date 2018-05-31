#ifndef INPUTCONTACTMESSAGECONTENT_H
#define INPUTCONTACTMESSAGECONTENT_H

#include <QString>

#include "inputmessagecontent.h"

namespace Telegram
{
    class InputContactMessageContent : public InputMessageContent
    {
    public:
        InputContactMessageContent();
        InputContactMessageContent(QJsonObject obj);
        
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
        
    private:
        QString phoneNumber;
        QString firstName;
        QString lastName;
        
        //Flags
        bool _hasPhoneNumber;
        bool _hasFirstName;
        bool _hasLastName;
    };
}
#endif // INPUTCONTACTMESSAGECONTENT_H
