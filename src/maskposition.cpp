#include "include/maskposition.h"
using namespace Telegram;

MaskPosition::MaskPosition()
{

}

MaskPosition::MaskPosition(QJsonObject jsonObject) :
    TelegramObject(jsonObject)
{

}

MaskPosition::MaskPosition(QString point, double xShift, double yShift, double scale)
{
    setPoint(point);
    setXShift(xShift);
    setYShift(yShift);
    setScale(scale);
}

//Getters/setters
QString MaskPosition::getPoint() const
{
    return jsonObject["point"].toString();
}

void MaskPosition::setPoint(const QString &value)
{
    jsonObject["point"] = value;
}

double MaskPosition::getXShift() const
{
    return jsonObject["x_shift"].toVariant().toDouble();
}

void MaskPosition::setXShift(double value)
{
    jsonObject["x_shift"] = value;
}

double MaskPosition::getYShift() const
{
    return jsonObject["y_shift"].toVariant().toDouble();
}

void MaskPosition::setYShift(double value)
{
    jsonObject["y_shift"] = value;
}

double MaskPosition::getScale() const
{
    return jsonObject["scale"].toVariant().toDouble();
}

void MaskPosition::setScale(double value)
{
    jsonObject["scale"] = value;
}

bool MaskPosition::hasPoint() const
{
    return jsonObject.contains("point");
}

bool MaskPosition::hasXShift() const
{
    return jsonObject.contains("x_shift");
}

bool MaskPosition::hasYShift() const
{
    return jsonObject.contains("y_shift");
}

bool MaskPosition::hasScale() const
{
    return jsonObject.contains("scale");
}
