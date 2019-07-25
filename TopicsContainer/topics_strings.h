#ifndef _TOPICS_STRINGS_H_
#define _TOPICS_STRINGS_H_

#include <ITopicsModule.h>

class TopicsStrings:public ITopicsModule
{
private:
    TopicsStrings(/* args */);

public:
    static TopicsStrings &GetInstance()
    {
        static TopicsStrings instance;
        return instance;
    }
    ~TopicsStrings();

};

#endif
