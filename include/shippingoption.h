#ifndef SHIPPINGOPTION_H
#define SHIPPINGOPTION_H

#include <QJsonArray>
#include <QString>
#include <QVector>

#include "tarnaobject.h"
#include "labeledprice.h"

namespace Telegram
{
    class ShippingOption : public TarnaObject
    {
    public:
        ShippingOption();
        ShippingOption(QJsonObject obj);
        
        //Getters/Setters
        QString getId() const;
        void setId(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QVector<LabeledPrice> getPrices() const;
        void setPrices(const QVector<LabeledPrice> &value);
        
        //Flag getters
        bool getHasId() const;
        
        bool getHasTitle() const;
        
        bool getHasPrices() const;
        
    private:
        QString id;
        QString title;
        
        QVector< LabeledPrice > prices;
        
        //Flags
        bool hasId;
        bool hasTitle;
        bool hasPrices;
    };
}
#endif // SHIPPINGOPTION_H
