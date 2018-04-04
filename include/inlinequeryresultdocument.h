#ifndef INLINEQUERYRESULTDOCUMENT_H
#define INLINEQUERYRESULTDOCUMENT_H

#include <QVariant>
#include "inlinequeryresult.h"

namespace TarnaBot
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
        bool getHasTitle() const;
        
        bool getHasCaption() const;
        
        bool getHasDocumentUrl() const;
        
        bool getHasMimeType() const;
        
        bool getHasDescription() const;
        
        bool getHasThumbUrl() const;
        
        bool getHasThumbHeight() const;
        
        bool getHasThumbWidth() const;
        
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
        bool hasTitle;
        bool hasCaption;
        bool hasDocumentUrl;
        bool hasMimeType;
        bool hasDescription;
        bool hasThumbUrl;
        bool hasThumbHeight;
        bool hasThumbWidth;
    };
}
#endif // INLINEQUERYRESULTDOCUMENT_H
