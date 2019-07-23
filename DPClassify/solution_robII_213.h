
#ifndef __SOLUTION_ROB_H_
#define __SOLUTION_ROB_H_

#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <ISolution.h>
using namespace std;

class SolutionRobII : public ISolution
{
public:
    SolutionRobII(){}
    ~SolutionRobII(){}
    int rob(vector<int>& nums);

    int rob2(vector<int>& nums);

    void answer();

};

#endif

