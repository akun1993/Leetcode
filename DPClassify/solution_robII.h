
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
    int rob(vector<int>& nums);

    int rob2(vector<int>& nums);

    void answer();

};

#endif

