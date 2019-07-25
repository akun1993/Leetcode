#include "topics_categorizer.h"
#include <ITopicsModule.h>
#include <memory.h>
#include <stdarg.h>
#include <iostream>
#include "topics_array.h"
#include "topics_dynamic.h"
#include "topics_list.h"
#include "topics_strings.h"
#include "topics_tree.h"

using namespace std;

TopicsCatergorizer::TopicsCatergorizer()
{
    memset(topics,0,sizeof(topics));
    InitTopics();
}

void TopicsCatergorizer::InitTopics()
{
    ITopicsModule &topics_string = static_cast<ITopicsModule &> (TopicsStrings::GetInstance());
    RegisterTopics(topics_string,STRING_TOPICS);

    ITopicsModule &topics_list = static_cast<ITopicsModule &> (TopicsList::GetInstance());
    RegisterTopics(topics_list,LIST_TOPICS);

    ITopicsModule &topics_tree = static_cast<ITopicsModule &> (TopicsTree::GetInstance());
    RegisterTopics(topics_tree,TREE_TOPICS);

    ITopicsModule &topics_array = static_cast<ITopicsModule &> (TopicsArray::GetInstance());
    RegisterTopics(topics_array,ARRAY_TOPICS);

    ITopicsModule &dynamic= static_cast<ITopicsModule &> (TopicsDynamic::GetInstance());
    RegisterTopics(dynamic,DYNAMIC_TOPICS);

}

void TopicsCatergorizer::RegisterTopics(ITopicsModule &topics_module,int topics_type)
{
    if(topics_type < 0 || topics_type >= TOPICS_COUNT)
    {
        cout << "Can Not Recognition Topics Type " << topics_type << endl;
        return;
    }
    if(topics[topics_type] != 0)
    {
        cout << "Topics Type " << topics_type << " has been register"<< endl;
        return;
    }

    topics[topics_type] = &topics_module;
}



void TopicsCatergorizer::SolutionDistribute(ISolutionBase *solution,int count,...)
{
    if(solution == nullptr) return;

    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        /* code */
        unsigned int idx = va_arg(args, unsigned int);

        if (idx < TOPICS_COUNT)
        {
            topics[idx]->RegisterSoulution(solution);
        }
    }
    va_end(args);
}


