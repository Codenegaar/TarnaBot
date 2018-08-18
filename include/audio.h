#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    /*!
     * \brief The Audio class represents an audio file to be treated as music by the Telegram clients.
     */
    class Audio : public TelegramObject
    {
    public:
        Audio();
        /*!
         * \param jsonObject The JSON object to store
         *
         * Creates an instance using a JSON object.
         */
        Audio(QJsonObject jsonObject);
        /*!
         * \param fileId file identifier for this audio.
         * \param duration duration of the audio in seconds
         *
         * Creates an instance and sets the necessary properties for it.
         * \sa setFileId()
         * \sa setDuration()
         */
        Audio(QString fileId, qint64 duration);
        
        //Getters/Setters
        /*!
         * \return The file id of this audio.
         */
        QString getFileId() const;
        /*!
         * \param value New file id of the audio.
         */
        void setFileId(const QString &value);
        
        /*!
         * \brief getPerformer
         * \return
         */
        QString getPerformer() const;
        void setPerformer(const QString &value);
        
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getMimeType() const;
        void setMimeType(const QString &value);
        
        qint64 getDuration() const;
        void setDuration(const qint64 &value);
        
        qint64 getFileSize() const;
        void setFileSize(const qint64 &value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasPerformer() const;
        
        bool hasTitle() const;
        
        bool hasMimeType() const;
        
        bool hasDuration() const;
        
        bool hasFileSize() const;
    };
}
#endif // AUDIO_H
