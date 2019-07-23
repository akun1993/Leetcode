
#ifndef __MAXIMAL_RECTANGLE_H_
#define __MAXIMAL_RECTANGLE_H_

#include <vector>
#include <ISolution.h>
using namespace std;

class SolutionMaximalRectangle : public ISolution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
     {
        
        
        vector<vector<int> > vals(matrix.size(),vector<int> (matrix[0].size(),0));
        int max_area = 0;
        for(size_t i = 0; i < matrix.size(); ++i)
        {
            
            //vals[i][0] = matrix[i][0] == '1' ? 1 : 0;
            
            for(size_t j = 1; j < matrix[0].size(); ++j)
            {
                if(j == 0)
                     vals[i][0] = matrix[i][0] == '1' ? 1 : 0;
                else
                {
                    if(matrix[i][j] == '0')
                        vals[i][j] = 0;
                    else
                        vals[i][j] = vals[i][j - 1] + 1;  
                }
                cout << vals[i][j] << " ";
                max_area = vals[i][j] > max_area ? vals[i][j] : max_area;
                if(vals[i][j] > 0)
                {
                   
                    int m = 1;
                    int min = vals[i][j];
                    while((int)i >= m)
                    {
                        if(vals[i - m][j] == 0)
                            break;
                        min = min > vals[i -m][j] ? vals[i -m][j] : min;
                        ++m;
                        if(min * m > max_area)
                            max_area = min * m ;
                    }
                   
                }
                
            }
            cout << endl;
            
        }
         return max_area;
    }

    void answer()
    {
        vector<vector<char>> case_1 = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'},
        };

        vector<vector<char>> case_2 =  {
            {'1','0','1','1','1'},
            {'0','1','0','1','0'},
            {'1','1','0','1','1'},
            {'1','1','0','1','1'},
            {'0','1','1','1','1'},
        };


        int max_area = maximalRectangle(case_1);

        cout << max_area << endl;

         max_area = maximalRectangle(case_2);
        cout << max_area << endl;
    }


    int largestRectangleArea(vector<int>& heights) 
    {

        if(heights.empty()) return 0;
        int max_area = heights[0];

        for (size_t i = 0; i < heights.size(); i++)
        {
           if(i > 0 && heights[i] <= heights[i - 1]) continue;
          
            int min = heights[i];

            max_area = max_area > min ? max_area : min;    
            
            int cur_area = heights[i];
            
            for (size_t j = i + 1; j < heights.size(); ++j)
            {
                /* code */
                if(min > heights[j])
                {
                    min =  heights[j];
                    cur_area = min * (j - i + 1);
                }
                else
                {
                    cur_area = cur_area + min;
                }
                max_area = max_area > cur_area ? max_area : cur_area;  
            }
        }
        
        return max_area;
    }

    void GetMaxArea(vector<int>& heights,int beg,int end,int &max_area)
    {
        if(beg >= end) return;
        int min = heights[beg];
        int min_idx = beg;
        for (int j = beg; j < end; ++j)
        {
            /* code */
            if(min > heights[j])
            {
                min =  heights[j];
                min_idx = j;
            }
        }
        int area = min * (end - beg);
        max_area = max_area > area ? max_area : area;  
        
        if(min_idx != beg)
            GetMaxArea(heights,beg,min_idx ,max_area);   
            
           
        if(min_idx != end - 1)
            GetMaxArea(heights,min_idx + 1,end,max_area);
            

    }
    
    
    int largestRectangleAreaII(vector<int>& heights) {
        
        
        if(heights.empty()) return 0;
        int max_area = 0;
        GetMaxArea(heights,0,(int)heights.size(),max_area);
        return max_area;
    
        
    } 

    int largestRectangleAreaIII(vector<int>& heights) {
        if(heights.empty()) return 0;
        int max_area = heights[0];
        
        int height = 0;
        
        for(size_t i = 0;i < heights.size(); ++i)
        {
            int cur_height =   heights[i];
            
            if(cur_height == height) continue;
            
            height = cur_height;
            
            int beg = i;
            int end = i;
            
            while(beg >= 0)
            {
                if(heights[beg] >= height)
                    --beg;
                else
                    break;
            }
            
            while(end < (int)heights.size())
            {
                if(heights[end] >= height)
                   ++end;
                  else
                   break;
            }
                   
            if(max_area < (end - beg - 1) * height)
                   max_area = (end - beg - 1) * height;
        }
        
        return max_area;
    }     

};

#endif

