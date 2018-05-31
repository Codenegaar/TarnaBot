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
        bool hasTitle() const;
        
        bool hasDescription() const;
        
        bool hasStartParameter() const;
        
        bool hasCurrency() const;
        
        bool hasTotalAmount() const;
        
    private:
        QString title;
        QString description;
        QString startParameter;
        QString currency;
        
        int totalAmount;
        
        //flags
        bool _hasTitle;
        bool _hasDescription;
        bool _hasStartParameter;
        bool _hasCurrency;
        bool _hasTotalAmount;
    };
}
#endif // INVOICE_H
