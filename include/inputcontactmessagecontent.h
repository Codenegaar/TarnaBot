#ifndef INPUTCONTACTMESSAGECONTENT_H
#define INPUTCONTACTMESSAGECONTENT_H

#include <QJsonObject>

class InputContactMessageContent
{
public:
    const QString type = "contact";
    InputContactMessageContent();
    InputContactMessageContent(QJsonObject obj);
    
    static InputContactMessageContent fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/setters
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &value);
    
    QString getFirstName() const;
    void setFirstName(const QString &value);
    
    QString getLastName() const;
    void setLastName(const QString &value);
    
private:
    QString phoneNumber;
    QString firstName;
    QString lastName;
    
    QJsonObject root;
};

#endif // INPUTCONTACTMESSAGECONTENT_H
