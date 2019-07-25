#ifndef __TOP_K_BIG_
#define __TOP_K_BIG_

#include <vector>
#include "my_types.h"
#include <ISolution.h>
#include <iostream>
using namespace std;

// 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 示例 1:

// 输入: [3,2,1,5,6,4] 和 k = 2
// 输出: 5
// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
// 输出: 4
// 说明:
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

class SolutiontopkBig : public ISolution
{

public:

    int partionII(vector<int>& nums,int beg, int end)
    {
      //  if(beg >= end) return 0;

        int pivot = nums[beg];
        int idx = beg;
       // cout << pivot << " " << beg << " " << end  << "," << endl;
        while(beg < end)
        {
            while(end > idx && pivot >= nums[end] ) --end;

            nums[idx] = nums[end];
            idx = end;

            while (beg < idx && pivot < nums[beg] ) ++beg;
            nums[idx] = nums[beg];
            idx = beg;

            //cout << beg << " " << end  << "," << endl;
        }
        cout << beg << " " << end  << "," << endl;
        nums[idx] = pivot;

        return idx;

    }

    int partion(vector<int>& nums,int beg, int end)
    {
      //  if(beg >= end) return 0;

        int pivot = nums[beg];
        int m = beg;
        while(beg < end)
        {
            while( pivot > nums[end] ) --end;

            while (pivot <= nums[beg] ) ++beg;
            
            if(beg < end)
            {
                int tmp = nums[beg];
                nums[beg] = nums[end];
                nums[end] = tmp;
            }else break;

            //cout << beg << " " << end  << "," << endl;
        }
        cout << beg << " " << end  << "," << endl;
        cout << nums[m] << " "<< nums[beg] << " " << nums[end]  << "," << endl;
        nums[m] = nums[end]; nums[end] = pivot;
        return end;

    }

    void quickSort(vector<int>& nums,int beg, int end,int k)
    {
        if(beg >= end) return ;
        int index = partionII(nums,beg, end); 
            
        if (index == k - 1 )
        {
            return  ;
        }else if(index > k - 1  )
        {
           return quickSort(nums,beg,index - 1,k  ); 
        }
        else
        {
            return quickSort(nums,index + 1, end,k);
        }
    }    

    int findKthLargest(vector<int>& nums, int k)
    {
        if(nums.empty()) return 0;
        if(k < 0 || k > (int)nums.size()) return 0;
        
        quickSort(nums,0,nums.size() - 1,k);

        return nums[k-1];
    }
    
    void answer()
    {
        vector<int> case_1 = {3,2,1,5,6,4};
        int idx = 0;
        idx = findKthLargest(case_1,4);
        for (u32 i = 0; i < case_1.size(); i++)
        {
            /* code */
            cout << case_1[i] << ",";
        }
        cout << endl << " k is 4 " <<idx << endl;  
        
        vector<int> case_2 =  {3,2,3,1,2,4,5,5,6};

        idx = findKthLargest(case_2,5);
        for (u32 i = 0; i < case_2.size(); i++)
        {
            /* code */
            cout << case_2[i] << ",";
        }
        cout << endl << " k is 5 " << idx << endl;       

        vector<int> case_3 =  {2,1};

        idx = findKthLargest(case_3,2);
        for (u32 i = 0; i < case_3.size(); i++)
        {
            /* code */
            cout << case_3[i] << ",";
        }
        cout << endl << " k is 2 " << idx << endl;    
        

        vector<int> case_4 =  {3,2,3,1,2,4,5,5,6};

        idx = findKthLargest(case_4,4);
        for (u32 i = 0; i < case_4.size(); i++)
        {
            /* code */
            cout << case_4[i] << ",";
        }
        cout << endl << " k is 4 " << idx << endl;            

    }
};


#endif