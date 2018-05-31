#ifndef INLINEQUERYRESULT_H
#define INLINEQUERYRESULT_H

#include <QString>

#include "inputmessagecontent.h"
#include "inputtextmessagecontent.h"
#include "inputlocationmessagecontent.h"
#include "inputvenuemessagecontent.h"
#include "inputcontactmessagecontent.h"
#include "inlinekeyboardmarkup.h"
#include "tarnaobject.h"

namespace Telegram
{
    class InlineQueryResult : public TarnaObject
    {
    public:
        InlineQueryResult();
        InlineQueryResult(QJsonObject obj);
        
        //Getters/Setters
        QString getType() const;
        void setType(const QString &value);
        
        QString getId() const;
        void setId(const QString &value);
        
        InputMessageContent *getInputMessageContent() const;
        void setInputMessageContent(InputMessageContent *value);
        
        InlineKeyboardMarkup getReplyMarkup() const;
        void setReplyMarkup(const InlineKeyboardMarkup &value);
        
        //Flag getters
        bool hasType() const;
        
        bool hasId() const;
        
        bool hasInputMessageContent() const;
        
        bool hasReplyMarkup() const;
        
    protected:
        QString type;
        QString id;
        
        InputMessageContent *inputMessageContent;
        InlineKeyboardMarkup replyMarkup;
        
        //Flags
        bool _hasType;
        bool _hasId;
        bool _hasInputMessageContent;
        bool _hasReplyMarkup;
    };
}
#endif // INLINEQUERYRESULT_H
