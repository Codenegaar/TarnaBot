#ifndef INPUTLOCATIONMESSAGECONTENT_H
#define INPUTLOCATIONMESSAGECONTENT_H

#include <QJsonObject>
#include <QVariant>

class InputLocationMessageContent
{
public:
    InputLocationMessageContent();
    InputLocationMessageContent(QJsonObject obj);
    
    static InputLocationMessageContent fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    double getLatitude() const;
    void setLatitude(double value);
    
    double getLongitude() const;
    void setLongitude(double value);
    
    int getMaxPeriod() const;
    void setMaxPeriod(int value);
    
private:
    double latitude;
    double longitude;
    
    int maxPeriod;
    
    QJsonObject root;
};

#endif // INPUTLOCATIONMESSAGECONTENT_H
