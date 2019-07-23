#ifndef __SOLUTION_LONGEST_SUBSTRING_H_
#define __SOLUTION_LONGEST_SUBSTRING_H_

#include <string>
#include <iostream>
#include <my_types.h>
#include <ISolution.h>
using namespace std;
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

// 示例 1:

// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//解法： 双指针的解法，begin 记录当前的最长无重复字符的开始，tmp记录当前最长无重复字符的结尾，
// 并使用 int sum[256] （因为最长的无重复字符串就是256）记录当前已经加入最长无重复字符串的索引，
// 如果下一个字符在sum[256]中有记录，则说明如果添加这个字符，会使结果字符串中出现重复的字符，所以要更新
// 当前的begin 值，找到那个字符，并从之后的那个字符开始计算begin，同时更新最长的无重复字符串的长度。

class SolutionLongestSubstring : public ISolution
{
public:

    SolutionLongestSubstring(){}
    ~SolutionLongestSubstring(){}

    int lengthOfLongestSubstring(std::string s);
  
    int lengthOfLongestSubstringII(std::string s);

    void answer();
};



#endif
