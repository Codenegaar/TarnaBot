#ifndef CHAT_H
#define CHAT_H

#include <QString>
#include <QVariant>
#include <QSharedPointer>

#include "TelegramObject"
#include "ChatPhoto"
#include "Message"

namespace Telegram
{
    class Message;      //Forward declaration of Message
    class Chat : public TelegramObject
    {
    public:
        Chat();
        Chat(QJsonObject obj);
        Chat(qint64 id, QString type);
        
        //Getters/Setters
        qint64 getId() const;
        void setId(qint64 &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);

        QString getType() const;
        void setType(const QString &value);
        
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
        void setPinnedMessage(const Message& value);
        
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
    };
}
#endif // CHAT_H
