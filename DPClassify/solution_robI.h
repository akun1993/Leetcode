#ifndef _LEETCODE_ROB_H__
#define _LEETCODE_ROB_H__

#include <iostream>
#include <vector>
#include <ISolutionBase.h>
#include "my_types.h"
using namespace std;

class SolutionRob : public ISolutionBase
{
public:
    SolutionRob(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionRob(){}
    void gap_rob(int beg,vector<int>& nums,int &cur_money,int &max_money);

    int rob(vector<int>& nums);
    
    void answer();
};


#endif
