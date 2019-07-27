#ifndef _I_TOPICS_MODULE_H_
#define _I_TOPICS_MODULE_H_

#include <vector>
#include "ISolutionItem.h"

class ITopicsModule
{
private:
    std::vector<ISolutionItem *> solutions;
public:
    ITopicsModule(/* args */);
    virtual ~ITopicsModule();

    virtual void ShowAnswer(int idx);

    virtual void ShowHelper();

    virtual void Loop();

    virtual void ShowAllSolutions();

    virtual void RegisterSoulution(ISolutionItem *solution);
};

#endif
