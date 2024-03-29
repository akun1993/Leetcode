
#include "solution_longest_palindrome_5.h"


string SolutionPalindrome::longestPalindrome(string s)
{

    string str;
    for (u32 i = s.size(); i >= 1; --i)
    {

        for (u32 j = 0; j + i - 1 < s.size(); ++j)
        {
            bool is_palind = true;
            int tmp_beg = j;
            int tmp_end = j + i - 1;

            // cout << tmp_beg << "  " << tmp_end << endl;

            while (tmp_beg <= tmp_end)
            {
                if (s[tmp_beg] != s[tmp_end])
                {
                    is_palind = false;
                    break;
                }
                ++tmp_beg;
                --tmp_end;
            }
            //cout << is_palind << endl;
            if (is_palind)
            {
                str = s.substr(j, i);
                return str;
            }
        }
    }

    return str;
}

void SolutionPalindrome::answer()
{
    string str = longestPalindrome("cbbd");

    cout << str << endl;
}
