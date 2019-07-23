#ifndef _SOLUTION_STRINGS_H_
#define _SOLUTION_STRINGS_H_

#include <ISolutionModule.h>
#include "solution_stringexist_79.h"

class SolutionStrings:public ISolutionModule
{
private:
    SolutionStrings(/* args */);

public:
    static SolutionStrings &GetInstance()
    {
        static SolutionStrings instance;
        return instance;
    }
    ~SolutionStrings();

};

#endif
