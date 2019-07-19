#ifndef __SOLUTION_WORD_BREAK_H_
#define __SOLUTION_WORD_BREAK_H_


#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
using namespace std;

// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

// 说明：

// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
// 示例 1：

// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 示例 2：

// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//      注意你可以重复使用字典中的单词。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/word-break
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 解法1 ： 深度优先搜索，深度优先搜索的解法是搜索一颗状态数，随着深度的增加，其时间复杂度呈指数增长，
// 因为其中相同的结果可能被计算多次，所以一般使用记忆法来记录那些被计算过的节点，也就是通常说的裁剪。

// 解法2：广度优先搜索，首先将从0开始将到j（j >= 0  && j < s.size()） 结束的所有在字典中的单词,加入队列
// 队列中存储的是结束的索引，然后取出队列中的元素也就是索引，从该索引再次进行搜索，直到队列为空，或找到结果。

class SolutionWordBreak
{
private:
    /* data */
public:
   
    bool dfs(string &s,int idx,map<string,int> &dict,int str_len_min,vector<int> &memo)
    {
        if(idx  >= (int)s.size()) return true;
        //从idx开始无法找到结果，则返回
        if(memo[idx] == 0) return false;

        bool res = false;
        //对从idx开始的每一个子串进行检查
        for(int i = 0; (idx + str_len_min + i) <= (int)s.size(); ++i)
        {
            //如果包含在字典中
            if(dict.count(s.substr(idx,str_len_min + i)))
            {
                //继续递归处理
                res = dfs(s,idx + str_len_min + i,dict,str_len_min,memo);
                if(res)
                {
                   // memo[idx] = 1;
                    return true;;
                } 
            }
            
        }
        //从idx开始无法找到结果，则裁剪掉该分支
        memo[idx] = 0;
        return res;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(s.empty()) return false;
        
        if(wordDict.empty()) return false;
        
        map<string,int> dict;
        
        int str_len_min = (int)(~0U >> 1);
        for(int i = 0; i < (int)wordDict.size(); ++i)
        {
            
            dict[wordDict[i]] = 1;
            
            if((int)wordDict[i].size() < str_len_min )
            {
                str_len_min = wordDict[i].size();
            }
        }

        vector<int> memo(s.size(),-1);

        return dfs(s,0,dict, str_len_min,memo);
    }


    bool wordBreakII(string s, vector<string>& wordDict) {
        
        if(s.empty()) return false;
        
        if(wordDict.empty()) return false;
        
        set<string> dict;
    
        for(int i = 0; i < (int)wordDict.size(); ++i)
        {
            dict.insert(wordDict[i]);
        }
        vector<bool> memo(s.size(),true);
        
        deque<int> qu;
        //int start = 0;

        qu.push_back(0);
        while(!qu.empty())
        {
            int idx = qu.back();

            qu.pop_back();

            if(memo[idx] == false) continue;
            for (size_t j = idx + 1; j <= s.size(); j++)
            {
                /* code */
                if(dict.count(s.substr(idx,j - idx)))
                {
                    if(j == s.size()) return true;
                    qu.push_back(j);
                }
            }
            memo[idx] = false;
        }    
        return false;    
    }
    void answer()
    {

        string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";

        string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

        cout << s.size() << " " << s1.size() << endl;

        vector<string> strs = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        
        bool ret = wordBreakII( s, strs);
        cout << ret << endl;
        ret = wordBreakII( s1, strs);

        cout << ret << endl;

    }

};



#endif
