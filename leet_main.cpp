#include <string>
#include <iostream>
#include "StringClassify/solution_strings.h"

static  const char * leetcode = 
"           *********************************\n" 
"           ************LEETCODE*************\n"
"           ***********Author ZKun***********\n"
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

    SolutionStrings &str = SolutionStrings::GetInstance();
    str.ShowAnswer(0);

     return 0;

}

