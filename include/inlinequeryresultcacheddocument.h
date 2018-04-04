#ifndef INLINEQUERYRESULTCACHEDDOCUMENT_H
#define INLINEQUERYRESULTCACHEDDOCUMENT_H

#include "inlinequeryresult.h"

namespace Telegram
{
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
        
        //Flag getters
        bool getHasDocumentFileId() const;
        
        bool getHasTitle() const;
        
        bool getHasCaption() const;
        
        bool getHasDescription() const;
        
        bool getHasParseMode() const;
        
    private:
        QString documentFileId;
        QString title;
        QString caption;
        QString description;
        QString parseMode;
        
        //Flags
        bool hasDocumentFileId;
        bool hasTitle;
        bool hasCaption;
        bool hasDescription;
        bool hasParseMode;
    };
}
#endif // INLINEQUERYRESULTCACHEDDOCUMENT_H
