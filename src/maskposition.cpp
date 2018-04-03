#include "include/maskposition.h"

using namespace TarnaBot;
MaskPosition::MaskPosition(QJsonObject obj)
{
    root = obj;
    
    point = root["point"].toString();
    
    xShift = root["x_shift"].toVariant().toDouble();
    yShift = root["y_shift"].toVariant().toDouble();
    scale = root["scale"].toVariant().toDouble();
}

MaskPosition::MaskPosition()
{
    
}

MaskPosition MaskPosition::fromObject(QJsonObject obj)
{
    return MaskPosition(obj);
}

//Getters/setters
QString MaskPosition::getPoint() const
{
    return point;
}

void MaskPosition::setPoint(const QString &value)
{
    point = value;
    root["point"] = point;
}

double MaskPosition::getXShift() const
{
    return xShift;
}

void MaskPosition::setXShift(double value)
{
    xShift = value;
    root["x_shift"] = xShift;
}

double MaskPosition::getYShift() const
{
    return yShift;
}

void MaskPosition::setYShift(double value)
{
    yShift = value;
    root["y_shift"] = yShift;
}

double MaskPosition::getScale() const
{
    return scale;
}

void MaskPosition::setScale(double value)
{
    scale = value;
    root["scale"] = scale;
}
