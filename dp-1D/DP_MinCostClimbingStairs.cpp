/*
  Solution for: https://leetcode.com/problems/min-cost-climbing-stairs/
*/

#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost);
int explore(vector<int>& cost, int i);

int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(cost);
    return 0;
}

vector<int> dp;
int minCostClimbingStairs(vector<int>& cost) {
    dp = vector<int>(cost.size(), -1);
    return min(explore(cost, 0), explore(cost, 1));
}

int explore(vector<int>& cost, int i) {
    if (i >= cost.size()) {
        return 0;
    }
    if (dp[i] != -1) return dp[i];

    return dp[i] = cost[i] + min(explore(cost, i + 1), explore(cost, i + 2));
}