/*
  Solution for: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices, int fee) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return dfs(prices, 0, 0, fee);
    }

    // state == 0: can buy
    // state == 1: can sell
    int dfs(vector<int>& prices, int i, int state, int fee) {
        if (i == prices.size()) return 0;
        if (dp[i][state] != -1) return dp[i][state];

        if (state == 0) {
            return dp[i][state] = max(-prices[i] + dfs(prices, i + 1, 1, fee), dfs(prices, i + 1, 0, fee));
        } else {
            return dp[i][state] = max(prices[i] - fee + dfs(prices, i + 1, 0, fee), dfs(prices, i + 1, 1, fee));
        }
    }
};

int main () {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout << Solution().maxProfit(prices, fee) << "\n";
    return 0;
}