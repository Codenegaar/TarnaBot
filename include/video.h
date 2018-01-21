#ifndef VIDEO_H
#define VIDEO_H
#include <QJsonObject>
#include <QString>
#include <QVariant>

#include "photosize.h"

class Video
{
public:
    Video(QJsonObject obj);
    Video();
    
    static Video fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    QString getFileId() const;
    void setFileId(const QString &value);
    
    QString getMimeType() const;
    void setMimeType(const QString &value);
    
    int getHeight() const;
    void setHeight(const int &value);
    
    int getWidth() const;
    void setWidth(const int &value);
    
    qint64 getDuration() const;
    void setDuration(const qint64 &value);
    
    qint64 getFileSize() const;
    void setFileSize(const qint64 &value);
    
    PhotoSize getThumb() const;
    void setThumb(const PhotoSize &value);
    
private:
    QString fileId;
    QString mimeType;
    
    int height;
    int width;
    qint64 duration;
    qint64 fileSize;
    
    PhotoSize thumb;
    
    QJsonObject root;
};

#endif // VIDEO_H
