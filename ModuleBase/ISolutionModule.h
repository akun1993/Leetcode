#ifndef _I_SOLUTION_MODULE_H_
#define _I_SOLUTION_MODULE_H_

#include <vector>
#include "ISolutionBase.h"

class ISolutionModule
{
private:
    std::vector<ISolutionBase *> solutions;
public:
    ISolutionModule(/* args */);
    virtual ~ISolutionModule();

    void ShowAnswer(int idx);

    virtual void ShowAllSolutions();

    virtual void RegisterSoulution(ISolutionBase *solution);
};

#endif
