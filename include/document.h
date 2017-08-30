#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <QJsonObject>
#include <QString>
#include <QVariant>

#include "photosize.h"

class Document
{
public:
    Document(QJsonObject obj);
    Document();
    static Document fromObject(QJsonObject obj);
    
private:
    QString fileId;
    QString fileName;
    QString mimeType;
    
    qint64 fileSize;
    
    PhotoSize thumb;
    
    QJsonObject root;
};

#endif // DOCUMENT_H
