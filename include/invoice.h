#ifndef INVOICE_H
#define INVOICE_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT Invoice : public TelegramObject
    {
    public:
        Invoice();
        Invoice(QJsonObject jsonObject);
        Invoice(QString title, QString description, QString startParameter,
                QString currency, int totalAmount);
        
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
    };
}
#endif // INVOICE_H
