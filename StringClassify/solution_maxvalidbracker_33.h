#ifndef __MAX_VALID_BRACKER_H_
#define __MAX_VALID_BRACKER_H_

#include <stack>
#include <string>
#include <iostream>
#include <my_types.h>
#include <ISolutionBase.h>

using namespace std;
// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

// 示例 1:

// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 示例 2:

// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-valid-parentheses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 括号的问题最常用的解法就是使用栈来解决。这里是寻找最长的包含有效括号的子串的长度
// 所以就是统计每个子串的有效长度。

class SolutionMaxValidBracker: public ISolutionBase
 {
public:
    
    SolutionMaxValidBracker(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionMaxValidBracker(){}

    struct Record_s
    {
        Record_s(int c,int idx):c(c),idx(idx) {}
        int  c;
        int  idx;
    };

    typedef  struct Record_s Record_t;
    int longestValidParentheses(string s);
    int longestValidParenthesesII(string s);
    void answer();

};
#endif