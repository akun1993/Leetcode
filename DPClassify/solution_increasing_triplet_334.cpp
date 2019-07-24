#include "solution_increasing_triplet_334.h"

bool SolutionTriplet::increasingTriplet(vector<int> &nums)
{

    if (nums.size() < 3)
        return false;
        
    int min_1 = (int)(~0U >> 1);
    
    int min_2 = (int)(~0U >> 1);
    
    for(size_t i = 0; i < nums.size();++i)
    {
        if(nums[i] <= min_1)
        {
            min_1 = nums[i];
        }
        else if(nums[i] <= min_2)
        {
            min_2  = nums[i];
        }
        else
        {
            return true;
        }
    }
    return false;
}
void SolutionTriplet::answer()
{

    vector<int> test = {1, 2, 1, 7, 9, 2, 4, 5};

    increasingTriplet(test);
}
