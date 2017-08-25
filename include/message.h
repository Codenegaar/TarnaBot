#ifndef MESSAGE_H
#define MESSAGE_H

#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QVariant>

#include "user.h"
class Message
{
public:
    Message(QJsonObject obj);
    
    long long getMessageId() const;
    void setMessageId(long long value);
    
    long long getMigrateToChatId() const;
    void setMigrateToChatId(long long value);
    
    long long getMigrateFromChatId() const;
    void setMigrateFromChatId(long long value);
    
    long long getForwardFromMessageId() const;
    void setForwardFromMessageId(long long value);
    
    QString getForwardSignature() const;
    void setForwardSignature(const QString &value);
    
    QString getAuthorSignature() const;
    void setAuthorSignature(const QString &value);
    
    QString getText() const;
    void setText(const QString &value);
    
    QString getCaption() const;
    void setCaption(const QString &value);
    
    QString getNewChatTitle() const;
    void setNewChatTitle(const QString &value);
    
    
    bool getDeleteChatPhoto() const;
    void setDeleteChatPhoto(bool value);
    
    bool getGroupChatCreated() const;
    void setGroupChatCreated(bool value);
    
    bool getSupergroupChatCreated() const;
    void setSupergroupChatCreated(bool value);
    
    bool getChannelChatCreated() const;
    void setChannelChatCreated(bool value);
    
    User *getFrom() const;
    void setFrom(User *value);
    
    User *getForwardFrom() const;
    void setForwardFrom(User *value);
    
    User **getNewChatMembers() const;
    void setNewChatMembers(User **value);
    
    User *getNewChatMember() const;
    void setNewChatMember(User *value);
    
    User *getLeftChatMember() const;
    void setLeftChatMember(User *value);
    
private:
    long long int messageId;
    long long int migrateToChatId;
    long long int migrateFromChatId;
    long long int forwardFromMessageId;
    //forwardDate
    //editDate
    //date
    
    QString forwardSignature;
    QString authorSignature;
    QString text;
    QString caption;
    QString newChatTitle;
    
    bool deleteChatPhoto;
    bool groupChatCreated;
    bool supergroupChatCreated;
    bool channelChatCreated;
    
    User *from;
    User *forwardFrom;
    User **newChatMembers; //Array
    User *newChatMember;
    User *leftChatMember;
    
    QJsonObject root;
};

#endif // MESSAGE_H
