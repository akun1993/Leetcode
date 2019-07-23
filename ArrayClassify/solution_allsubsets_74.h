#ifndef __SOLUTION_ALL_SUBSETS_H_
#define __SOLUTION_ALL_SUBSETS_H_

#include <vector>
#include <ISolution.h>
using namespace std;
// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

// 说明：解集不能包含重复的子集。
class SolutionAllSubsets : public ISolution
{
public:
    //位运算，先计算集合的总数 为total 包含了空集， 而 [0 - total) 的非零bit 位的位置，就是数字在所给数组中的位置 
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;

        if(nums.size() == 0) return res;

        //但是不能超过32 个吧
        size_t total = 1 << nums.size();

        for(size_t i = 0;i < total ; ++i)
        {
            vector<int> sub;
            for (size_t j = i , k = 0; j > 0; j >>= 1,++k)
            {
                /* code */
                if(j & 1)
                {
                    sub.push_back(nums[k]);
                }
            }
            res.push_back(sub);
        }

        res.push_back(vector<int> ());

        return res ;
    }
    //迭代的方式，
    vector<vector<int>> subsetsII(vector<int>& nums)
    {
        vector<vector<int>> res;

        res.push_back(vector<int> ());
        for (size_t i = 0; i < nums.size(); i++)
        {
            /* code */
            size_t res_size = res.size();
            for (size_t j = 0; j < res_size; j++)
            {
                /* code */
                vector<int> sub;
                sub = res[j];

                sub.push_back(nums[i]);

                res.push_back(sub);
            }
            //res.push_back(sub);

        }

        return res;

    }

    void recursive(int idx,vector<int>& nums,vector<int>& sub,vector<vector<int>> & res)
    {
        res.push_back(sub);

        for (size_t i = idx; i < nums.size(); i++)
        {
            /* code */
            sub.push_back(nums[i]);
            recursive(i + 1,nums,sub,res);
            sub.pop_back();
        }
    }

    //

    vector<vector<int>> subsetsIII(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> sub;
        recursive(0,nums,sub,res);
        return res;
    }    

    vector<vector<int>> subsetsIIII(vector<int>& nums)
    {
        vector<vector<int>> res;
        
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            vector<int> sub;
            sub.push_back(nums[i]);
            res.push_back(sub);
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                sub.push_back(nums[j]);
                res.push_back(sub);
                /* code */
            }
            /* code */
        }

        return res;
    }  

    void answer()
    {
        vector<int> nums = {1,2,3,4,5};

        vector<vector<int>> ret = subsetsIIII(nums);

        for (size_t i = 0; i < ret.size(); i++)
        {
            /* code */
            for (size_t j = 0; j < ret[i].size(); j++)
            {
                /* code */
                cout << ret[i][j] << " ";
            }
             cout << endl;
        }
        

    }

};

#endif
