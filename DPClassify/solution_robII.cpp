#include "solution_robII.h"

int SolutionRobII::rob(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    if (nums.size() == 1)
        return nums[0];

    map<int, int> res1;
    map<int, int> res2;

    int ret_rob = nums[0];

    for (int k = 0; k < 2; ++k)
    {
        cout << " current index" << k << endl;
        res1[k] = nums[k];
        int max_rob = nums[k];

        while (!res1.empty() || !res2.empty())
        {
            map<int, int> &full_map = res1.empty() ? res2 : res1;
            map<int, int> &empty_map = res1.empty() ? res1 : res2;

            if (!full_map.empty())
            {
                map<int, int>::iterator iter = full_map.begin();
                for (; iter != full_map.end(); ++iter)
                {
                    int key = iter->first;
                    int val = iter->second;
                    int arr[2] = {key + 2, key + 3};

                    cout << "key is " << key << " value is " << val << endl;

                    for (int i = 0; i < 2; ++i)
                    {
                        int next = arr[i];
                        if (next < (int)nums.size())
                        {
                            if (empty_map.count(next))
                            {
                                if (nums[next] + val > empty_map[next])
                                    empty_map[next] = val + nums[next];
                                if (empty_map[next] > max_rob)
                                    max_rob = empty_map[next];
                            }
                            else
                            {
                                empty_map[next] = val + nums[next];
                                if (empty_map[next] > max_rob)
                                    max_rob = empty_map[next];
                            }
                        }
                    }
                }
                full_map.clear();
                if (!res1.empty() || !res2.empty())
                    cout << "\nnext group";
                cout << endl;
            }
        }

        ret_rob = max_rob > ret_rob ? max_rob : ret_rob;
    }
    return ret_rob;
}
int SolutionRobII::rob2(vector<int> &nums)
{
    int sumodd = 0, sumeven = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            sumeven += nums[i];
            sumeven = max(sumodd, sumeven);
        }
        else
        {
            sumodd += nums[i];
            sumodd = max(sumodd, sumeven);
        }
    }
    return max(sumodd, sumeven);
}

void SolutionRobII::answer()
{
    srand(time(NULL));
    vector<int> height = {2, 1, 1, 2};

    for (int i = 0; i < 100; ++i)
    {
        // height.push_back(rand() % 100);
    }

    int max_area = rob2(height);

    cout << "answer is " << max_area << endl;

    vector<int> height_2 = {1, 2};

    max_area = rob2(height_2);

    cout << "answer is " << max_area << endl;

    vector<int> height_3 = {6, 3, 10, 8, 2, 10, 3, 5, 10, 5, 3};

    max_area = rob2(height_3);

    cout << "answer is " << max_area << endl;
}
