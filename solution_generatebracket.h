#ifndef __SOLUTION_GENERATE_BRACKET_H_
#define __SOLUTION_GENERATE_BRACKET_H_

#include <vector>
#include <string>

using namespace std;

//���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ�����Ч��������ϡ�
//���磬���� n = 3�����ɽ��Ϊ��
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]

class SolutionGenerateBracket
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
