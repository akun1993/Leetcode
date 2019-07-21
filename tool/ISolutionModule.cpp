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
        std::cout << cnt << " " << info->name <<" " << info->level << std::endl;
        ++cnt;
    }
    
}

void ISolutionModule::RegisterSoulution(Option *option)
{
    solutions.push_back(option);
}
