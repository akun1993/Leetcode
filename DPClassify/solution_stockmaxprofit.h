#ifndef __SOLUTION_STOCK_MAX_PROFIT_H_
#define __SOLUTION_STOCK_MAX_PROFIT_H_

#include <vector>
#include <ISolutionBase.h>
using namespace std;

class SolutionStockMaxProfit : public ISolutionBase
{
public:
    SolutionStockMaxProfit(
        const char *name,
        const char * problem_desc,
        int number,
        ISolutionBase::Difficulty lv,
        unsigned int flag
    ): ISolutionBase(name,problem_desc,number,lv,flag)
    {
      
    }
    ~SolutionStockMaxProfit(){}
    void __profit(vector<int>& prices,int idx, int buy_price,int status,int cur_profit,vector<int> &memo,int &max_profit);
    int maxProfitII(vector<int>& prices);

    int maxProfit(vector<int>& prices);
    int maxProfitIII(vector<int>& prices);
    void answer();

};

#endif
