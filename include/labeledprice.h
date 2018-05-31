#ifndef LABELEDPRICE_H
#define LABELEDPRICE_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace Telegram
{
    class LabeledPrice : public TarnaObject
    {
    public:
        LabeledPrice();
        LabeledPrice(QJsonObject obj);
        
        //Getters/Setters
        QString getLabel() const;
        void setLabel(const QString &value);
        
        int getAmount() const;
        void setAmount(int value);
        
        //Flag getters
        bool hasLabel() const;
        
        bool hasAmount() const;
        
    private:
        QString label;
        int amount;
        
        //flags
        bool _hasLabel;
        bool _hasAmount;
    };
}
#endif // LABELEDPRICE_H
