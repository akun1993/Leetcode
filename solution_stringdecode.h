#ifndef __SOLUTION_STRING_DECODE_
#define __SOLUTION_STRING_DECODE_

#include <string>

class SolutionStringDecode {
public:
    
    void __decode(string &s,int beg,int &end,int &breaket,string &str)
    {
        if(beg >= (int)s.size()) 
        {
            end = beg;
            return;   
        }

        if(isdigit(s[beg]))
        {
            int num = 0;
            while(isdigit(s[beg]))
            {
                num = num * 10 + (s[beg] - '0');
                ++beg;
            }
            ++breaket;
            string tmp;
            __decode(s,beg + 1,end,breaket,tmp);    
            while(num >0)
            {
                str.append(tmp);
                --num;
            }
            if(breaket != 0)
            {
                string  oth;
                __decode(s,end + 1,end,breaket,oth); 
                str.append(oth);
            }
        }
        else
        {
            string sub;
            while(isalpha(s[beg]))
            {
                sub.append(1,s[beg++]);
            }
            if(isdigit(s[beg]))
            {
                string  tmp;
                __decode(s,beg,end,breaket,tmp); 
                sub.append(tmp);
            }
            str.append(sub);
            if(s[beg] == ']' || beg >= (int)s.size())
            {
                --breaket;
                end = beg;
            }
        }
    }
    
    string decodeString(string s) {
                
        string str;

        for(int i = 0; i < (int)s.size();)
        {
            int end;
            string tmp;
            int breaket = 0;
            __decode(s,i,end,breaket,tmp);
            str.append(tmp);
            i = end + 1;
            
           // cout <<"tmp is " <<tmp<<"  end is"<< end << endl;  
        }

        return str;
        
    }

    void answer()
    {
        string encode_str = "2[abc]3[cd2[d]ef2[d]]ef";
        string str =   decodeString(encode_str);
        cout <<str<< endl;  
    }
};

#endif
