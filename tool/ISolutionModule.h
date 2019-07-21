#ifndef _I_SOLUTION_MODULE_H_
#define _I_SOLUTION_MODULE_H_

#include <vector>
#include "option.h"

class ISolutionModule
{
private:
    

    std::vector<Option *> solutions;

public:
    ISolutionModule(/* args */);
    virtual ~ISolutionModule();

    virtual void ShowAllSolutions();

    virtual void RegisterSoulution(Option *option);
};

#endif
