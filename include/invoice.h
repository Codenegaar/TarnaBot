#ifndef INVOICE_H
#define INVOICE_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class Invoice : public TarnaObject
    {
    public:
        Invoice();
        Invoice(QJsonObject obj);
        
        static Invoice fromObject(QJsonObject obj);
        
        //Getters/Setters
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getDescription() const;
        void setDescription(const QString &value);
        
        QString getStartParameter() const;
        void setStartParameter(const QString &value);
        
        QString getCurrency() const;
        void setCurrency(const QString &value);
        
        int getTotalAmount() const;
        void setTotalAmount(int value);
        
        //Flag getters
        bool getHasTitle() const;
        
        bool getHasDescription() const;
        
        bool getHasStartParameter() const;
        
        bool getHasCurrency() const;
        
        bool getHasTotalAmount() const;
        
    private:
        QString title;
        QString description;
        QString startParameter;
        QString currency;
        
        int totalAmount;
        
        //flags
        bool hasTitle;
        bool hasDescription;
        bool hasStartParameter;
        bool hasCurrency;
        bool hasTotalAmount;
    };
}
#endif // INVOICE_H
