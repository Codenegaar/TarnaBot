#ifndef REPLYKEYBOARDREMOVE_H
#define REPLYKEYBOARDREMOVE_H
///
#include <QJsonObject>

class ReplyKeyboardRemove
{
public:
    ReplyKeyboardRemove(QJsonObject obj);
    ReplyKeyboardRemove();
    
    static ReplyKeyboardRemove fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/setters
    bool getRemoveKeyboard() const;
    void setRemoveKeyboard(bool value);
    
    bool getSelective() const;
    void setSelective(bool value);
    
private:
    bool removeKeyboard = true;
    bool selective;
    
    QJsonObject root;
};

#endif // REPLYKEYBOARDREMOVE_H
