#include "stock.h"

int Stock::maxProfit(vector<int>& prices){
    int n = prices.size();
    int minPrice = prices[0];
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++){
        minPrice = min(minPrice, prices[i]);
        dp[i] = max(dp[i - 1], prices[i] - minPrice);
    }
    return dp[n - 1];
}