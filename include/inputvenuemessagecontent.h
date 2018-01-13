#ifndef INPUTVENUEMESSAGECONTENT_H
#define INPUTVENUEMESSAGECONTENT_H

#include <QJsonObject>
#include <QVariant>

class InputVenueMessageContent
{
public:
    const QString type = "venue";
    
    InputVenueMessageContent();
    InputVenueMessageContent(QJsonObject obj);
    
    static InputVenueMessageContent fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QString getAddress() const;
    void setAddress(const QString &value);
    
    QString getFoursquareId() const;
    void setFoursquareId(const QString &value);
    
    double getLatitude() const;
    void setLatitude(double value);
    
    double getLongitude() const;
    void setLongitude(double value);
    
private:
    QString title;
    QString address;
    QString foursquareId;
    
    double latitude;
    double longitude;
    
    QJsonObject root;
};

#endif // INPUTVENUEMESSAGECONTENT_H
