#ifndef INLINEQUERYRESULTARTICLE_H
#define INLINEQUERYRESULTARTICLE_H

#include <QJsonObject>
#include <QString>

#include "inputcontactmessagecontent.h"
#include "inputlocationmessagecontent.h"
#include "inputtextmessagecontent.h"
#include "inputvenuemessagecontent.h"
#include "inlinekeyboardmarkup.h"

class InlineQueryResultArticle
{
public:
    InlineQueryResultArticle();
    InlineQueryResultArticle(QJsonObject obj);
    
    static InlineQueryResultArticle fromObject(QJsonObject obj);
    QJsonObject toObject();
    
private:
    QString type;
    QString id;
    QString title;
    QString url;
    QString description;
    QString thumbUrl;
    
    int thumbWidth;
    int thumbHeight;
    bool hideUrl;
    
    InputMessageContent inputMessageContent;
    InlineKeyboardMarkup replyMarkup;
    
    QJsonObject root;
};

#endif // INLINEQUERYRESULTARTICLE_H
