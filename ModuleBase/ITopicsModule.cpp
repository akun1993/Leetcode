#include "ITopicsModule.h"
#include <iostream>

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
void ITopicsModule::ShowAnswer(int idx)
{
    if(idx < 0 || idx >=  (int) solutions.size())
    {
        std::cout << "No Question " << idx << " Check Your Input." << std::endl;
        return;
    }
    solutions[idx]->answer();
}

void ITopicsModule::RegisterSoulution(ISolutionBase *solution)
{
    if(solution) solutions.push_back(solution);
}
