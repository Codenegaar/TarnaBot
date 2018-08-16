#ifndef FORCEREPLY_H
#define FORCEREPLY_H

#include "ReplyMarkup"

namespace Telegram
{
    class ForceReply : public ReplyMarkup
    {
    public:
        ForceReply();
        ForceReply(QJsonObject jsonObject);
    
        //Getters/setters
        bool getForceReply() const;
        void setForceReply(bool value);
        
        bool getSelective() const;
        void setSelective(bool value);
    };
}
#endif // FORCEREPLY_H
