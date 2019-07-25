#include "topics_categorizer.h"
#include <memory.h>
#include "topics_array.h"
#include "topics_dynamic.h"
#include "topics_list.h"
#include "topics_strings.h"
#include "topics_tree.h"
#include <iostream>
using namespace std;

TopicsCatergorizer::TopicsCatergorizer()
{
    memset(topics,0,sizeof(topics));
    InitTopics();
}

void TopicsContainer::InitTopics()
{
    ITopicsModule &topics_string = static_cast<ITopicsModule &> (TopicsStrings::GetInstance());
    RegisterTopics(topics_string,STRING_TOPICS);

    ITopicsModule &topics_list = static_cast<ITopicsModule &> (TopicsList::GetInstance());
    RegisterTopics(topics_list,LIST_TOPICS);

    ITopicsModule &topics_tree = static_cast<ITopicsModule &> (TopicsTree::GetInstance());
    RegisterTopics(topics_tree,TREE_TOPICS);

    TopicsModule &topics_array = static_cast<ITopicsModule &> (TopicsArray::GetInstance());
    RegisterTopics(topics_array,ARRAY_TOPICS);

    ITopicsModule &dynamic= static_cast<ITopicsModule &> (TopicsDynamic::GetInstance());
    RegisterTopics(dynamic,DYNAMIC_TOPICS);

}

void TopicsContainer::RegisterTopics(ITopicsModule &topics_module,int topics_type)
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



void TopicsContainer::SolutionDistribute(ISolutionBase *solution,u32 )
{
    if(solution == nullptr) return;

    topics[idx].RegisterSoulution(solution);

}



