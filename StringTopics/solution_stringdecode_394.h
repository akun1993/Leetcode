#ifndef __SOLUTION_STRING_DECODE_
#define __SOLUTION_STRING_DECODE_

#include <string>
#include <iostream>
#include <my_types.h>
#include <ISolution.h>
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

class SolutionStringDecode : public ISolution
{
public:

    SolutionStringDecode(){}
    ~SolutionStringDecode(){}
    
    void __decode(string &s,int beg,int &end,int &breaket,string &str);
    
    string decodeString(string s) ;
    void answer();

};

#endif
