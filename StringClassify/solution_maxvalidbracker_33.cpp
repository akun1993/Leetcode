#include "solution_maxvalidbracker_33.h"

int SolutionMaxValidBracker::longestValidParentheses(string s) {
        
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

               //cout <<"right_max" <<right_max << endl;
                
                while(!st.empty())
                {
                    Record_t tmp = st.top();
                    st.pop();
                    
                    if(re.idx - tmp.idx > 1 && re.idx - tmp.idx > max_valid)
                    {
                        max_valid = re.idx - tmp.idx - 1;
                       // cout << "Record_t" << max_valid << endl;
                    }
                    re = tmp;
                }
                
                int left_max = re.idx - begin;
                if(left_max > max_valid)
                {
                    max_valid = left_max;
                }
             //   cout << "left_max" << left_max << endl;
                
            }
           // cout << "max_valid" << max_valid << endl;
        }
        
        return max_valid;
        
    }

   int SolutionMaxValidBracker::longestValidParenthesesII(string s) {
        
        
        if(s.size() <= 1) return 0;
        
        int max_valid = 0;
        size_t i = 0;
        
        while(i < s.size())
        {
            int left = 0;
            int right = 0;

            //如果这是个右括号，这时前面还没有右括号，则不是有效的括号，丢弃   
            while(i < s.size() && s[i] == ')')
                ++i;
            
            if(i >= s.size()) break;

            stack<char> st;

            //左括号大于等于右括号说明可能是有效的括号，加入栈中
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
            //计算有效的括号,这时候左括号大于等于右括号
            while(!st.empty())
            {
                char  top_c = st.top();
                st.pop();
                
                //丢弃无效的左括号
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

    void SolutionMaxValidBracker::answer()
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

