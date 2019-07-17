#ifndef __MAX_VALID_BRACKER_H_
#define __MAX_VALID_BRACKER_H_

class SolutionMaxValidBracker {
public:
    
    struct Record_s
    {
        Record_s(int c,int idx):c(c),idx(idx) {}
        int  c;
        int  idx;
    };

    typedef  struct Record_s Record_t;
    
    int longestValidParentheses(string s) {
        
        if(s.size() <= 1) return 0;
        
        int max_valid = 0;
        size_t i = 0;
        while(i < s.size())
        {
            int left = 0;
            int right = 0;
            
            while(i < s.size() && s[i] == ')')
                ++i;
            
            if(i >= s.size()) break;

            stack<Record_t> st;

            int begin = i;

            while(i < s.size() && left >= right)
            {
                if(!st.empty())
                {
                    Record_t record = st.top();

                    if( record.c == '(' && s[i] == ')' )
                    {
                        st.pop();
                        --left;
                        ++i;
                        continue;
                    }
                }

                if(s[i] == '(')
                {
                    ++left;
                }
                else
                {
                    ++right;
                }
                
                Record_t new_record(s[i],i);
                st.push(new_record);
        
                ++i;
            }
            
            if(right > left)
            {
                st.pop();
                --i;
            }
            
            if(st.empty())
            {
                int cur_valid = i - begin ;
                if(max_valid < cur_valid)
                {
                    max_valid = cur_valid;
                }
            }
            else
            {
                Record_t re = st.top();
                st.pop();
                
                int right_max = i - re.idx - 1;
                
                if(right_max > max_valid)
                {
                    max_valid = right_max;
                }

               cout <<"right_max" <<right_max << endl;
                
                while(!st.empty())
                {
                    Record_t tmp = st.top();
                    st.pop();
                    
                    if(re.idx - tmp.idx > 1 && re.idx - tmp.idx > max_valid)
                    {
                        max_valid = re.idx - tmp.idx - 1;
                        cout << "Record_t" << max_valid << endl;
                    }
                    re = tmp;
                }
                
                int left_max = re.idx - begin;
                if(left_max > max_valid)
                {
                    max_valid = left_max;
                }
                cout << "left_max" << left_max << endl;
                
            }
            cout << "max_valid" << max_valid << endl;
        }
        
        return max_valid;
        
    }

   int longestValidParenthesesII(string s) {
        
        
        if(s.size() <= 1) return 0;
        
        int max_valid = 0;
        size_t i = 0;
        while(i < s.size())
        {
            int left = 0;
            int right = 0;
            
            while(i < s.size() && s[i] == ')')
                ++i;
            
            if(i >= s.size()) break;

            stack<char> st;

            while(i < s.size() && left >= right)
            {
                char c = s[i];
                c == '(' ?  ++left : ++right;
                if(right > left)
                {
                    break;
                }
                st.push(c);
                ++i;
            }
        
            int end = 0;
            int count = 0;
            
            while(!st.empty())
            {
                char  top_c = st.top();
                st.pop();
                    
                if(count == 0 && top_c == '(')
                {
                    if(end > max_valid)
                    {
                        max_valid = end;
                        //cout << "left_max" << max_valid << endl;
                    }
                    end = 0;
                    continue;
                }
                top_c == '(' ? --count : ++count;

                ++end;
                
            }
            if(end > max_valid) max_valid = end;
            //cout << "max_valid" << max_valid << endl;  
        }
        return max_valid;
        
    }

    void answer()
    {


        string case_1 = ")()())";// test = {1,2,1,7,9,2,4,5};

        longestValidParenthesesII(case_1);

        cout <<case_1 << endl;

        string case_2 = ")()())()()()()(((((";// test = {1,2,1,7,9,2,4,5};

        longestValidParenthesesII(case_2);

        cout <<case_2 << endl;

        string case_3 = "(()";// test = {1,2,1,7,9,2,4,5};

        longestValidParenthesesII(case_3);

        cout<<case_3<< endl;

        string case_4 = ")(((((()())()()))()(()))(";
        longestValidParenthesesII(case_4);
        cout<<case_4<< endl;
    }

};
#endif