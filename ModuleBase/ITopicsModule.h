#ifndef _I_TOPICS_MODULE_H_
#define _I_TOPICS_MODULE_H_

#include <vector>
#include "ISolutionBase.h"

class ITopicsModule
{
private:
    std::vector<ISolutionBase *> solutions;
public:
    ITopicsModule(/* args */);
    virtual ~ITopicsModule();

    void ShowAnswer(int idx);

    virtual void ShowAllSolutions();

    virtual void RegisterSoulution(ISolutionBase *solution);
};

#endif
