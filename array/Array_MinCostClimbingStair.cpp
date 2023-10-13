/*
  Solution for: https://leetcode.com/problems/min-cost-climbing-stairs
*/

#include <bits/stdc++.h>
using namespace std;

/* Function declaration */
int minCostClimbingStairs(vector<int>& cost);
int minCost(int i, vector<int>& cost);

/* Main()  function */
int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(cost);
}

vector<int> dp;

int minCostClimbingStairs(vector<int>& cost) {
    dp = vector(cost.size(), -1);
    return min(minCost(0, cost), minCost(1, cost));
}

int minCost(int i, vector<int>& cost) {
    if (i >= cost.size()) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = cost[i] + min(minCost(i + 1, cost), minCost(i + 2, cost));
}

/* Main() Ends Here */