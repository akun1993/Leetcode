#ifndef __SOLUTION_WORD_BREAK_H_
#define __SOLUTION_WORD_BREAK_H_


#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>

class SolutionWordBreak
{
private:
    /* data */
public:
   
    bool dfs(string &s,int idx,map<string,int> &dict,int str_len_min,vector<int> &memo)
    {
        if(idx  >= (int)s.size()) return true;
        
        if(memo[idx] == 0) return false;

        bool res = false;
        for(int i = 0; (idx + str_len_min + i) <= (int)s.size(); ++i)
        {
            if(dict.count(s.substr(idx,str_len_min + i)))
            {
                res = dfs(s,idx + str_len_min + i,dict,str_len_min,memo);
                if(res)
                {
                   // memo[idx] = 1;
                    return true;;
                } 
            }
            
        }
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
