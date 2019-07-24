#ifndef _MATRIX_TRAPPING_RAIN_WATER_H__
#define _MATRIX_TRAPPING_RAIN_WATER_H__

#include <vector>
#include <ISolution.h>
#include <my_types.h>
#include <iostream>
using namespace std;

// Problem： 给定n个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// Figure Out ： area = width * height,   每个柱子宽度为1，但是每个柱子的高度不同，
// 单个柱子上面所能容纳的水取决去他左右两侧的柱子,假设当前柱子上面不能容纳水，可以推论 他的左右两侧不会同时出现高度高于他的柱子，因为根据
// 木桶原理，如果存在这样两个柱子，必然会使这个柱子上有水，且左右两侧同时出现高度高于他的柱子，是柱子存水的充要条件。
// 把问题划分成对间隔最小的两个没水的柱子做计算，算出这两个柱子之间的水，将每一个这个小段累加在一起最终得到结果。
//
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
class SolutionTrappingRainWater : public ISolution
{
private:
    /* data */
public:
    int trap(vector<int> &height)
    {
        int total = 0;
        int beg = 0;
        int end = height.size() - 1;
        int reverse = true;

        while (beg < end)
        {
            /* code */
            if (reverse)
            {
                int area = 0;
                int flag = false;
                for (int j = beg + 1; j <= end; ++j)
                {
                    if (height[j] >= height[beg])
                    {
                        beg = j;
                        flag = true;
                        break;
                    }
                    else
                    {
                        area += height[beg] - height[j];
                    }
                }
                if (flag)
                {
                    total += area;
                }
                else
                {
                    reverse = false;
                }
            }
            else
            {
                int area = 0;
                int flag = false;
                for (int k = end - 1; k >= beg; --k)
                {
                    if (height[k] >= height[end])
                    {
                        end = k;
                        flag = true;
                        break;
                    }
                    else
                    {
                        area += height[end] - height[k];
                    }
                }
                if (flag)
                {
                    total += area;
                }
                else
                {
                    reverse = true;
                }
            }
        }
        return total;
    }

    void answer()
    {

        vector<int> case_1 = {1, 1, 1, 2, 2, 3};

       int res = trap(case_1);
       cout << res << endl;
    }
};




#endif
