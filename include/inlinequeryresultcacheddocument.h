#ifndef INLINEQUERYRESULTCACHEDDOCUMENT_H
#define INLINEQUERYRESULTCACHEDDOCUMENT_H

#include "inlinequeryresult.h"

class InlineQueryResultCachedDocument : public InlineQueryResult
{
public:
    InlineQueryResultCachedDocument();
    InlineQueryResultCachedDocument(QJsonObject obj);
    
    //Getters/Setters
    QString getDocumentFileId() const;
    void setDocumentFileId(const QString &value);
    
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QString getCaption() const;
    void setCaption(const QString &value);
    
    QString getDescription() const;
    void setDescription(const QString &value);
    
    QString getParseMode() const;
    void setParseMode(const QString &value);
    
private:
    QString documentFileId;
    QString title;
    QString caption;
    QString description;
    QString parseMode;
};

#endif // INLINEQUERYRESULTCACHEDDOCUMENT_H
