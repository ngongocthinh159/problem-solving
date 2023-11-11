/*
  Solution for: https://leetcode.com/problems/coin-change/
*/

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount);
int minAt(int amount, vector<int>& coins, vector<int>& dp);

int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << coinChange(coins, amount);

    return 0;
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -2);
    return minAt(amount, coins, dp);
}

int minAt(int amount, vector<int>& coins, vector<int>& dp) {
    if (amount == 0) return 0;
    if (dp[amount] != -2) return dp[amount];
    
    int res = INT_MAX;
    bool found = false;
    for (int i = 0; i < coins.size(); i++) {
        if (amount < coins[i]) continue;
        int tmp = minAt(amount - coins[i], coins, dp);
        if (tmp != -1 && res > tmp) {
            found = true;
            res = tmp;
        } 
    }
    if (!found) return dp[amount] = -1;
    return dp[amount] = res + 1;
}