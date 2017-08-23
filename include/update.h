#ifndef UPDATE_H
#define UPDATE_H

#include <QJsonObject>
#include <QVariant>

class Update
{
public:
    Update(QJsonObject obj);
    
    //Getters
    long long int getUpdateId();
    
    QJsonObject getObject();
    
    //Setters
    void setUpdateId(long long int value);
private:
    long long int updateId;
    
    QJsonObject root;
};

#endif //UPDATE_H
