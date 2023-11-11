/*
  Solution for: https://leetcode.com/problems/climbing-stairs/
*/

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n);
int dfs(int n, int steps, vector<int>& dp);

int main() {
    cout << climbStairs(3);
    return 0;
}

int climbStairs(int n) {
    vector<int> dp(n, -1);
    return dfs(n, 0, dp);
}

int dfs(int n, int steps, vector<int>& dp) {
    if (steps > n) return 0;
    if (steps == n) return 1;
    
    if (dp[steps] != -1) return dp[steps];
    return dp[steps] = dfs(n, steps + 1, dp) + dfs(n, steps + 2, dp);
}