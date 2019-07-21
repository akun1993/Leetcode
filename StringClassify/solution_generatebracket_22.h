#ifndef __SOLUTION_GENERATE_BRACKET_H_
#define __SOLUTION_GENERATE_BRACKET_H_

#include <vector>
#include <string>
#include <my_types.h>
#include <ISolutionBase.h>
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

class SolutionGenerateBracket : public ISolutionBase
{
public:

    void recursive(string &str,int left,int right,vector<string> &result)
    {
        if (left == 0)
        {
            int i = 0;
            while (i++ < right)
            {
                str.append(1,')');
            }

            result.push_back(str);

            i = 0;
            while (i++ < right)
            {
                str.pop_back();
            }
            return;
        }
		 //print("left == 0 ",right)

        if (left > 0 )
        {
            str.append(1,'(');
            //print("left first ",List)
            recursive(str,left - 1,right,result);
            str.pop_back();
        }

        if(right > 0 && left < right )
        {
            str.append(1,')');
            //print("right first ",List)
            recursive(str,left,right - 1,result);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> bracketlist;

        string str;
        str.append(1,'(');

        recursive(str,n - 1,n,bracketlist);
        return bracketlist;
    }

    void answer()
    {
       vector<string> bracketlist = generateParenthesis(3);

       for(int i = 0; i < (int)bracketlist.size(); ++i)
       {
           cout << bracketlist[i] << endl;
       }
    }

};

#endif // __SOLUTION_GENERATE_BRACKET_H_
