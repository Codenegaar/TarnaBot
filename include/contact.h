#ifndef CONTACT_H
#define CONTACT_H
//
#include <QJsonObject>
#include <QString>
#include <QVariant>

class Contact
{
public:
    Contact(QJsonObject obj);
    Contact();
    
    static Contact fromObject(QJsonObject obj);
    QJsonObject toObject();
    void refresh();
    //Getters/setters
    
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &value);
    
    QString getFirstName() const;
    void setFirstName(const QString &value);
    
    QString getLastName() const;
    void setLastName(const QString &value);
    
    qint64 getUserId() const;
    void setUserId(const qint64 &value);
    
private:
    QString phoneNumber;
    QString firstName;
    QString lastName;
    
    qint64 userId;
    
    QJsonObject root;
};

#endif // CONTACT_H
