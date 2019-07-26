#include "topics_categorizer.h"
#include <ITopicsModule.h>
#include <memory.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "topics_array.h"
#include "topics_dynamic.h"
#include "topics_list.h"
#include "topics_strings.h"
#include "topics_tree.h"

#include "solution_strings.h"
#include "solution_lists.h"
#include "solution_trees.h"
#include "solution_dynamics.h"
#include "solution_arrays.h"

using namespace std;

TopicsCatergorizer::TopicsCatergorizer()
{
    InitTopics();
}

void TopicsCatergorizer::InitTopics()
{
    ITopicsModule &topics_string = static_cast<ITopicsModule &> (TopicsStrings::GetInstance());
    RegisterTopics(topics_string,STRING_TOPICS,"字符串");

    ITopicsModule &topics_list = static_cast<ITopicsModule &> (TopicsList::GetInstance());
    RegisterTopics(topics_list,LIST_TOPICS,"链表");

    ITopicsModule &topics_tree = static_cast<ITopicsModule &> (TopicsTree::GetInstance());
    RegisterTopics(topics_tree,TREE_TOPICS,"树");

    ITopicsModule &topics_array = static_cast<ITopicsModule &> (TopicsArray::GetInstance());
    RegisterTopics(topics_array,ARRAY_TOPICS,"数组");

    ITopicsModule &dynamic= static_cast<ITopicsModule &> (TopicsDynamic::GetInstance());
    RegisterTopics(dynamic,DYNAMIC_TOPICS,"动态规划");

}

void TopicsCatergorizer::RegisterTopics(ITopicsModule &topics_module,int topics_type,std::string name)
{
    if(topics_type < 0 || topics_type >= TOPICS_COUNT)
    {
        cout << "Can Not Recognition Topics Type " << topics_type << endl;
        return;
    }
    if(topics[topics_type].used != false)
    {
        cout << "Topics Type " << topics_type << " has been register"<< endl;
        return;
    }
    topics[topics_type].used = true;
    topics[topics_type].name = name;
    topics[topics_type].module = &topics_module;
}


void TopicsCatergorizer::ShowAllTopics( )
{
    cout << "*******题目类型*******" << endl; 
    for(int i = 0; i < TOPICS_COUNT; ++i)
    {
        if(topics[i].used)
        {
            cout << i + 1 << "、" << topics[i].name << endl;
        }
    }
    cout << "请选择题目类型: ";
}

void TopicsCatergorizer::ShowHelper()
{
    static const char *helper = "输入类型序号选择题目类型\n"
                                "输入q退出\n";

    cout << helper;
}



void TopicsCatergorizer::Loop( )
{
    static  std::string  str;
    while(cin >> str)
    {
        if(str == "q")
        {
            break;
        }

        int idx = atoi(str.c_str());

        if(idx > 0 && idx <= TOPICS_COUNT)
        {
            if(topics[idx - 1].module)
            {
                topics[idx - 1].module->ShowAllSolutions();
                topics[idx - 1].module->Loop();
            }
        }
        else
        {
            ShowHelper();
        }
        ShowAllTopics();
    }
    return ;
}


void TopicsCatergorizer::InitSolutions()
{


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
            topics[idx].module->RegisterSoulution(solution);
        }
    }
    va_end(args);
}


