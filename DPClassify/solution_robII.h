
#ifndef __SOLUTION_ROB_H_
#define __SOLUTION_ROB_H_

#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <ISolutionBase.h>
using namespace std;

class SolutionRobII : public ISolutionBase
{
public:
    SolutionRobII(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionRobII(){}
    int rob(vector<int>& nums);

    int rob2(vector<int>& nums);

    void answer();

};

#endif

