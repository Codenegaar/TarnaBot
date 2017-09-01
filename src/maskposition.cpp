#include "include/maskposition.h"

MaskPosition::MaskPosition(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    point = root["point"].toString();
    
    xShift = root["x_shift"].toVariant().toDouble(&ok);
    yShift = root["y_shift"].toVariant().toDouble(&ok);
    scale = root["scale"].toVariant().toDouble(&ok);
}

MaskPosition::MaskPosition()
{
    
}

MaskPosition MaskPosition::fromObject(QJsonObject obj)
{
    return MaskPosition(obj);
}

QString MaskPosition::getPoint() const
{
    return point;
}

void MaskPosition::setPoint(const QString &value)
{
    point = value;
}

double MaskPosition::getXShift() const
{
    return xShift;
}

void MaskPosition::setXShift(double value)
{
    xShift = value;
}

double MaskPosition::getYShift() const
{
    return yShift;
}

void MaskPosition::setYShift(double value)
{
    yShift = value;
}

double MaskPosition::getScale() const
{
    return scale;
}

void MaskPosition::setScale(double value)
{
    scale = value;
}
