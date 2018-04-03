#ifndef MASKPOSITION_H
#define MASKPOSITION_H

#include <QVariant>
#include <QString>

#include "tarnaobject.h"

namespace TarnaBot
{
    class MaskPosition : public TarnaObject
    {
    public:
        MaskPosition(QJsonObject obj);
        MaskPosition();
        
        static MaskPosition fromObject(QJsonObject obj);
    
        //Getters/setters
        QString getPoint() const;
        void setPoint(const QString &value);
        
        double getXShift() const;
        void setXShift(double value);
        
        double getYShift() const;
        void setYShift(double value);
        
        double getScale() const;
        void setScale(double value);
        
        //Public flags
        bool hasPoint = false;
        bool hasXShift = false;
        bool hasYShift = false;
        bool hasScale = false;
        
    private:
        QString point;
        double xShift;
        double yShift;
        double scale;
    };
}
#endif // MASKPOSITION_H
