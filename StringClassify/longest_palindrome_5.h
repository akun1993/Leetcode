
#ifndef __LONGEST_PALINDROME_H
#define __LONGEST_PALINDROME_H

#include <string>
#include <iostream>
#include "my_types.h"

using namespace std;

//      给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

//     示例 1：

//      输入 : "babad" 输出 : "bab" 注意 : "aba" 也是一个有效答案。 示例 2：

//      输入 : "cbbd" 输出 : "bb"

//     来源：力扣（LeetCode）
//     链接：https : //leetcode-cn.com/problems/longest-palindromic-substring
//     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class SolutionPalindrome
{
public:
    string longestPalindrome(string s) {
        
        string str;
        for(u32 i = s.size() ; i >= 1; --i)
        {
            
            for(u32 j = 0; j + i - 1 < s.size(); ++j)
            {
                bool is_palind = true;
                int tmp_beg = j;
                int tmp_end = j + i - 1;
                
               // cout << tmp_beg << "  " << tmp_end << endl;
               
                while(tmp_beg <= tmp_end )
                {
                    if(s[tmp_beg] != s[tmp_end])
                    {
                        is_palind = false;
                        break;
                    }
                    ++tmp_beg;
                    --tmp_end;
                }
                //cout << is_palind << endl;
                if(is_palind )
                {
                     str = s.substr (j,i);
                     return str;
                }
                
            }

        }
         
        return str;
    }

    void answer()
    {
        string str = longestPalindrome("cbbd");

        cout << str << endl;

    }

};

#endif
