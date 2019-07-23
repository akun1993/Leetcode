#ifndef _LEETCODE_ROB_H__
#define _LEETCODE_ROB_H__

#include <iostream>
#include <vector>
#include <ISolution>
#include "my_types.h"
using namespace std;

class SolutionRob : public ISolutionBase
{
public:
    SolutionRob(){}
    ~SolutionRob(){}
    void gap_rob(int beg,vector<int>& nums,int &cur_money,int &max_money);

    int rob(vector<int>& nums);
    
    void answer();
};


#endif
