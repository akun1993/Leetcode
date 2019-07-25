#ifndef _TOPICS_DYNAMIC_H_
#define _TOPICS_DYNAMIC_H_

#include <ITopicsModule.h>

class TopicsDynamic:public ITopicsModule
{
private:
    TopicsDynamic(/* args */);

public:
    static TopicsDynamic &GetInstance()
    {
        static TopicsDynamic instance;
        return instance;
    }
    ~TopicsDynamic();

};

#endif
