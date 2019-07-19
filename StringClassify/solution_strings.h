#ifndef _SOLUTION_STRINGS_H_
#define _SOLUTION_STRINGS_H_

#include <vector>
#include "option.h"

class SolutionStrings
{
private:
    std::vector<Option> solutions;

public:
    SolutionStrings(/* args */);
    ~SolutionStrings();

    void ShowAllSolutions();

    void RegisterSoulution(Option &option);
};

#endif
