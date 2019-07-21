#ifndef __I_SOLUTION_BASE_
#define __I_SOLUTION_BASE_

#include <memory.h>
#include <iostream>

class ISolutionBase
{

public:
    enum Difficulty
    {
        EASY_LV,
        NORMAL_LV,
        HARD_LV,
        COUNT_LV,
    };
    ISolutionBase(
        const char *name,
        const char * problem_desc,
        int number,
        Difficulty lv,
        unsigned int flag
    ): name(name), problem_desc(problem_desc), number(number), level(lv), flags(flag) 
    {
       memset(solution_desc, 0, sizeof(solution_desc));
    }

    virtual void problemInfo()
    {
        std::cout << level << " " << name <<" " << problem_desc << std::endl;
    }

    virtual ~ISolutionBase() {}

    virtual void answer() = 0;

private:
    static const int MAX_SOLUTION = 3;

    /* data */
    const char * name; /* name of the option */
    const char * problem_desc;
    char       * solution_desc[MAX_SOLUTION];
    int          number;
    Difficulty   level;
    unsigned int flags;    


};

#endif
