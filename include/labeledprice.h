#ifndef LABELEDPRICE_H
#define LABELEDPRICE_H

#include <QString>
#include <QVariant>

#include "tarnaobject.h"

namespace TarnaBot
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
        
        //Public flags
        bool hasLabel = false;
        bool hasAmount = false;
        
    private:
        QString label;
        int amount;
    };
}
#endif // LABELEDPRICE_H
