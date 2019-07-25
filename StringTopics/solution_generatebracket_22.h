#ifndef __SOLUTION_GENERATE_BRACKET_H_
#define __SOLUTION_GENERATE_BRACKET_H_

#include <vector>
#include <string>
#include <my_types.h>
#include <ISolution.h>
using namespace std;

// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
// 例如，给出 n = 3，生成结果为：
//     ["((()))",
//      "(()())",
//      "(())()",
//      "()(())",
//      "()()()"]

// 来源：力扣（LeetCode）
// 链接：https : //leetcode-cn.com/problems/generate-parentheses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 递归，生成的括号必须是有效的，所以最终 '(' 和 ')' 的数量是一样的,并且每一部增加一个括号时，
// '(' 的数量一定大于等于')'的数量，所以第一个肯定是'(',
// 结束条件是'('的数量达到要求。

class SolutionGenerateBracket : public ISolution
{
public:
    SolutionGenerateBracket(){}
    ~SolutionGenerateBracket(){}
    void recursive(string &str,int left,int right,vector<string> &result);
    vector<string> generateParenthesis(int n);
    void answer();
};

#endif // __SOLUTION_GENERATE_BRACKET_H_
