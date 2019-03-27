#ifndef INLINEQUERYRESULTCONTACT_H
#define INLINEQUERYRESULTCONTACT_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT InlineQueryResultContact : public InlineQueryResult
    {
    public:
        InlineQueryResultContact();
        InlineQueryResultContact(QJsonObject jsonObject);
        InlineQueryResultContact(QString id, QString phoneNumber, QString firstName);
        
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
    };
}
#endif // INLINEQUERYRESULTCONTACT_H
