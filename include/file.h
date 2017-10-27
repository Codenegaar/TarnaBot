#ifndef FILE_H
#define FILE_H
///
#include <QJsonObject>
#include <QString>
#include <QVariant>

class File
{
public:
    File(QJsonObject obj);
    File();
    
    static File fromObject(QJsonObject obj);
    QJsonObject toObject();

    //Getters/setters
    
    QString getFileId() const;
    void setFileId(const QString &value);
    
    QString getFilePath() const;
    void setFilePath(const QString &value);
    
    qint64 getFileSize() const;
    void setFileSize(const qint64 &value);
    
private:
    QString fileId;
    QString filePath;
    qint64 fileSize;
    
    QJsonObject root;
};

#endif // FILE_H
