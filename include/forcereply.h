#ifndef FORCEREPLY_H
#define FORCEREPLY_H

#include "replymarkup.h"

namespace Telegram
{
    class ForceReply : public ReplyMarkup
    {
    public:
        ForceReply(QJsonObject obj);
        ForceReply();
    
        //Getters/setters
        bool getForceReply() const;
        void setForceReply(bool value);
        
        bool getSelective() const;
        void setSelective(bool value);
        
    private:
        bool forceReply = true;
        bool selective;
    };
}
#endif // FORCEREPLY_H
