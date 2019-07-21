#include "ISolutionModule.h"

#include <iostream>

ISolutionModule::ISolutionModule(/* args */)
{

}

ISolutionModule::~ISolutionModule()
{

}

void ISolutionModule::ShowAllSolutions()
{
    int cnt = 1;
    for (auto &info : solutions)
    {
        info->problemInfo();
        ++cnt;
    }
    
}
void ISolutionModule::ShowAnswer(int idx)
{
    if(idx < 0 || idx >=  (int) solutions.size())
    {
        std::cout << "No Question " << idx << " Check Your Input." << std::endl;
        return;
    }
    solutions[idx]->answer();
}

void ISolutionModule::RegisterSoulution(ISolutionBase *solution)
{
    if(solution) solutions.push_back(solution);
}
