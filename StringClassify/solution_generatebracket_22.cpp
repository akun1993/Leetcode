#include "solution_generatebracket_22.h"
#include <iostream>
void SolutionGenerateBracket::recursive(string &str, int left, int right, vector<string> &result)
{
    if (left == 0)
    {
        int i = 0;
        while (i++ < right)
        {
            str.append(1, ')');
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

    if (left > 0)
    {
        str.append(1, '(');
        //print("left first ",List)
        recursive(str, left - 1, right, result);
        str.pop_back();
    }

    if (right > 0 && left < right)
    {
        str.append(1, ')');
        //print("right first ",List)
        recursive(str, left, right - 1, result);
        str.pop_back();
    }
}

vector<string> SolutionGenerateBracket::generateParenthesis(int n)
{
    vector<string> bracketlist;

    string str;
    str.append(1, '(');

    recursive(str, n - 1, n, bracketlist);
    return bracketlist;
}

void SolutionGenerateBracket::answer()
{
    vector<string> bracketlist = generateParenthesis(3);

    for (int i = 0; i < (int)bracketlist.size(); ++i)
    {
        cout << bracketlist[i] << endl;
    }
}