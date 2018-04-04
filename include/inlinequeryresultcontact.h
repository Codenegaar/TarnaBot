#ifndef INLINEQUERYRESULTCONTACT_H
#define INLINEQUERYRESULTCONTACT_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace Telegram
{
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
        
        //Flag getters
        bool getHasPhoneNumber() const;
        
        bool getHasFirstName() const;
        
        bool getHasLastName() const;
        
        bool getHasThumbUrl() const;
        
        bool getHasThumbWidth() const;
        
        bool getHasThumbHeight() const;
        
    private:
        QString phoneNumber;
        QString firstName;
        QString lastName;
        QString thumbUrl;
        
        int thumbWidth;
        int thumbHeight;
        
        //Flags
        bool hasPhoneNumber;
        bool hasFirstName;
        bool hasLastName;
        bool hasThumbUrl;
        bool hasThumbWidth;
        bool hasThumbHeight;
    };
}
#endif // INLINEQUERYRESULTCONTACT_H
