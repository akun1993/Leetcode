#ifndef __TOPICS_CATEGORIZER_H_
#define __TOPICS_CATEGORIZER_H_

#include <my_types.h>
#include <string>

class ITopicsModule;
class ISolutionBase;

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

    struct TopicsInfo
    {
        TopicsInfo():used(false),name(""),module(nullptr){}
        bool            used;
        std::string     name;
        ITopicsModule  *module;

    };

    TopicsInfo topics[TOPICS_COUNT];
private:
    void RegisterTopics(ITopicsModule &topics_module,int topics_type,std::string name);
    void ShowHelper();
    void InitTopics();
public:
    TopicsCatergorizer(/* args */);
    ~TopicsCatergorizer(){}
    void ShowAllTopics( );
    void InitSolutions();
    void Loop( );

    void SolutionDistribute(ISolutionBase *solution, int count, ...);
    
};


#endif
