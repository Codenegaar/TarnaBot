#ifndef CALLBACKQUERY_H
#define CALLBACKQUERY_H

#include <QString>

#include "TelegramObject"
#include "Message"
#include "User"

namespace Telegram
{
    /*!
     * \brief The CallbackQuery class represents an incoming callback
     * query from a callback button in an inline keyboard.
     *
     * If the button that originated the query was attached to a message sent by the bot,
     * the field message will be present. If the button was attached to a message
     * sent via the bot (in inline mode), the field inline_message_id will be present.
     * Exactly one of the fields data or game_short_name will be present.
     *
     * \sa Telegram::InlineKeyboardMarkup
     */
    class CallbackQuery : public TelegramObject
    {
    public:
        CallbackQuery();
        /*!
         * \brief Creates a CallbackQuery object using a JSON object.
         * \param jsonObject The JSON object to construct the object with.
         */
        CallbackQuery(QJsonObject jsonObject);
        /*!
         * \brief Creates a CallbackQuery object using the required properties.
         * \param id Unique identifier for this query
         * \param from Sender
         */
        CallbackQuery(QString id, User from);
    
        //Getters/setters
        /*!
         * \return Unique identifier for this query
         */
        QString getId() const;
        /*!
         * \param value Unique identifier for this query
         */
        void setId(const QString &value);
        
        /*!
         * \return  Identifier of the message sent via the bot in inline mode,
         * that originated the query.
         */
        QString getInlineMessageId() const;
        /*!
         * \param value  Identifier of the message sent via the bot in inline mode,
         * that originated the query.
         */
        void setInlineMessageId(const QString &value);
        
        /*!
         * \return Global identifier, uniquely corresponding to the chat to which
         * the message with the callback button was sent.
         * Useful for high scores in games.
         */
        QString getChatInstance() const;
        /*!
         * \param value Global identifier, uniquely corresponding to the chat to which
         * the message with the callback button was sent.
         * Useful for high scores in games.
         */
        void setChatInstance(const QString &value);
        
        /*!
         * \return Data associated with the callback button.
         * Be aware that a bad client can send arbitrary data in this field.
         */
        QString getData() const;
        /*!
         * \param value Data associated with the callback button.
         * Be aware that a bad client can send arbitrary data in this field.
         */
        void setData(const QString &value);
        
        /*!
         * \return Short name of a Game to be returned,
         * serves as the unique identifier for the game
         */
        QString getGameShortName() const;
        /*!
         * \param value Short name of a Game to be returned,
         * serves as the unique identifier for the game
         */
        void setGameShortName(const QString &value);
        
        /*!
         * \return Sender
         */
        User getFrom() const;
        /*!
         * \param value Sender
         */
        void setFrom(const User &value);
        
        /*!
         * \return Message with the callback button that originated the query.
         * Note that message content and message date
         * will not be available if the message is too old
         */
        Message getMessage() const;
        /*!
         * \param value Message with the callback button that originated the query.
         * Note that message content and message date
         * will not be available if the message is too old
         */
        void setMessage(const Message &value);
        
        //Flag getters
        bool hasId() const;
        
        bool hasInlineMessageId() const;
        
        bool hasChatInstance() const;
        
        bool hasData() const;
        
        bool hasGameShortName() const;
        
        bool hasFrom() const;
        
        bool hasMessage() const;
    };
}
#endif // CALLBACKQUERY_H
