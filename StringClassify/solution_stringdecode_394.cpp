
#include "solution_stringdecode_394.h"
using namespace std;

void SolutionStringDecode::__decode(string &s, int beg, int &end, int &breaket, string &str)
{
    if (beg >= (int)s.size())
    {
        end = beg;
        return;
    }

    //是数字，说明后面存在[
    if (isdigit(s[beg]))
    {
        int num = 0;
        while (isdigit(s[beg]))
        {
            num = num * 10 + (s[beg] - '0');
            ++beg;
        }
        //增加括号的数量
        ++breaket;
        string tmp;
        //对括号内的内容继续解码
        __decode(s, beg + 1, end, breaket, tmp);

        while (num > 0)
        {
            str.append(tmp);
            --num;
        }
        //还有括号没有被解，继续解码
        if (breaket != 0)
        {
            string oth;
            __decode(s, end + 1, end, breaket, oth);
            str.append(oth);
        }
    }
    else
    {
        string sub;
        //是字母
        while (isalpha(s[beg]))
        {
            sub.append(1, s[beg++]);
        }
        //是数字
        if (isdigit(s[beg]))
        {
            string tmp;
            __decode(s, beg, end, breaket, tmp);
            sub.append(tmp);
        }
        str.append(sub);
        //遇到']',减少括号的数量
        if (s[beg] == ']' || beg >= (int)s.size())
        {
            --breaket;
            end = beg;
        }
    }
}

string SolutionStringDecode::decodeString(string s)
{

    string str;

    for (int i = 0; i < (int)s.size();)
    {
        int end;
        string tmp;
        int breaket = 0;
        __decode(s, i, end, breaket, tmp);
        str.append(tmp);
        i = end + 1;

        // cout <<"tmp is " <<tmp<<"  end is"<< end << endl;
    }

    return str;
}

void SolutionStringDecode::answer()
{
    string encode_str = "2[abc]3[cd2[d]ef2[d]]ef";
    string str = decodeString(encode_str);
    cout << str << endl;
}
