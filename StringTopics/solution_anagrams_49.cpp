#include "solution_anagrams_49.h"

vector<vector<string>> SolutionAnagrams::groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    if (strs.empty())
        return res;

    //int  flag[26] = {0};
    //vector<bool> flag(strs.size(),false);
    map<int, vector<int>> record;

    for (size_t i = 0; i < strs.size(); i++)
    {
        /* code */
        string &cur = strs[i];
        map<int, vector<int>>::iterator iter = record.begin();

        int idx = -1;
        for (; iter != record.end(); ++iter)
        {
            /* code */
            vector<int> &info_vec = iter->second;

            if ((int)cur.size() != info_vec[0])
                continue;

            bool new_flag = false;

            int cur_vec[27] = {0};

            for (size_t j = 0; j < cur.size(); j++)
            {
                /* code */
                int idx_j = cur[j] - 'a' + 1;

                ++cur_vec[idx_j];
                if (info_vec[idx_j] < cur_vec[idx_j])
                {
                    new_flag = true;
                    break;
                }
            }
            if (!new_flag)
            {
                idx = iter->first;
                break;
            }
        }

        if (idx == -1)
        {
            vector<string> diff(1, cur);
            res.push_back(diff);

            vector<int> cnt_vec(27, 0);

            cnt_vec[0] = cur.size();
            for (size_t k = 0; k < cur.size(); ++k)
            {
                int idx_k = cur[k] - 'a' + 1;
                if (idx_k > 0 && idx_k < (int)cnt_vec.size())
                    ++cnt_vec[idx_k];
            }
            record[res.size()] = cnt_vec;
        }
        else
        {
            res[idx - 1].push_back(cur);
        }
    }
    return res;
}

vector<vector<string>> SolutionAnagrams::groupAnagramsII(vector<string> &strs)
{
    vector<vector<string>> res;

    if (strs.empty())
        return res;

    int flag[26] = {0};
    //vector<bool> flag(strs.size(),false);

    for (size_t i = 0; i < strs.size(); i++)
    {
        /* code */
        string &cur = strs[i];

        int idx = -1;
        for (size_t k = 0; k < res.size(); ++k)
        {
            /* code */
            string &contrast = res[k][0];

            if (cur.size() != contrast.size())
                continue;

            bool new_flag = true;
            int cur_vec[26] = {0};

            int a = 0;
            int b = 0;
            for (size_t j = 0; j < cur.size(); j++)
            {
                int idx_a = (cur[j] - 'a');
                int idx_b = (contrast[j] - 'a');

                ++cur_vec[idx_a];
                --cur_vec[idx_b];

                a += idx_a;
                b += idx_b;
            }
            if (a != b || memcmp(flag, cur_vec, 26 * 4) != 0)
            {
                new_flag = false;
            }

            if (new_flag)
            {
                idx = k;
                break;
            }
        }

        if (idx == -1)
        {
            res.push_back(vector<string>(1, cur));
        }
        else
        {
            res[idx].push_back(cur);
        }
    }
    return res;
}

vector<vector<string>> SolutionAnagrams::groupAnagramsIII(vector<string> &strs)
{

    map<string, vector<string>> dict;
    vector<vector<string>> res;
    string tmp;
    for (u32 i = 0; i < strs.size(); ++i)
    {
        tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        dict[tmp].push_back(strs[i]);
    }

    for (auto i : dict)
        res.push_back(i.second);

    return res;
}

void SolutionAnagrams::answer()
{
}