/*
  Solution for: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return dfs(prices, 0, 0);
    }

    // state == 0: can buy
    // state == 1: can sell
    int dfs(vector<int>& prices, int i, int state) {
        if (i >= prices.size()) return 0;
        if (dp[i][state] != -1) return dp[i][state];

        if (state == 0) {
            return dp[i][state] = max(-prices[i] + dfs(prices, i + 1, 1), dfs(prices, i + 1, 0));
        } else {
            return dp[i][state] = max(prices[i] + dfs(prices, i + 2, 0), dfs(prices, i + 1, 1));
        }
    }
};

int main() {
    vector<int> prices = {1,2,3,0,2};
    cout << Solution().maxProfit(prices) << "\n";
    return 0;
}

