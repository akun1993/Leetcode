#include "solution_stockmaxprofit_309.h"
#include <iostream>

void SolutionStockMaxProfit::__profit(vector<int> &prices, int idx, int buy_price, int status, int cur_profit, vector<int> &memo, int &max_profit)
{
    if (idx >= (int)prices.size())
    {
        if (cur_profit > max_profit)
            max_profit = cur_profit;
        return;
    }

    if (status == 1) //上一步为卖出
    {
        if (cur_profit < memo[idx])
            return;
        __profit(prices, idx + 1, -1, 0, cur_profit, memo, max_profit);
        if (cur_profit > memo[idx])
        {
            memo[idx] = cur_profit;
        }
    }
    if (status == 0) //上一步不操作
    {
        if (buy_price == -1)
        {
            //if(cur_profit < memo[idx]) return;
            __profit(prices, idx + 1, prices[idx], 0, cur_profit, memo, max_profit);
            __profit(prices, idx + 1, -1, 0, cur_profit, memo, max_profit);
        }
        else
        {
            __profit(prices, idx + 1, buy_price, 0, cur_profit, memo, max_profit);
            if (buy_price != -1)
                cur_profit += prices[idx] - buy_price;

            __profit(prices, idx + 1, buy_price, 1, cur_profit, memo, max_profit);
        }
    }
}
int SolutionStockMaxProfit::maxProfitII(vector<int> &prices)
{

    int max_profit = 0;
    vector<int> memo(prices.size(), -1);
    __profit(prices, 0, -1, 0, 0, memo, max_profit);

    return max_profit;
}

int SolutionStockMaxProfit::maxProfit(vector<int> &prices)
{

    // int max_profit = 0;
    if (prices.empty())
        return 0;

    vector<vector<int>> profit(prices.size(), vector<int>(prices.size(), 0));
    vector<int> max_profit(prices.size(), 0);
    for (size_t i = 0; i < prices.size(); ++i)
    {
        for (size_t j = i + 1; j < prices.size(); ++j)
        {
            if (i == 0)
            {
                if (prices[j] > prices[0])
                {
                    profit[j][i] = prices[j] - prices[0];
                    max_profit[j] = profit[j][i];
                }
            }
            else
            {
                int cur_profit = 0;
                if (i >= 2)
                    cur_profit = max_profit[i - 2];

                if (prices[j] > prices[i])
                    cur_profit += prices[j] - prices[i];
                profit[j][i] = cur_profit > max_profit[j - 1] ? cur_profit : max_profit[j - 1];

                if (max_profit[j] < profit[j][i])
                    max_profit[j] = profit[j][i];
            }
        }
    }
    return max_profit[max_profit.size() - 1];
}

int SolutionStockMaxProfit::maxProfitIII(vector<int> &prices)
{

    // int max_profit = 0;
    if (prices.empty())
        return 0;

    vector<int> max_profit(prices.size(), 0);
    for (size_t i = 0; i < prices.size(); ++i)
    {
        for (size_t j = i + 1; j < prices.size(); ++j)
        {
            if (i == 0)
            {
                if (prices[j] > prices[0])
                {
                    max_profit[j] = prices[j] - prices[0];
                }
            }
            else
            {
                int cur_profit = 0;
                if (i >= 2)
                    cur_profit = max_profit[i - 2];
                if (prices[j] > prices[i])
                    cur_profit += prices[j] - prices[i];
                int max_j = cur_profit > max_profit[j - 1] ? cur_profit : max_profit[j - 1];
                if (max_profit[j] < max_j)
                    max_profit[j] = max_j;
            }
        }
    }
    return max_profit[max_profit.size() - 1];
}

void SolutionStockMaxProfit::answer()
{
    vector<int> test_case_1 = {1, 2, 3, 0, 2};

    int ret = maxProfit(test_case_1);

    vector<int> test_case_2 = {48, 12, 60, 93, 97, 42, 25, 64, 17, 56, 85, 93, 9, 48, 52, 42, 58, 85, 81, 84, 69, 36, 1, 54, 23, 15, 72, 15, 11, 94};
    ret = maxProfit(test_case_2);
    cout << "max profit is " << ret << endl;

    vector<int> test_case_3 = {6, 1, 6, 4, 3, 0, 2};
    ret = maxProfit(test_case_3);
    cout << "max profit is " << ret << endl;
}
