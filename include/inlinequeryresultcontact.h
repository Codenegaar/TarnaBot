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
        bool hasPhoneNumber() const;
        
        bool hasFirstName() const;
        
        bool hasLastName() const;
        
        bool hasThumbUrl() const;
        
        bool hasThumbWidth() const;
        
        bool hasThumbHeight() const;
        
    private:
        QString phoneNumber;
        QString firstName;
        QString lastName;
        QString thumbUrl;
        
        int thumbWidth;
        int thumbHeight;
        
        //Flags
        bool _hasPhoneNumber;
        bool _hasFirstName;
        bool _hasLastName;
        bool _hasThumbUrl;
        bool _hasThumbWidth;
        bool _hasThumbHeight;
    };
}
#endif // INLINEQUERYRESULTCONTACT_H
