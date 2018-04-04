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
        
        static InputContactMessageContent fromObject(QJsonObject obj);
        
        //Getters/Setters
        QString getPhoneNumber() const;
        void setPhoneNumber(const QString &value);
        
        QString getFirstName() const;
        void setFirstName(const QString &value);
        
        QString getLastName() const;
        void setLastName(const QString &value);
        
        //Flag getters
        bool getHasPhoneNumber() const;
        
        bool getHasFirstName() const;
        
        bool getHasLastName() const;
        
    private:
        QString phoneNumber;
        QString firstName;
        QString lastName;
        
        //Flags
        bool hasPhoneNumber;
        bool hasFirstName;
        bool hasLastName;
    };
}
#endif // INPUTCONTACTMESSAGECONTENT_H
