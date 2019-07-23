#ifndef __SOLUTION_PERMUTE_H_
#define __SOLUTION_PERMUTE_H_

#include <vector>
#include <ISolution.h>
using namespace std;

//����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�

class SolutionPermuteII : public ISolution
{
  public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int> > result;

        if(nums.empty()) return result;

        int count = nums.size();

        vector<int> arr(nums.size(),1);

        int i = 0;

        while(true)
        {
            bool flag = true;
            for(int j = 0; j < i;++j)
            {
                if(arr[j] == arr[i])
                {
                    flag = false;
                    break;
                }
            }

            if(flag && i == count - 1)
            {
                vector<int> one;
                for(int j = 0; j < count; ++j)
                {
                    one.push_back(nums[arr[j] - 1]);

                    //cout << arr[j] << " ";
                }
                result.push_back(one);
            }

            if(flag && i < count - 1)
            {
                ++i;
                arr[i] = 1;
                continue;
            }

            while(i >=0 && arr[i] == count )
            {
                --i;
            }

            if(i >= 0)
                ++arr[i];
            else
                break;
        }
        return result;
    }

    void answer()
    {
        vector<int> nums;

        int key = 0;
        for(int i = 0; i < 3; ++i)
        {
            nums.push_back(i + key);

            key = key + 6;
        }

        vector<vector<int>>  result = permute(nums);

        for(int i = 0; i < (int)result.size(); ++i)
        {
            for(int j = 0; j < (int)result[i].size(); ++j)
            {
                cout << result[i][j] << " ";

            }
             cout << endl;
        }

    }

};

#endif // __SOLUTION_PERMUTE_H_
