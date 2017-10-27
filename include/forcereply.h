#ifndef FORCEREPLY_H
#define FORCEREPLY_H
///
#include <QJsonObject>

class ForceReply
{
public:
    ForceReply(QJsonObject obj);
    ForceReply();
    
    static ForceReply fromObject(QJsonObject obj);
    QJsonObject toObject();

    //Getters/setters
    
    bool getForceReply() const;
    void setForceReply(bool value);
    
    bool getSelective() const;
    void setSelective(bool value);
    
private:
    bool forceReply = true;
    bool selective;
    
    QJsonObject root;
};

#endif // FORCEREPLY_H
