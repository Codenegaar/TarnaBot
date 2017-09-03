#ifndef CHAT_H
#define CHAT_H
//
#include <QJsonObject>
#include <QString>
#include <QVariant>

#include <c++/7.1.1/type_traits>

#include "chatphoto.h"
#include "message.h"
class Chat
{
public:
    Chat(QJsonObject obj);
    Chat();
    static Chat fromObject(QJsonObject obj);
    QJsonObject toObject();
    void refresh();
    //Getters/Setters
    
    qint64 getId() const;
    void setId(qint64 &value);
    
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QString getUsername() const;
    void setUsername(const QString &value);
    
    QString getFirstName() const;
    void setFirstName(const QString &value);
    
    QString getLastName() const;
    void setLastName(const QString &value);
    
    QString getDescription() const;
    void setDescription(const QString &value);
    
    QString getInviteLink() const;
    void setInviteLink(const QString &value);
    
    bool getAllMembersAreAdministrators() const;
    void setAllMembersAreAdministrators(bool value);
    
    ChatPhoto getPhoto() const;
    void setPhoto(const ChatPhoto &value);
    
    Message getPinnedMessage() const;
    void setPinnedMessage(const Message &value);
    
private:
    qint64 id;
    
    QString type;
    QString title;
    QString username;
    QString firstName;
    QString lastName;
    QString description;
    QString inviteLink;
    
    bool allMembersAreAdministrators;
    
    ChatPhoto photo;
    Message pinnedMessage;
    
    QJsonObject root;
};

#endif // CHAT_H
