
#ifndef __SOLUTION_COMBINATION_SUM_H_
#define __SOLUTION_COMBINATION_SUM_H_

#include <ISolution.h>
#include <iostream>
using namespace std;

// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的数字可以无限制重复被选取。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combination-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class SolutionCombinbationSum : public ISolution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;

        if(candidates.empty()) return res;    
        
        int cand_cnt = candidates.size();

        vector<int> nums(cand_cnt,0);
        
        for(int i = 0; i < cand_cnt;++i)
        {
            int idx = 0;
            nums[0] = 0;
            while(true)
            {
                bool flag = true;
                int sum = 0;
                for(int k = 0; k < idx; ++k)
                {
                    if(nums[k] > nums[idx])
                    {
                        flag = false;
                        break;
                    }
                    sum += candidates[nums[k]];
                }
                if(sum + candidates[nums[idx]] > target) break;
                if(flag && idx == i && target == sum + candidates[nums[idx]])
                {
                    vector<int> new_res;
                    for (int j = 0; j <= i; j++)
                    {
                        new_res.push_back(candidates[nums[j]]);
                    } 
                    res.push_back(new_res);
                }

                if(idx < i)
                {
                    ++idx;
                    nums[idx] = 0;
                    continue;
                }

                while(i > 0 && nums[i] >= cand_cnt - 1)
                {
                    --i;
                }
                if(idx < 0)
                    break;
                else
                    ++nums[idx];
            }    
        }
        
        return res;
    }

    void answer()
    {

    }

};

#endif
