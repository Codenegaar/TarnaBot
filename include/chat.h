#ifndef CHAT_H
#define CHAT_H

#include <QString>
#include <QVariant>
#include <QSharedPointer>

#include "tarnaobject.h"
#include "chatphoto.h"
#include "message.h"


namespace Telegram
{
    class Message;      //FIX for usage of chat and message in each other`s body
    class Chat : public TarnaObject
    {
    public:
        Chat(QJsonObject obj);
        Chat();
        virtual ~Chat();
        
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
        bool hasId() const;
        
        bool hasTitle() const;
        
        bool hasType() const;
        
        bool hasUsername() const;
        
        bool hasFirstName() const;
        
        bool hasLastName() const;
        
        bool hasDescription() const;
        
        bool hasInviteLink() const;
        
        bool hasPhoto() const;
        
        bool hasPinnedMessage() const;
        
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
        bool _hasId;
        bool _hasTitle;
        bool _hasType;
        bool _hasUsername;
        bool _hasFirstName;
        bool _hasLastName;
        bool _hasDescription;
        bool _hasInviteLink;
        bool _hasPhoto;
        bool _hasPinnedMessage;
    };
}
#endif // CHAT_H
