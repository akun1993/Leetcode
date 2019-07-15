#ifndef __SOLUTION_LONGEST_SUBSTRING_H_
#define __SOLUTION_LONGEST_SUBSTRING_H_

class SolutionLongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() <= 1) return s.size();
        
        int sum[256] = {0};
        
        int max_len = 0;
        int tmp = 0;
        int begin = 0;
        
        for(size_t i = 0; i < s.size() ; ++i)
        {   
            int idx = s[i];
            if(sum[idx] == 0)
            {
                ++tmp; 
            }
            else
            {
                int len = sum[idx] - begin ;

                if(tmp > max_len) max_len = tmp;

                for(int j = begin;j < begin + len; ++j)
                {
                    int idx_j = s[j];
                    sum[idx_j] = 0;
                }
                tmp -= (len - 1);
                begin += len; 
            }
            sum[idx] = i + 1;
        }
        
        return tmp > max_len ? tmp : max_len;
    }

    int lengthOfLongestSubstringII(string s) {
        
        if(s.size() <= 1) return s.size();
        
        int sum[256] = {0};
        
        int max_len = 0;

        int begin = 0;
        
        for(int i = 0; i < (int)s.size() ; ++i)
        {   
            int idx = s[i];
            begin = sum[idx] > begin ? sum[idx] : begin;

            max_len = (i - begin + 1) > max_len ? (i - begin + 1) : max_len;

            sum[idx] = i + 1;
        }
        
        return max_len;
    }

    void answer()
    {


    }

};



#endif
