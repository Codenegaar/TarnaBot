#ifndef INPUTMESSAGECONTENT_H
#define INPUTMESSAGECONTENT_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

class InputMessageContent : public TarnaObject
{
public:
    InputMessageContent();
    InputMessageContent(QJsonObject obj);
    
    static InputMessageContent fromObject(QJsonObject obj);
    
    //Getters/Setters
    QString getMessageText() const;
    void setMessageText(const QString &value);
    
    QString getParseMode() const;
    void setParseMode(const QString &value);
    
    bool getDisableWebPagePreview() const;
    void setDisableWebPagePreview(bool value);
    
    double getLongitude() const;
    void setLongitude(double value);
    
    double getLatitude() const;
    void setLatitude(double value);
    
    int getLivePeriod() const;
    void setLivePeriod(int value);
    
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QString getAddress() const;
    void setAddress(const QString &value);
    
    QString getFoursquareId() const;
    void setFoursquareId(const QString &value);
    
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &value);
    
    QString getFirstName() const;
    void setFirstName(const QString &value);
    
    QString getLastName() const;
    void setLastName(const QString &value);
    
    QString getType() const;
    void setType(const QString &value);
    
private:
    /**
      Plan B:
      We declare all of the needed properties here
      + a "type" which is used to identify the object.
      Constructor and toObject work with needed values.
      **/
    
    //InputTextMessageContent types
    QString messageText;
    QString parseMode;
    bool disableWebPagePreview;
    
    //InputLocation/VenueMessageContent
    double longitude;
    double latitude;
    int livePeriod;
    QString title;
    QString address;
    QString foursquareId;
    
    //InputContactMessageContent
    QString phoneNumber;
    QString firstName;
    QString lastName;
    
    QString type;
};

#endif // INPUTMESSAGECONTENT_H
