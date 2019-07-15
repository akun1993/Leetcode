#ifndef _MATRIX_SET_ZEROS_H__
#define _MATRIX_SET_ZEROS_H__

#include <vector>

// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

class SolutionMatrixSetZeros
{

public:

    int trap(vector<int>& height) 
    {   
        int total = 0;
        int beg = 0;
        int end = height.size() - 1;
        int reverse = true;

        while (beg < end)
        {
            /* code */
            if(reverse)
            {
                int area = 0;
                int flag = false;
                for(int j = beg + 1; j <= end;++j)
                {
                    if(height[j] >= height[beg])
                    {
                        beg = j;
                        flag = true;
                        break;
                    }
                    else
                    {
                        area +=  height[beg] - height[j];
                    }  
                }
                if(flag ) 
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
                for(int k = end - 1; k >= beg;--k)
                {
                    if(height[k] >= height[end])
                    {
                        end = k ;
                        flag = true;
                        break;
                    }
                    else
                    {
                        area +=  height[end] - height[k];
                    }
                }
                if(flag ) 
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
    //将矩阵中为0 的元素的所在行所在列的元素也值为零，只能操作原始矩阵中的0元素
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if(matrix.empty() || matrix[0].empty()) return;
        
        int x_len = matrix.size();
        int y_len = matrix[0].size();
        
        vector<bool > colum(y_len,false);
        vector<bool > row(x_len,false);
        
        for(int i = 0; i < x_len ;++i)
        {
            for(int j = 0;j < y_len;++j)
            {
                if(matrix[i][j] == 0)
                {
                    colum[j] = true;
                    row[i] = true;
                }   
            }
        }
        
        for(int i = 0;i < y_len;++i)
        {
            if(colum[i] == true)
            {
                for(int j = 0; j <x_len; ++j )
                {
                    matrix[j][i] = 0;
                }
            }
        }
        
        for(int i = 0;i < x_len;++i)
        {
            if(row[i] == true)
            {
                for(int j = 0; j <y_len; ++j )
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

}


#endif
