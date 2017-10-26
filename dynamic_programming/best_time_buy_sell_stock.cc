// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int min_price = prices[0];

    for(int i=1;i<prices.size();i++) {
        if (prices[i] > min_price && max_profit < prices[i] - min_price) {
            max_profit = prices[i] - min_price; 
        }

        if (min_price > prices[i]) {
            min_price = prices[i];
        }
    }

    return max_profit;
}
