#ifndef _LEETCODE_ROB_H__
#define _LEETCODE_ROB_H__

#include <iostream>
#include <vector>
#include "my_types.h"
#include <ISolution.h>
using namespace std;

class SolutionRob : public ISolution
{
public:
    SolutionRob(){}
    ~SolutionRob(){}
    void gap_rob(int beg,vector<int>& nums,int &cur_money,int &max_money);

    int rob(vector<int>& nums);
    
    void answer();
};


#endif
