#include "ITopicsModule.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <utility.h>

using namespace std;

ITopicsModule::ITopicsModule(/* args */)
{

}

ITopicsModule::~ITopicsModule()
{

}

void ITopicsModule::ShowAllSolutions()
{
    int cnt = 1;
    for (auto &info : solutions)
    {
        info->problemInfo();
        ++cnt;
    }
}

void ITopicsModule::ShowHelper()
{
    static const char *helper = "输入题目序号选择题目\n"
                                "输入q返回上一级\n";

    cout << helper;
}

void ITopicsModule::Loop()
{
    std::string  str;
    if(solutions.empty()) 
    {
        cout << "当前题库中没有题目,输入任意键继续" << endl;
        getch();
        getch();
        return;
    }
    while(cin >> str)
    {
        if(str == "q")
        {
            break;
        }

        int idx = atoi(str.c_str());

        if(idx > 0 && idx <= (int)solutions.size())
        {
            ShowAnswer(idx - 1);
        }
        else
        {
            ShowHelper();
        }
        ShowAllSolutions();
    }
    return ;

}


void ITopicsModule::ShowAnswer(int idx)
{
    if(idx < 0 || idx >=  (int) solutions.size())
    {
        std::cout << "No Question " << idx << " Check Your Input." << std::endl;
        return;
    }
    solutions[idx]->answer();
}

void ITopicsModule::RegisterSoulution(ISolutionItem *solution)
{
    if(solution) solutions.push_back(solution);
}
