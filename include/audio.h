#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QVariant>

#include "TelegramObject"

namespace Telegram
{
    /*!
     * \brief The Audio class represents an audio file
     * to be treated as music by the Telegram clients.
     */
    class Audio : public TelegramObject
    {
    public:
        Audio();
        /*!
         * \param jsonObject The JSON object to construct the object with.
         *
         * Creates an Audio object from a JSON object.
         */
        Audio(QJsonObject jsonObject);
        /*!
         * \param fileId The audio's file id.
         * \param duration Audio's duration in seconds.
         *
         * Creates an Audio object and sets the required properties.
         */
        Audio(QString fileId, qint64 duration);
        
        //Getters/Setters
        /*!
         * \return file ID of the audio.
         */
        QString getFileId() const;
        /*!
         * \param value File ID for this audio.
         */
        void setFileId(const QString &value);
        
        /*!
         * \return Performer of the audio as defined by sender or by audio tags.
         */
        QString getPerformer() const;
        /*!
         * \param value Performer of the audio as defined by sender or by audio tags.
         */
        void setPerformer(const QString &value);
        
        /*!
         * \return Title of the audio as defined by sender or by audio tags.
         */
        QString getTitle() const;
        /*!
         * \param value Title of the audio as defined by sender or by audio tags.
         */
        void setTitle(const QString &value);
        
        /*!
         * \return MIME type of the file as defined by sender
         *
         * Refer to \ref mimetypes for more info.
         */
        QString getMimeType() const;
        /*!
         * \param value MIME type of the file as defined by sender.
         *
         * Refer to \ref mimetypes for more info.
         */
        void setMimeType(const QString &value);
        
        /*!
         * \return Duration of the audio in seconds as defined by sender.
         */
        qint64 getDuration() const;
        /*!
         * \param value Duration of the audio in seconds as defined by sender.
         */
        void setDuration(const qint64 &value);
        
        /*!
         * \return file size.
         */
        qint64 getFileSize() const;
        /*!
         * \param value File size.
         */
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
