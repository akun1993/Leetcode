
#ifndef _LEET_INCREASING_TRIPLET_H__
#define _LEET_INCREASING_TRIPLET_H__

#include <string>
#include <iostream>
#include <vector>
#include "my_types.h"

using namespace std;

// 给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。

// 数学表达式如下:

// 如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
// 使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。


class SolutionTriplet {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        if(nums.size() < 3) return false;
        
        int a = nums[0];
        
        int b = nums[1];
        
        
        for(u32 i = 2; i < nums.size();++i)
        {
            if(a < b && b < nums[i]) return true;
            
            if(a > nums[i] && b < nums[i])
            {
                a = b;
                b = nums[i];
            }
            
            if(nums[i] > a && nums[i] < b )
            {
                b = nums[i];
            }
            
            if(a > b && nums[i] > a)
            {
                a = b;
                b = nums[i];
            }
        }
        
         a = nums[nums.size() - 1];
        
         b = nums[nums.size() - 2];
        
        for(int i = (int)nums.size() - 3; i >= 0 ;--i)
        {
            if(a > b && b > nums[i]) return true;
            
            if(a < nums[i] && b > nums[i])
            {
                a = b;
                b = nums[i];
            }
            
            if(nums[i] < a && nums[i] > b )
            {
                b = nums[i];
            }
            
            if(a < b && nums[i] < a)
            {
               	a = b;
                b = nums[i];
            }
        }
        return false;
        
    }
    void answer()
    {


        vector<int> test = {1,2,1,7,9,2,4,5};

        increasingTriplet(test);

    }

};

#endif

