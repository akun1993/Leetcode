
#ifndef __LEET_ANAGRAMS_H_
#define __LEET_ANAGRAMS_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <my_types.h>
#include <ISolutionBase.h>
using namespace std;

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

class SolutionAnagrams : public ISolutioBase
 {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs);
    vector<vector<string>> groupAnagramsII(vector<string>& strs);
    vector<vector<string>> groupAnagramsIII(vector<string> &strs);
    void answer();

};

#endif

