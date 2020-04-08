#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#define BUY 1
#define SELL 0
using namespace std;
//Best Time to Buy and Sell Stock II
int maxProfit(vector<int> &prices);
int main()
{
    int state = BUY; //define initial state as buy
    vector<int> array = {

        7,
        1,
        5,
        3,
        6,
        4, 
        10};
    return maxProfit(array);
}
//either buy or sell
//if you bought, you have to just sell
//if you sell, you have to buy
int maxProfit(vector<int> &prices) {
    int total_profit = 0;
    if (prices.size() <= 1)
    {
        return 0;
    }
    else {
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {//then we sell
                //if profit is not negative
                //then we buy at i-1 and sell 
                total_profit += prices[i] - prices[i - 1];
            }
            else {//else we ignore and set profit += 0
                total_profit += 0;
            }
        }
    }
    cout << "Total Profit " << total_profit << endl;
       return total_profit;
}