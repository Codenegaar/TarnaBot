#ifndef FORCEREPLY_H
#define FORCEREPLY_H

#include "tarnaobject.h"

namespace TarnaBot
{
    class ForceReply : public TarnaObject
    {
    public:
        ForceReply(QJsonObject obj);
        ForceReply();
        
        static ForceReply fromObject(QJsonObject obj);
    
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
