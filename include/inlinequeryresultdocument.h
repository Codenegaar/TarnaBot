#ifndef INLINEQUERYRESULTDOCUMENT_H
#define INLINEQUERYRESULTDOCUMENT_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace Telegram
{
    class InlineQueryResultDocument : public InlineQueryResult
    {
    public:
        InlineQueryResultDocument();
        InlineQueryResultDocument(QJsonObject obj);
        
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
        
    private:
        QString title;
        QString caption;
        QString documentUrl;
        QString mimeType;
        QString description;
        QString thumbUrl;
        
        int thumbHeight;
        int thumbWidth;
        
        //Flags
        bool _hasTitle;
        bool _hasCaption;
        bool _hasDocumentUrl;
        bool _hasMimeType;
        bool _hasDescription;
        bool _hasThumbUrl;
        bool _hasThumbHeight;
        bool _hasThumbWidth;
    };
}
#endif // INLINEQUERYRESULTDOCUMENT_H
