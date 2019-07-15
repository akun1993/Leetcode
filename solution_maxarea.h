#ifndef __SOLUTION_MAXAREA_H_
#define __SOLUTION_MAXAREA_H_

#include <vector>
using namespace std;

class SolutionMaxArea{
public:
    int maxArea(vector<int>& height) {

        int max_area = 0;
        if(height.size() < 2) return max_area;

        for(int i = 0; i < (int)height.size(); ++i)
        {
            int y1 =  height[i];

            for(int j = i + 1; j < (int)height.size(); ++j)
            {
                int y2 = height[j];

                int min_y = y1 > y2 ? y2 : y1;

                if( min_y * (j - i) >  max_area)
                {
                    max_area = min_y * (j - i);
                }
                if(y2 >= y1 || y1 * (j - i -1 ) <= max_area) break; 
            }
        }

        return max_area;
    }

    void answer()
    {
        vector<int> height = {1,8,6,2,5,4,8,3,7};
        int max_area = maxArea(height);

        cout <<"answer is " << max_area <<endl;
    }

};

#endif
