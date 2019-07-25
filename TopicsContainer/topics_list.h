#ifndef _TOPICS_LIST_H_
#define _TOPICS_LIST_H_

#include <ITopicsModule.h>

class TopicsList:public ITopicsModule
{
private:
    TopicsList(/* args */);

public:
    static TopicsList &GetInstance()
    {
        static TopicsList instance;
        return instance;
    }
    ~TopicsList();

};

#endif
