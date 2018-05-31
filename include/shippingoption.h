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
        bool hasId() const;
        
        bool hasTitle() const;
        
        bool hasPrices() const;
        
    private:
        QString id;
        QString title;
        
        QVector< LabeledPrice > prices;
        
        //Flags
        bool _hasId;
        bool _hasTitle;
        bool _hasPrices;
    };
}
#endif // SHIPPINGOPTION_H
