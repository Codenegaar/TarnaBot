#ifndef AUDIO_H
#define AUDIO_H
#include <QJsonObject>
#include <QString>
#include <QVariant>
//
class Audio
{
public:
    Audio(QJsonObject obj);
    Audio();
    static Audio fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    
    QString getFileId() const;
    void setFileId(const QString &value);
    
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
    
private:
    QString fileId;
    QString performer;
    QString title;
    QString mimeType;
    
    qint64 duration;
    qint64 fileSize;
    
    QJsonObject root;
};

#endif // AUDIO_H
