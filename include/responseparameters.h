#ifndef RESPONSEPARAMETERS_H
#define RESPONSEPARAMETERS_H
#include <QJsonObject>
#include <QVariant>

class ResponseParameters
{
public:
    ResponseParameters(QJsonObject obj);
    ResponseParameters();
    
    static ResponseParameters fromObject(QJsonObject obj);
    //Getters/setters
    
    qint64 getMigrateToChatId() const;
    void setMigrateToChatId(const qint64 &value);
    
    qint64 getRetryAfter() const;
    void setRetryAfter(const qint64 &value);
    
private:
    qint64 migrateToChatId;
    qint64 retryAfter;
    
    QJsonObject root;
};

#endif // RESPONSEPARAMETERS_H
