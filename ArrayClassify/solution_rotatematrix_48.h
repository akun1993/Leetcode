#ifndef __SOLUTION_ROTATE_MATRIX_H_
#define __SOLUTION_ROTATE_MATRIX_H_

#include <vector>
#include <ISolution.h>
using namespace std;

class SolutionRotateMatrix : public ISolution
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {

        if(matrix.size() == 0) return  ;
        if(matrix[0].size() != matrix.size()) return ;

        int matrix_size =  matrix.size();
       
        for(int i = 0; i < (matrix_size + 1) / 2; ++i)
        {
            for(int j = i; j < matrix_size - i - 1; ++j)
            {
                int trans_x = i;
                int trans_y = j;

                int bef_val = matrix[i][j];
               
                int cycle_idx = 0;
                while( cycle_idx < 4)
                {
                    int x = trans_x;
                    trans_x =  trans_y ;
                    trans_y = matrix_size - x - 1; 

                    int tmp = bef_val;
                    bef_val = matrix[trans_x][trans_y];
                    matrix[trans_x][trans_y] = tmp;
                    ++cycle_idx;
                }

            }
        }
    }

    void printmatrix(vector<vector<int> > &matrix)
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix.size(); j++)
            {
                /* code */
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void answer()
    {
        
        vector<vector<int> > matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        printmatrix(matrix);

        cout << endl;
        rotate(matrix);
        printmatrix(matrix);

    }

};

#endif
