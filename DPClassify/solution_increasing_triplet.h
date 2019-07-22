
#ifndef _LEET_INCREASING_TRIPLET_H__
#define _LEET_INCREASING_TRIPLET_H__

#include <string>
#include <iostream>
#include <vector>
#include "my_types.h"
#include <ISolutionBase.h>

using namespace std;

// 给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。

// 数学表达式如下:

// 如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
// 使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

class SolutionTriplet : public ISolutionBase
{
public:

    SolutionTriplet(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionTriplet(){}

    bool increasingTriplet(vector<int>& nums) ;
    void answer();

};

#endif

