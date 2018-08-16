#ifndef INLINEQUERYRESULTCACHEDDOCUMENT_H
#define INLINEQUERYRESULTCACHEDDOCUMENT_H

#include "InlineQueryResult"

namespace Telegram
{
    class InlineQueryResultCachedDocument : public InlineQueryResult
    {
    public:
        InlineQueryResultCachedDocument();
        InlineQueryResultCachedDocument(QJsonObject jsonObject);
        InlineQueryResultCachedDocument(QString id, QString title, QString documentFileId);
        
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
        
        //Flag getters
        bool hasDocumentFileId() const;
        
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasDescription() const;
        
        bool hasParseMode() const;
    };
}
#endif // INLINEQUERYRESULTCACHEDDOCUMENT_H
