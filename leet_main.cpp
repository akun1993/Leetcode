#include <string>
#include <iostream>
#include <memory>
#include <utility.h>
#include "topics_categorizer.h"

static  const char * leetcode = 
"           *********************************\n" 
"           ************LEETCODE*************\n"
"           ********Study And Practice*******\n"
"           **********Version 1.0.0**********\n"
"           ****题目来源:力扣(LeetCode)*******\n"
"  **** 链接：https://leetcode-cn.com/problems/*****\n"
;

void PrintStartInfo()
{
    std::cout << leetcode << std::endl;
}

int main(int argc,const char **argv)
{

    PrintStartInfo();

    std::shared_ptr<TopicsCatergorizer> topics = std::make_shared<TopicsCatergorizer>();
    topics->ShowAllTopics();
    topics->Loop();

    return 0;

}

