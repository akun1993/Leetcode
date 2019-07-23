#ifndef __SOLUTION_WORD_BREAK_H_
#define __SOLUTION_WORD_BREAK_H_


#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <my_types.h>
#include <ISolution>
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

class SolutionWordBreak : public ISolution
{
private:
    /* data */
public:

    SolutionWordBreak(){}
    ~SolutionWordBreak(){}
   
    bool dfs(string &s,int idx,map<string,int> &dict,int str_len_min,vector<int> &memo);
    bool wordBreak(string s, vector<string>& wordDict);
    bool wordBreakII(string s, vector<string>& wordDict);
    void answer();

};



#endif
