#ifndef INLINEQUERYRESULTARTICLE_H
#define INLINEQUERYRESULTARTICLE_H

#include <QJsonObject>
#include <QString>
#include <QVariant>

#include "inputmessagecontent.h"
#include "inlinekeyboardmarkup.h"

class InlineQueryResultArticle
{
public:
    InlineQueryResultArticle();
    InlineQueryResultArticle(QJsonObject obj);
    
    static InlineQueryResultArticle fromObject(QJsonObject obj);
    QJsonObject toObject();
    
    //Getters/Setters
    QString getType() const;
    void setType(const QString &value);
    
    QString getId() const;
    void setId(const QString &value);
    
    QString getTitle() const;
    void setTitle(const QString &value);
    
    QString getUrl() const;
    void setUrl(const QString &value);
    
    QString getDescription() const;
    void setDescription(const QString &value);
    
    QString getThumbUrl() const;
    void setThumbUrl(const QString &value);
    
    int getThumbWidth() const;
    void setThumbWidth(int value);
    
    int getThumbHeight() const;
    void setThumbHeight(int value);
    
    bool getHideUrl() const;
    void setHideUrl(bool value);
    
    InlineKeyboardMarkup getReplyMarkup() const;
    void setReplyMarkup(const InlineKeyboardMarkup &value);
    
    InputMessageContent getInputMessageContent() const;
    void setInputMessageContent(const InputMessageContent &value);
    
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
    
    InlineKeyboardMarkup replyMarkup;
    InputMessageContent inputMessageContent;
    
    QJsonObject root;
};

#endif // INLINEQUERYRESULTARTICLE_H
