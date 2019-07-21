#ifndef _SOLUTION_STRINGS_H_
#define _SOLUTION_STRINGS_H_

#include "../tool/ISolutionModule.h"

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
