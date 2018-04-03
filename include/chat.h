#ifndef CHAT_H
#define CHAT_H

#include <QString>
#include <QVariant>
#include <QSharedPointer>

#include "tarnaobject.h"
#include "chatphoto.h"
#include "message.h"


namespace TarnaBot
{
    class Message;      //FIX for usage of chat and message in each other`s body
    class Chat : public TarnaObject
    {
    public:
        Chat(QJsonObject obj);
        Chat();
        virtual ~Chat();
        static Chat fromObject(QJsonObject obj);
        
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
        
        Message *getPinnedMessage() const;
        void setPinnedMessage(Message *value);
        
        //Flag getters
        bool getHasId() const;
        
        bool getHasTitle() const;
        
        bool getHasType() const;
        
        bool getHasUsername() const;
        
        bool getHasFirstName() const;
        
        bool getHasLastName() const;
        
        bool getHasDescription() const;
        
        bool getHasInviteLink() const;
        
        bool getHasPhoto() const;
        
        bool getHasPinnedMessage() const;
        
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
        Message *pinnedMessage = 0;
        QSharedPointer<Message> pm;
        
        //flags
        bool hasId;
        bool hasTitle;
        bool hasType;
        bool hasUsername;
        bool hasFirstName;
        bool hasLastName;
        bool hasDescription;
        bool hasInviteLink;
        bool hasPhoto;
        bool hasPinnedMessage;
    };
}
#endif // CHAT_H
