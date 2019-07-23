#ifndef __SOLUTION_DIVIDE_H_
#define __SOLUTION_DIVIDE_H_

#include <ISolution.h>
using namespace std;

class SolutionDivide : public ISolution
{
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == 0) return 0;
        
        bool is_neg = false;
        if(dividend < 0 && divisor > 0) 
        {
            divisor = -divisor;
            is_neg = true;
        }
        if(dividend > 0 && divisor < 0) 
        {
            dividend = -dividend;
            is_neg = true;
        }
        if(dividend > 0 && divisor > 0) 
        {
            dividend = -dividend;
            divisor = -divisor;
        }
        
        int val = 0;
        int ret = 0;
        while( val >= dividend - divisor)
        {
            val += divisor;
            ret -= 1;
        }
        
        if(is_neg)
        {
            return ret;    
        }
        else
        {
            if(ret == (-(int)(~0U >> 1) - 1))
                ret = -(int)(~0U >> 1);
            return -ret;
        }
        
    }

    void answer()
    {
        int ret = divide(-2147483648,-1);

        cout << "ret is " << ret << endl;
    }

};

#endif
