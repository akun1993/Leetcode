#ifndef __TOPICS_CATEGORIZER_H_
#define __TOPICS_CATEGORIZER_H_

#include <my_types.h>

class ITopicsModule;

class TopicsCatergorizer
{

private:
    /* data */
    enum TOPICS_TYPES
    {
        ARRAY_TOPICS,
        STRING_TOPICS,
        TREE_TOPICS,
        LIST_TOPICS,
        DYNAMIC_TOPICS,
        TOPICS_COUNT,
    };
    ITopicsModule *topics[TOPICS_COUNT];
private:
    void SolutionDistribute(ISolutionBase *solution,u32 flag);
    void InitTopics();
public:
    TopicsCatergorizer(/* args */);
    ~TopicsCatergorizer(){}
};


#endif
