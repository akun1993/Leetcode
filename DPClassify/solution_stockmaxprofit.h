#ifndef __SOLUTION_STOCK_MAX_PROFIT_H_
#define __SOLUTION_STOCK_MAX_PROFIT_H_

#include <vector>
#include <ISolutionBase.h>

class SolutionStockMaxProfit : public ISolutionBase
{
public:
    void __profit(vector<int>& prices,int idx, int buy_price,int status,int cur_profit,vector<int> &memo,int &max_profit);
    int maxProfitII(vector<int>& prices) ;

    int maxProfit(vector<int>& prices)
    int maxProfitIII(vector<int>& prices);
    void answer();

};

#endif
