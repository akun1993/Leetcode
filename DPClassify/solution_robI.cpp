#include "solution_robI.h"

void SolutionRob::gap_rob(int beg, vector<int> &nums, int &cur_money, int &max_money)
{

    if (beg >= (int)nums.size())
    {
        //cout << beg <<"  " << nums.size() << endl;
        max_money = cur_money > max_money ? cur_money : max_money;
        return;
    }

    cur_money += nums[beg];

    gap_rob(beg + 2, nums, cur_money, max_money);

    gap_rob(beg + 3, nums, cur_money, max_money);

    cur_money -= nums[beg];
}

int SolutionRob::rob(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int cur_money = 0;

    //max_money = max_money + nums[0];

    int max_money_1 = 0;
    //max_money = max_money + nums[0];

    gap_rob(0, nums, cur_money, max_money_1);

    cur_money = 0;
    int max_money_2 = 0;
    //gap_rob(1,nums,cur_money,max_money_2);

    return max_money_1 > max_money_2 ? max_money_1 : max_money_2;
}

void SolutionRob::answer()
{

    vector<vector<int>> test_case;

    vector<int> nums = {1, 2, 5, 9, 2, 6, 20, 23, 221, 1, 2, 5};

    // test_case.push_back(nums);

    vector<int> nums_2 = {1, 2, 3, 1};

    //  test_case.push_back(nums_2);

    vector<int> nums_3 = {2, 7, 9, 3, 1};

    // test_case.push_back(nums_3);

    vector<int> nums_4 = {
        1,
        2,
    };

    //test_case.push_back(nums_4);

    vector<int> nums_5 = {226, 174, 214, 16, 218, 48, 153, 131, 128, 17, 157, 142, 88, 43, 37, 157, 43, 221, 191, 68, 206, 23, 225, 82, 54, 118, 111, 46, 80, 49, 245, 63, 25, 194, 72, 80, 143, 55, 209, 18, 55, 122, 65, 66, 177, 101, 63, 201, 172, 130, 103, 225, 142, 46, 86, 185, 62, 138, 212, 192, 125, 77, 223, 188, 99, 228, 90, 25, 193, 211, 84, 239, 119, 234, 85, 83, 123, 120, 131, 203, 219, 10, 82, 35, 120, 180, 249, 106, 37, 169, 225, 54, 103, 55, 166, 124};

    test_case.push_back(nums_5);

    vector<int> nums_6 = {
        226,
        174,
        214,
        16,
        218,
        48,
        153,
        131,
        128,
        17,
        157,
        142,
        88,
        43,
        37,
        157,
        43,
        221,
        191,
        68,
        206,
        23,
        225,
        82,
        54,
        118,
        111,
        46,
        80,
        49,
        245,
        63,
        25,
        194,
        72,
        80,
        143,
        55,
        209,
        18,
        55,
        122,
        65,
    }; //66,177,101,63,201,172,130,103,};
    test_case.push_back(nums_6);
    for (u32 i = 0; i < test_case.size(); i++)
    {
        /* code */
        cout << "size is " << test_case[i].size() << endl;

        int money = rob(test_case[i]);

        cout << "group " << i + 1 << " result : " << money << endl;
    }
}
