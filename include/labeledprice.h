#ifndef LABELEDPRICE_H
#define LABELEDPRICE_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    class TARNABOTSHARED_EXPORT LabeledPrice : public TelegramObject
    {
    public:
        LabeledPrice();
        LabeledPrice(QJsonObject jsonObject);
        LabeledPrice(QString label, int amount);
        
        //Getters/Setters
        QString getLabel() const;
        void setLabel(const QString &value);
        
        int getAmount() const;
        void setAmount(int value);
        
        //Flag getters
        bool hasLabel() const;
        
        bool hasAmount() const;
    };
}
#endif // LABELEDPRICE_H
