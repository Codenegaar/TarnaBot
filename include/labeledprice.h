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
        
        static LabeledPrice fromObject(QJsonObject obj);
        
        //Getters/Setters
        QString getLabel() const;
        void setLabel(const QString &value);
        
        int getAmount() const;
        void setAmount(int value);
        
        //Flag getters
        bool getHasLabel() const;
        
        bool getHasAmount() const;
        
    private:
        QString label;
        int amount;
        
        //flags
        bool hasLabel;
        bool hasAmount;
    };
}
#endif // LABELEDPRICE_H
