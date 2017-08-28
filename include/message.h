#ifndef MESSAGE_H
#define MESSAGE_H
#include <QJsonObject>

class Message
{
public:
    Message(QJsonObject obj);
    Message();
    
    static Message fromObject(QJsonObject obj);
private:
    
};

#endif // MESSAGE_H
