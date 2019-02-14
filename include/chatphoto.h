#ifndef CHATPHOTO_H
#define CHATPHOTO_H

#include <QString>

#include "TelegramObject"

namespace Telegram
{
    /*!
     * @brief The ChatPhoto class represents a chat photo.
     */
    class ChatPhoto : public TelegramObject
    {
    public:
        ChatPhoto();
        /*!
         * \brief Creates a ChatPhoto object using a JSON object.
         * \param jsonObject The JSON object to construct the object with.
         */
        ChatPhoto(QJsonObject jsonObject);
        /*!
         * \brief Creates a ChatPhoto object using the required properties.
         * \param smallFileId Unique file identifier of small (160x160) chat photo.
         * \param bigFileId Unique file identifier of big (640x640) chat photo.
         * \sa ChatPhoto::getSmallFileId()
         * \sa ChatPhoto::getBigFileId()
         */
        ChatPhoto(QString smallFileId, QString bigFileId);
    
        //Getters/setters
        /*!
         * \brief getSmallFileId
         * \return Unique file identifier of small (160x160) chat photo.
         * This file_id can be used only for photo download.
         */
        QString getSmallFileId() const;
        void setSmallFileId(const QString &value);
        
        /*!
         * \brief getBigFileId
         * \return Unique file identifier of big (640x640) chat photo.
         * This file_id can be used only for photo download.
         */
        QString getBigFileId() const;
        void setBigFileId(const QString &value);
        
        //Flag getters
        bool hasSmallFileId() const;
        bool hasBigFileId() const;
    };
}
#endif // CHATPHOTO_H
