#ifndef __OPTION_H__
#define __OPTION_H__

#include <memory.h>

class Option
{
public:
    enum Difficulty
    {
        EASY_LV,
        NORMAL_LV,
        HARD_LV,
        COUNT_LV,
    };

    Option() : name(0), addr(0), problem_desc(0), number(-1), level(EASY_LV), flags(0) 
    {
        memset(solution_desc, 0, sizeof(solution_desc));
    }
    ~Option();
    static const int MAX_SOLUTION = 3;

    char       * name; /* name of the option */
    void       * addr;
    char       * problem_desc;
    char       * solution_desc[MAX_SOLUTION];
    int          number;
    Difficulty   level;
    unsigned int flags;
};

#endif
