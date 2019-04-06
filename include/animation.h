#ifndef ANIMATION_H
#define ANIMATION_H

#include <QString>
#include <QVariant>

#include "PhotoSize"

namespace Telegram
{
    /*!
      \brief The Animation class represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
     */
    class TARNABOTSHARED_EXPORT Animation : public TelegramObject
    {
    public:
        Animation();
        /*!
         * \param jsonObject The JSON object to store
         *
         * Creates an instance using a JSON object.
         */
        Animation(QJsonObject jsonObject);
        /*!
         * \param fileId file identifier for this animation
         *
         * Creates an instance and sets fileId.
         * \sa setFileId()
         */
        Animation(QString fileId);
        
        //Getters/Setters
        /*!
         * \return The file id for this animation
         */
        QString getFileId() const;
        /*!
         * \param value New file ID for this animation.
         *
         * Sets the animation's file ID.
         * \see Telegram::File::setFileId()
         */
        void setFileId(const QString &value);

        /*!
         * \return Video width as defined by sender
         */
        int getWidth() const;
        void setWidth(int value);

        /*!
         * \return Video height as defined by sender
         */
        int getHeight() const;
        void setHeight(int value);

        /*!
         * \return Duration of the video in seconds
         * and as defined by the sender
         */
        qint64 getDuration() const;
        void setDuration(qint64 value);
        
        /*!
         * \return The file name.
         *
         * Gets the file name.
         */
        QString getFileName() const;
        /*!
         * \param value New file name.
         *
         * Sets the file name.
         */
        void setFileName(const QString &value);
        
        /*!
         * \return the animation's mime type
         *
         * Read more about \ref mimetypes
         */
        QString getMimeType() const;
        /*!
         * \param value New mime type of the animation.
         *
         * Refer to \ref mimetypes for more info
         */
        void setMimeType(const QString &value);

        /*!
         * \return the animation's file size.
         */
        qint64 getFileSize() const;
        /*!
         * \param value New file size of this animation
         */
        void setFileSize(const qint64 &value);
        
        /*!
         * \return thumbnail of the animation as a PhotoSize object.
         */
        PhotoSize getThumb() const;
        /*!
         * \param value New thumbnail of the animation.
         */
        void setThumb(const PhotoSize &value);
        
        //Flag getters
        bool hasFileId() const;

        bool hasWidth() const;

        bool hasHeight() const;
        bool hasDuration() const;
        
        bool hasFileName() const;
        
        bool hasMimeType() const;
        
        bool hasFileSize() const;
        
        bool hasThumb() const;
    };
}

#endif // ANIMATION_H
