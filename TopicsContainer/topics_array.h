#ifndef _TOPICS_ARRAY_H_
#define _TOPICS_ARRAY_H_

#include <ITopicsModule.h>

class TopicsArray:public ITopicsModule
{
private:
    TopicsArray(/* args */);

public:
    static TopicsArray &GetInstance()
    {
        static TopicsArray instance;
        return instance;
    }
    ~TopicsArray();

};

#endif
