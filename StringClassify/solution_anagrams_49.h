
#ifndef __LEET_ANAGRAMS_H_
#define __LEET_ANAGRAMS_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>

// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/group-anagrams
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//解法1：暴力解法，最开始结果集是空的，遍历每一个字符串，如果这个字符串不属于结果集中的任何一个字母异位词组，则新增加一个组
//否则添加到相应的数组中。

// 解法2：对每个字符串的副本排序，是字母异位的排序后顺序一定相同,并使用map将是字母异位词的存在同一个key中
// 最后在复制到返回结果

using namespace std;

class SolutionAnagrams {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;

        if(strs.empty()) return res;

        //int  flag[26] = {0};
        //vector<bool> flag(strs.size(),false);
        map<int,vector<int>> record; 

        for (size_t i = 0; i < strs.size(); i++)
        {
            /* code */
            string &cur = strs[i];
            map<int,vector<int>>::iterator iter = record.begin();

            int idx = -1;
            for (; iter != record.end(); ++iter)
            {
                /* code */
                vector<int> &info_vec = iter->second;
                
                if((int)cur.size() != info_vec[0]) continue;

                bool new_flag = false;

                int cur_vec[27] = {0}; 

                for (size_t j = 0; j < cur.size(); j++)
                {
                    /* code */
                    int idx_j = cur[j] - 'a' + 1;

                    ++cur_vec[idx_j];
                    if( info_vec[idx_j] < cur_vec[idx_j])
                    {
                        new_flag = true;
                        break;
                    }
                }
                if(!new_flag)
                {
                    idx = iter->first;
                    break;
                }
            }

            if(idx == -1)
            {
                vector<string> diff(1,cur);
                res.push_back(diff);

                vector<int> cnt_vec(27,0);
                
                cnt_vec[0] = cur.size();
                for(size_t k = 0; k < cur.size();++k)
                {
                    int idx_k = cur[k] - 'a' + 1;
                    if(idx_k > 0 && idx_k < (int)cnt_vec.size())
                        ++cnt_vec[idx_k];
                }
                record[res.size()] = cnt_vec;
            }
            else
            {
                res[idx -1].push_back(cur);
            }
            

        }
        return res;

    }

    vector<vector<string>> groupAnagramsII(vector<string>& strs) 
    {
       vector<vector<string>> res;

        if(strs.empty()) return res;

        int  flag[26] = {0};
        //vector<bool> flag(strs.size(),false);
        
        for (size_t i = 0; i < strs.size(); i++)
        {
            /* code */
            string &cur = strs[i];

            int idx = -1;
            for (size_t k = 0; k < res.size(); ++k)
            {
                /* code */
                string &contrast = res[k][0];
                
                if(cur.size() != contrast.size()) continue;

                bool new_flag = true;
                int cur_vec[26] = {0};

                int a = 0;
                int b = 0;
                for (size_t j = 0; j < cur.size(); j++)
                {
                    int idx_a  = (cur[j] - 'a');
                    int idx_b  = (contrast[j] - 'a');

                    ++cur_vec[idx_a];
                    --cur_vec[idx_b];

                    a += idx_a;
                    b += idx_b;
                }
                if(a != b || memcmp(flag,cur_vec,26 * 4) != 0)
                {
                    new_flag = false;
                }

                if(new_flag)
                {
                    idx = k;
                    break;
                }
            }

            if(idx == -1)
            {
                res.push_back(vector<string> (1,cur));
            }
            else
            {
                res[idx].push_back(cur);
            }
        }
        return res;
    }


    vector<vector<string>> groupAnagramsIII(vector<string> &strs)
    {

        map<string, vector<string>> dict;
        vector<vector<string>> res;
        string tmp;
        for (int i = 0; i < strs.size(); ++i)
        {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            dict[tmp].push_back(strs[i]);
        }

        for (auto i : dict)
            res.push_back(i.second);

        return res;
    }

    void answer()
    {


    }

};

#endif

