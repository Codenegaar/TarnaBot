#ifndef AUDIO_H
#define AUDIO_H

#include <QString>
#include <QVariant>

#include "TelegramObject"
#include "PhotoSize"

namespace Telegram
{
    /*!
     * \brief The Audio class represents an audio file
     * to be treated as music by the Telegram clients.
     */
    class TARNABOTSHARED_EXPORT Audio : public TelegramObject
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

        /*!
         * \return Thumbnail of the album cover
         * to which the music file belongs
         */
        PhotoSize getThumb() const;
        void setThumb(const PhotoSize& value);
        
        //Flag getters
        bool hasFileId() const;
        
        bool hasPerformer() const;
        
        bool hasTitle() const;
        
        bool hasMimeType() const;
        
        bool hasDuration() const;
        
        bool hasFileSize() const;
        bool hasThumb() const;
    };
}
#endif // AUDIO_H
