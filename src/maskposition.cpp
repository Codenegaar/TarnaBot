#include "include/maskposition.h"

using namespace Telegram;
MaskPosition::MaskPosition(QJsonObject obj) : TarnaObject::TarnaObject(obj)
{
    point = root["point"].toString();
    _hasPoint = true;
    xShift = root["x_shift"].toVariant().toDouble();
    _hasXShift = true;
    yShift = root["y_shift"].toVariant().toDouble();
    _hasYShift = true;
    scale = root["scale"].toVariant().toDouble();
    _hasScale = true;
}

MaskPosition::MaskPosition()
{
    
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
    _hasPoint = true;
}

double MaskPosition::getXShift() const
{
    return xShift;
}

void MaskPosition::setXShift(double value)
{
    xShift = value;
    root["x_shift"] = xShift;
    _hasXShift = true;
}

double MaskPosition::getYShift() const
{
    return yShift;
}

void MaskPosition::setYShift(double value)
{
    yShift = value;
    root["y_shift"] = yShift;
    _hasYShift = true;
}

double MaskPosition::getScale() const
{
    return scale;
}

void MaskPosition::setScale(double value)
{
    scale = value;
    root["scale"] = scale;
    _hasScale = true;
}

bool MaskPosition::hasPoint() const
{
    return _hasPoint;
}

bool MaskPosition::hasXShift() const
{
    return _hasXShift;
}

bool MaskPosition::hasYShift() const
{
    return _hasYShift;
}

bool MaskPosition::hasScale() const
{
    return _hasScale;
}
