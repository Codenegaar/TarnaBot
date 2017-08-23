#include "../include/update.h"

Update::Update(QJsonObject obj)
{
    root = obj;
    bool ok = false;
    
    updateId = root["update_id"].toVariant().toLongLong(&ok);
}

//Getters
long long int Update::getUpdateId()
{
    return updateId;
}

QJsonObject Update::getObject()
{
    return root;
}

//Setters
void Update::setUpdateId(long long int value)
{
    updateId = value;
}

