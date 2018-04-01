#ifndef INLINEQUERYRESULTCONTACT_H
#define INLINEQUERYRESULTCONTACT_H

#include <QVariant>
#include "inlinequeryresult.h"

class InlineQueryResultContact : public InlineQueryResult
{
public:
    InlineQueryResultContact();
    InlineQueryResultContact(QJsonObject obj);
    
    //Getters/Setters
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &value);
    
    QString getFirstName() const;
    void setFirstName(const QString &value);
    
    QString getLastName() const;
    void setLastName(const QString &value);
    
    QString getThumbUrl() const;
    void setThumbUrl(const QString &value);
    
    int getThumbWidth() const;
    void setThumbWidth(int value);
    
    int getThumbHeight() const;
    void setThumbHeight(int value);
    
private:
    QString phoneNumber;
    QString firstName;
    QString lastName;
    QString thumbUrl;
    
    int thumbWidth;
    int thumbHeight;
};

#endif // INLINEQUERYRESULTCONTACT_H
