#ifndef CHOSENINLINERESULT_H
#define CHOSENINLINERESULT_H

#include <QString>

#include "TelegramObject"
#include "User"
#include "Location"

namespace Telegram
{
    /*!
     * \brief The ChosenInlineResult class Represents
     * a result of an inline query that was chosen
     * by the user and sent to their chat partner.
     */
    class TARNABOTSHARED_EXPORT ChosenInlineResult : public TelegramObject
    {
    public:
        ChosenInlineResult();
        /*!
         * \brief Creates a ChosenInlineResult object using j JSON object.
         * \param jsonObject The JSON object to construct the object with.
         */
        ChosenInlineResult(QJsonObject jsonObject);
        /*!
         * \brief Creates a ChosenInlineResult object using the required properties.
         * \param resultId The unique identifier for the result that was chosen
         * \param query The query that was used to obtain the result
         * \param from The user that chose the result
         * \sa ChosenInlineResult::getResultId()
         * \sa ChosenInlineResult::getQuery()
         * \sa ChosenInlineResult::getFrom()
         */
        ChosenInlineResult(QString resultId, QString query, User from);
        
        //Getters/Setters
        /*!
         * \return The unique identifier for the result that was chosen.
         */
        QString getResultId() const;
        void setResultId(const QString &value);
        
        /*!
         * \return Optional. Identifier of the sent inline message.
         * Available only if there is an inline keyboard attached
         * to the message. Will be also received in
         * callback queries and can be used to edit the message.
         */
        QString getInlineMessageId() const;
        void setInlineMessageId(const QString &value);
        
        /*!
         * \return The query that was used to obtain the result
         */
        QString getQuery() const;
        void setQuery(const QString &value);
        
        /*!
         * \return The user that chose the result
         */
        User getFrom() const;
        void setFrom(const User &value);
        
        /*!
         * \return Optional. Sender location, only for
         * bots that require user location
         */
        Location getLocation() const;
        void setLocation(const Location &value);
        
        //Flag getters
        bool hasResultId() const;
        
        bool hasInlineMessageId() const;
        
        bool hasQuery() const;
        
        bool hasFrom() const;
        
        bool hasLocation() const;
    };
}
#endif // CHOSENINLINERESULT_H
