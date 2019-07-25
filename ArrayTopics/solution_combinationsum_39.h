
#ifndef __SOLUTION_COMBINATION_SUM_H_
#define __SOLUTION_COMBINATION_SUM_H_

#include <ISolution.h>
#include <iostream>
using namespace std;

class SolutionCombinbationSum : public ISolution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;

        if(candidates.empty()) return res;    
        
        int cand_cnt = candidates.size();

        vector<int> nums(cand_cnt,0);
        
        for(size_t i = 0; i < cand_cnt;++i)
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
                    for (size_t j = 0; j <= i; j++)
                    {
                        /* code */
                        cout << nums[j] << " ";
                    }
                    cout << endl;
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
        
    }



};

#endif
