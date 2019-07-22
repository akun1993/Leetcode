#include "solution_increasingTriplet.h"

bool SolutionTriplet::increasingTriplet(vector<int> &nums)
{

    if (nums.size() < 3)
        return false;

    int a = nums[0];

    int b = nums[1];

    for (u32 i = 2; i < nums.size(); ++i)
    {
        if (a < b && b < nums[i])
            return true;

        if (a > nums[i] && b < nums[i])
        {
            a = b;
            b = nums[i];
        }

        if (nums[i] > a && nums[i] < b)
        {
            b = nums[i];
        }

        if (a > b && nums[i] > a)
        {
            a = b;
            b = nums[i];
        }
    }

    a = nums[nums.size() - 1];

    b = nums[nums.size() - 2];

    for (int i = (int)nums.size() - 3; i >= 0; --i)
    {
        if (a > b && b > nums[i])
            return true;

        if (a < nums[i] && b > nums[i])
        {
            a = b;
            b = nums[i];
        }

        if (nums[i] < a && nums[i] > b)
        {
            b = nums[i];
        }

        if (a < b && nums[i] < a)
        {
            a = b;
            b = nums[i];
        }
    }
    return false;
}
void SolutionTriplet::answer()
{

    vector<int> test = {1, 2, 1, 7, 9, 2, 4, 5};

    increasingTriplet(test);
}
