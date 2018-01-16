#include "include/inputmessagecontent.h"

InputMessageContent::InputMessageContent()
{
    
}

InputMessageContent::InputMessageContent(QJsonObject obj)
{
    bool ok = false;
    root = obj;
    
    //Determine type
    if(root.contains("message_text"))
    {
        type = "text";
        messageText = root["message_text"].toString();
        
        if(root.contains("parse_mode"))
            parseMode = root["parse_mode"].toString();
        
        if(root.contains("disable_web_page_preview"))
            disableWebPagePreview = root["disable_web_page_preview"].toBool();
    }
    
    else if(root.contains("title"))
    {
        type = "venue";
        latitude = root["latitude"].toVariant().toDouble(&ok);
        longitude = root["longitude"].toVariant().toDouble(&ok);
        
        title = root["title"].toString();
        address = root["address"].toString();
        
        if(root.contains("foursquare_id"))
            foursquareId = root["foursquare_id"].toString();
    }
    
    else if(root.contains("latitude"))
    {
        type = "location";
        latitude = root["latitude"].toVariant().toDouble(&ok);
        longitude = root["longitude"].toVariant().toDouble(&ok);
        
        if(root.contains("live_period"))
            livePeriod = root["live_period"].toVariant().toInt(&ok);
    }
    
    else if(root.contains("phone_number"))
    {
        type = "contact";
        phoneNumber = root["phone_number"].toString();
        firstName = root["first_name"].toString();
        
        if(root.contains("last_name"))
            lastName = root["last_name"].toString();
    }
}

InputMessageContent InputMessageContent::fromObject(QJsonObject obj)
{
    return InputMessageContent(obj);
}

QJsonObject InputMessageContent::toObject()
{
    return root;
}

//Getters/Setters
QString InputMessageContent::getMessageText() const
{
    return messageText;
}

void InputMessageContent::setMessageText(const QString &value)
{
    messageText = value;
    root["message_text"] = messageText;
}

QString InputMessageContent::getParseMode() const
{
    return parseMode;
}

void InputMessageContent::setParseMode(const QString &value)
{
    parseMode = value;
    root["parse_mode"] = parseMode;
}

bool InputMessageContent::getDisableWebPagePreview() const
{
    return disableWebPagePreview;
}

void InputMessageContent::setDisableWebPagePreview(bool value)
{
    disableWebPagePreview = value;
    root["disable_web_page_preview"] = disableWebPagePreview;
}

double InputMessageContent::getLongitude() const
{
    return longitude;
}

void InputMessageContent::setLongitude(double value)
{
    longitude = value;
    root["longitude"] = longitude;
}

double InputMessageContent::getLatitude() const
{
    return latitude;
}

void InputMessageContent::setLatitude(double value)
{
    latitude = value;
    root["latitude"] = latitude;
}

int InputMessageContent::getLivePeriod() const
{
    return livePeriod;
}

void InputMessageContent::setLivePeriod(int value)
{
    livePeriod = value;
    root["live_period"] = livePeriod;
}

QString InputMessageContent::getTitle() const
{
    return title;
}

void InputMessageContent::setTitle(const QString &value)
{
    title = value;
    root["title"] = title;
}

QString InputMessageContent::getAddress() const
{
    return address;
}

void InputMessageContent::setAddress(const QString &value)
{
    address = value;
    root["address"] = address;
}

QString InputMessageContent::getFoursquareId() const
{
    return foursquareId;
}

void InputMessageContent::setFoursquareId(const QString &value)
{
    foursquareId = value;
    root["foursquare_id"] = foursquareId;
}

QString InputMessageContent::getPhoneNumber() const
{
    return phoneNumber;
}

void InputMessageContent::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
    root["phone_number"] = phoneNumber;
}

QString InputMessageContent::getFirstName() const
{
    return firstName;
}

void InputMessageContent::setFirstName(const QString &value)
{
    firstName = value;
    root["first_name"] = firstName;
}

QString InputMessageContent::getLastName() const
{
    return lastName;
}

void InputMessageContent::setLastName(const QString &value)
{
    lastName = value;
    root["last_name"] = lastName;
}

QString InputMessageContent::getType() const
{
    return type;
}

void InputMessageContent::setType(const QString &value)
{
    type = value;
    root["type"] = type;
}
