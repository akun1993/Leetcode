#ifndef __SOLUTION_STRING_DECODE_
#define __SOLUTION_STRING_DECODE_

#include <string>
#include <iostream>
#include <my_types.h>
#include <ISolutionBase.h>
using namespace std;
// 给定一个经过编码的字符串，返回它解码后的字符串。

// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

// 示例:

// s = "3[a]2[bc]", 返回 "aaabcbc".
// s = "3[a2[c]]", 返回 "accaccacc".
// s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/decode-string
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//解法 ：使用递归， 本题解码同样涉及到括号匹配的问题，解码时最主要的是注意嵌套，也就是 '[' 开始 和 ']' 结束，必须对应匹配
// 其内部嵌套的'['']' 

class SolutionStringDecode :  public ISolutionBase
{
public:
    
    void __decode(string &s,int beg,int &end,int &breaket,string &str)
    {
        if(beg >= (int)s.size()) 
        {
            end = beg;
            return;   
        }

        //是数字，说明后面存在[
        if(isdigit(s[beg]))
        {
            int num = 0;
            while(isdigit(s[beg]))
            {
                num = num * 10 + (s[beg] - '0');
                ++beg;
            }
            //增加括号的数量
            ++breaket;
            string tmp;
            //对括号内的内容继续解码
            __decode(s,beg + 1,end,breaket,tmp);    
            
            while(num >0)
            {
                str.append(tmp);
                --num;
            }
            //还有括号没有被解，继续解码
            if(breaket != 0)
            {
                string  oth;
                __decode(s,end + 1,end,breaket,oth); 
                str.append(oth);
            }
        }
        else
        {
            string sub;
            //是字母
            while(isalpha(s[beg]))
            {
                sub.append(1,s[beg++]);
            }
            //是数字
            if(isdigit(s[beg]))
            {
                string  tmp;
                __decode(s,beg,end,breaket,tmp); 
                sub.append(tmp);
            }
            str.append(sub);
            //遇到']',减少括号的数量
            if(s[beg] == ']' || beg >= (int)s.size())
            {
                --breaket;
                end = beg;
            }
        }
    }
    
    string decodeString(string s) {
                
        string str;

        for(int i = 0; i < (int)s.size();)
        {
            int end;
            string tmp;
            int breaket = 0;
            __decode(s,i,end,breaket,tmp);
            str.append(tmp);
            i = end + 1;
            
           // cout <<"tmp is " <<tmp<<"  end is"<< end << endl;  
        }

        return str;
        
    }

    void answer()
    {
        string encode_str = "2[abc]3[cd2[d]ef2[d]]ef";
        string str =   decodeString(encode_str);
        cout <<str<< endl;  
    }
};

#endif
