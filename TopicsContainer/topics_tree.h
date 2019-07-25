#ifndef _TOPICS_TREE_H_
#define _TOPICS_TREE_H_

#include <ITopicsModule.h>

class TopicsTree:public ITopicsModule
{
private:
    TopicsTree(/* args */);

public:
    static TopicsTree &GetInstance()
    {
        static TopicsTree instance;
        return instance;
    }
    ~TopicsTree();

};

#endif
