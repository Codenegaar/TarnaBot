#ifndef SHIPPINGOPTION_H
#define SHIPPINGOPTION_H

#include <QJsonArray>
#include <QString>
#include <QVector>

#include "TelegramObject"
#include "LabeledPrice"

namespace Telegram
{
    class ShippingOption : public TelegramObject
    {
    public:
        ShippingOption();
        ShippingOption(QJsonObject jsonObject);
        ShippingOption(QString id, QString title, QVector<LabeledPrice> prices);
        
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
    };
}
#endif // SHIPPINGOPTION_H
