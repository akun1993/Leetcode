#ifndef _MATRIX_SET_ZEROS_H__
#define _MATRIX_SET_ZEROS_H__

#include <vector>
#include <ISolution.h>
#include <iostream>
using namespace std;


class SolutionMatrixSetZeros : public ISolution
{
public:

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

    void answer()
    {

    }

};


#endif
