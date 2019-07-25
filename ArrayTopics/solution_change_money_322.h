#ifndef __SOLUTION_CHANGE_MONEY_
#define __SOLUTION_CHANGE_MONEY_

//整币兑零

#include <vector>
#include <ISolution.h>
#include <iostream>
using namespace std;

class SolutionChangeMoney : public ISolution
{
    public:
    
    int changemoney(vector<int> &moneys,int sum)
    {
        
        vector<vector<int>> dp(moneys.size() ,vector<int> (sum + 1,0)); 

        for (int i = 0; i <= sum; i++)
        {
            /* code */
            if( i % moneys[0] == 0 )
            {
                dp[0][i] = 1;
            }
            else
            {
                dp[0][i] = 0;
            }
        }
        int s = dp[0][sum];
        for (size_t i = 1; i < moneys.size(); i++)
        {
            /* code */
            for (size_t j = moneys[i]; j <= (size_t)sum; j++)
            {
                int total = 0; 
                int left = j - moneys[i] ;
                for(size_t  k = 0; k <= i; ++k)
                {
                    total += dp[k][left];
                }
                dp[i][j] = total;
            }
            s += dp[i][sum];
        }
        return s;

    }

    int changemoneyII(vector<int> &x,int money)
    {
        long int a[12][1001];   

        int n = money;
        int m = x.size() -1;
        for(int i = 0; i <= n;++i )
        {
            if( i % x[1] == 0)
                a[1][i] = 1;
            else
            {
                a[1][i] = 0;
            }
        }
        int s = a[1][n];
        for(int j = 2; j <= m; j++)
        {
            for(int i = x[j]; i <= n;i++)
            {
                int p = i - x[j];
                int b = 0;
                for(int k = 1; k <= j; ++k)
                    b+= a[k][p];
                a[j][i] = b;
                cout << "j " << x[j] << " i " << i  << " total  " << b << endl ;
            }
            s += a[j][n];
        }
        return s;
    }


   vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;

        if(candidates.empty() || target < 0 ) return res;    
        
        if(candidates[0] <= 0) return res;

        int cand_cnt = target / candidates[0] ;

        vector<int> nums(cand_cnt,0);

        int max_idx = candidates.size();
        
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

                if(flag && idx == i && target == sum + candidates[nums[idx]])
                {
                    vector<int> new_res;
                    for (int j = 0; j <= i; j++)
                    {
                        /* code */
                        //cout <<"id " << nums[j] << " value "<< candidates[nums[j]] << " " ;
                        new_res.push_back(candidates[nums[j]]);
                    } 
                    res.push_back(new_res);
                    //cout << endl;
                }

                if(flag && idx < i)
                {
                    ++idx;
                    nums[idx] = 0;
                    continue;
                }

                while(idx >= 0 && nums[idx] == max_idx - 1)
                {
                    --idx;
                }

                if(idx < 0)
                    break;
                else
                    ++nums[idx];
            }    
        }
        return res;
    }

// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

// 示例 1:

// 输入: coins = [1, 2, 5], amount = 11
// 输出: 3 
// 解释: 11 = 5 + 5 + 1
// 示例 2:

// 输入: coins = [2], amount = 3
// 输出: -1

    void dfs(vector<int>& coins,int idx,int amount ,int &cur,int &result)
    {
        if(idx == (int)coins.size() && amount == 0) 
        {
            if(cur < result || result == -1)
                result = cur;
            return ;
        }
        if(idx == (int)coins.size() && amount != 0) return ;
        
        for(int i = amount / coins[idx]; i >= 0 ; --i)
        {
            if(cur + i > result && result > 0) break;
            cur += i;
            dfs(coins,idx + 1,amount - i * coins[idx],cur,result);
            cur -= i;
        }
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        if(coins.empty()) return -1;
        if(amount == 0) return 0;
        
        sort(coins.begin(),coins.end(),[]( int s1, int s2) { return s1 > s2;});
        
        int cur = 0;
        int result = -1;
        dfs(coins,0, amount ,cur,result);

        return result;
    }

    void answer()
    {


        vector<int > moneys = {2,3,5,};

        int s = changemoney(moneys,8);

        vector<vector<int > > res = combinationSum(moneys,8);

        cout <<"s is " << res.size() << "s is " << s<< endl;
    }


};

#endif
