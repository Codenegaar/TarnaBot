#ifndef CHOSENINLINERESULT_H
#define CHOSENINLINERESULT_H

#include <QJsonObject>
#include <QString>

#include "user.h"
#include "location.h"


class ChosenInlineResult
{
public:
    ChosenInlineResult();
    ChosenInlineResult(QJsonObject obj);
    
    static ChosenInlineResult fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    QString getResultId() const;
    void setResultId(const QString &value);
    
    QString getInlineMessageId() const;
    void setInlineMessageId(const QString &value);
    
    QString getQuery() const;
    void setQuery(const QString &value);
    
    User getFrom() const;
    void setFrom(const User &value);
    
    Location getLocation() const;
    void setLocation(const Location &value);
    
private:
    QString resultId;
    QString inlineMessageId;
    QString query;
    
    User from;
    Location location;
    
    QJsonObject root;
};

#endif // CHOSENINLINERESULT_H
