#ifndef INLINEQUERYRESULTDOCUMENT_H
#define INLINEQUERYRESULTDOCUMENT_H

#include <QVariant>

#include "InlineQueryResult"

namespace Telegram
{
    class InlineQueryResultDocument : public InlineQueryResult
    {
    public:
        InlineQueryResultDocument();
        InlineQueryResultDocument(QJsonObject jsonObject);
        InlineQueryResultDocument(QString id, QString title, QString documentUrl, QString mimeType);
        
        //Getters/Setters
        QString getTitle() const;
        void setTitle(const QString &value);
        
        QString getCaption() const;
        void setCaption(const QString &value);
        
        QString getDocumentUrl() const;
        void setDocumentUrl(const QString &value);
        
        QString getMimeType() const;
        void setMimeType(const QString &value);
        
        QString getDescription() const;
        void setDescription(const QString &value);
        
        QString getThumbUrl() const;
        void setThumbUrl(const QString &value);
        
        int getThumbHeight() const;
        void setThumbHeight(int value);
        
        int getThumbWidth() const;
        void setThumbWidth(int value);
        
        //Flag getters
        bool hasTitle() const;
        
        bool hasCaption() const;
        
        bool hasDocumentUrl() const;
        
        bool hasMimeType() const;
        
        bool hasDescription() const;
        
        bool hasThumbUrl() const;
        
        bool hasThumbHeight() const;
        
        bool hasThumbWidth() const;
    };
}
#endif // INLINEQUERYRESULTDOCUMENT_H
