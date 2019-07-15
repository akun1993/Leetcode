#ifndef __TOP_K_FREQUENT_
#define __TOP_K_FREQUENT_

#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "my_types.h"

// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

// 示例 1:

// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
// 示例 2:

// 输入: nums = [1], k = 1
// 输出: [1]
// 说明：

// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

class SolutiontopkFrequent
{

public:
    vector<int> topKFrequentII(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty() || k <= 0) return res;
                
        unordered_map<int,int> hash;
        
        int frequent_next = 0;
        for(u32 i = 0; i < nums.size(); ++i)
        {
            if(hash.count(nums[i]) == 0)
                hash[nums[i]] = 1;
            else
                ++hash[nums[i]];
        }
        
        
        frequent_next = nums.size();
        for(int i = 0; i < k;++i)
        {
            int min = 0;
            int key ;
           
            unordered_map<int,int>::iterator iter = hash.begin();
            for(;iter != hash.end(); ++iter  )
            {
                if(frequent_next >= iter->second && iter->second > min)
                {
                   min = iter->second;
                   key = iter->first;
                }                
            }
            
            hash.erase(key);
            
            frequent_next = min;
            
            res.push_back(key);
        }

        return res;
    }

    struct cmp_s
    {
        bool operator() (const pair<int,int> &left,const pair<int,int> &right)
        {
            return left.second > right.second;
        }
    }  cmp_t;
        
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty() || k <= 0) return res;
                
        unordered_map<int,int> hash;

        for(u32 i = 0; i < nums.size(); ++i)
        {
            ++hash[nums[i]];
        }
        
        vector< pair<int,int> > vec(hash.begin(),hash.end());
        

        sort(vec.begin(),vec.end(),cmp_t);

        for (int i = 0; i < k; i++)
        {
            /* code */
            res.push_back(vec[i].first);
        }
        
      
        return res;
    }  
    
    void answer()
    {

        vector<int> case_1 = {1,1,1,2,2,3};
        
        vector<int> res = topKFrequent(case_1,2);
        for (u32 i = 0; i < res.size(); i++)
        {
            /* code */
            cout << res[i] << ",";
        }
        cout << endl ;  

    }
};


#endif
