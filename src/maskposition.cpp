#include "include/maskposition.h"

using namespace TarnaBot;
MaskPosition::MaskPosition(QJsonObject obj)
{
    root = obj;
    
    point = root["point"].toString();
    hasPoint = true;
    xShift = root["x_shift"].toVariant().toDouble();
    hasXShift = true;
    yShift = root["y_shift"].toVariant().toDouble();
    hasYShift = true;
    scale = root["scale"].toVariant().toDouble();
    hasScale = true;
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
    hasPoint = true;
}

double MaskPosition::getXShift() const
{
    return xShift;
}

void MaskPosition::setXShift(double value)
{
    xShift = value;
    root["x_shift"] = xShift;
    hasXShift = true;
}

double MaskPosition::getYShift() const
{
    return yShift;
}

void MaskPosition::setYShift(double value)
{
    yShift = value;
    root["y_shift"] = yShift;
    hasYShift = true;
}

double MaskPosition::getScale() const
{
    return scale;
}

void MaskPosition::setScale(double value)
{
    scale = value;
    root["scale"] = scale;
    hasScale = true;
}

bool MaskPosition::getHasPoint() const
{
    return hasPoint;
}

bool MaskPosition::getHasXShift() const
{
    return hasXShift;
}

bool MaskPosition::getHasYShift() const
{
    return hasYShift;
}

bool MaskPosition::getHasScale() const
{
    return hasScale;
}
