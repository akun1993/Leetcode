#ifndef __SOLUTION_MERGE_ARRAY_H_
#define __SOLUTION_MERGE_ARRAY_H_

#include <vector>
#include <string>
#include <ISolution.h>
using namespace std;


// 给出一个区间的集合，请合并所有重叠的区间。

// 示例 1:

// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

// 来源：力扣（LeetCode）


class SolutionMergeArray : public ISolution
{
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size() <= 1) return intervals;
        
        vector<vector<int>> res;
        
        vector<bool> falg(intervals.size(),false);
        
        for(size_t i = 0; i < intervals.size();++i)
        {
            int idx;
            int max = (int)(~0U >> 1);
            for(size_t i = 0; i < intervals.size();++i)
            {
                if(falg[i] == true) continue;
                int diff = intervals[i][0];
                if(diff < max)
                {
                    max = diff;
                    idx = i;
                }
            }
            
            vector<int> &ele = intervals[idx];
            
            falg[idx] = true;
            

            bool merge = false;
            for(size_t i = 0;i < res.size();++i)
            {
               vector<int> &tmp = res[i];
                
                //四种情况
                // 区间 a , 区间 b
                // 1. a包含b
                // 2. a被包含b
                // 3. a 和 b 相交 最小值是 a[0]
                // 4. a 和 b 相交 最小值是 b[0]
                
                if((tmp[0] <= ele[0] && tmp[1] >= ele[1]) 
                    || (tmp[0] <= ele[0] && tmp[1] <= ele[1] && tmp[1] >= ele[0] )
                    || (tmp[0] >= ele[0] && tmp[1] >= ele[1] && tmp[0] <= ele[1])
                    || (tmp[0] >= ele[0] && tmp[1] <= ele[1]) )
                {
                    tmp[0] = tmp[0] > ele[0] ? ele[0] : tmp[0];
                    tmp[1] = tmp[1] > ele[1] ? tmp[1] : ele[1];
                    merge = true;
                }

            }

            if(!merge) res.push_back(ele);
        }
        return res; 
    }

    vector<vector<int>> mergeII(vector<vector<int>>& intervals) 
    {
        if(intervals.size() <= 1) return intervals;
        
        vector<vector<int>> res;
        
        vector<bool> falg(intervals.size(),false);
        
        for(size_t i = 0; i < intervals.size();++i)
        {
            int idx;
            int max = (int)(~0U >> 1);
            for(size_t i = 0; i < intervals.size();++i)
            {
                if(falg[i] == true) continue;
                int diff = intervals[i][0];
                if(diff < max)
                {
                    max = diff;
                    idx = i;
                }
            }
            
            vector<int> &ele = intervals[idx];
            
            falg[idx] = true;
            

            bool merge = false;
            for(size_t i = 0;i < res.size();++i)
            {
               vector<int> &tmp = res[i];
                
                //四种情况
                // 区间 a , 区间 b
                // 1. a包含b
                // 2. a被包含b
                // 3. a 和 b 相交 最小值是 a[0]
                // 4. a 和 b 相交 最小值是 b[0]
                
                if((tmp[0] <= ele[0] && tmp[1] >= ele[1]) 
                    || (tmp[0] <= ele[0] && tmp[1] <= ele[1] && tmp[1] >= ele[0] )
                    || (tmp[0] >= ele[0] && tmp[1] >= ele[1] && tmp[0] <= ele[1])
                    || (tmp[0] >= ele[0] && tmp[1] <= ele[1]) )
                {
                    tmp[0] = tmp[0] > ele[0] ? ele[0] : tmp[0];
                    tmp[1] = tmp[1] > ele[1] ? tmp[1] : ele[1];
                    merge = true;
                }

            }

            if(!merge) res.push_back(ele);
        }
        return res; 
    }



    void answer()
    {

       vector<vector<int> > case_1 = {{1,3},{2,6},{8,10},{15,18}};

       vector<vector<int> > ret = merge(case_1);

       for(int i = 0; i < (int)ret.size(); ++i)
       {
           cout << "[" << ret[i][0] << "," <<  ret[i][1]  << "]" << endl;
       }

    }

};

#endif
