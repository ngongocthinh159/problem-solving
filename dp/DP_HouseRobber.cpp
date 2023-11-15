/*
  Solution for: https://leetcode.com/problems/house-robber/
*/

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums);
int dfs(vector<int>& nums, int i, vector<int>& dp);

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums);
    return 0;
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return dfs(nums, 0, dp);
}

int dfs(vector<int>& nums, int i, vector<int>& dp) {
    if (i >= nums.size()) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = max(dfs(nums, i + 1, dp), nums[i] + dfs(nums, i + 2, dp));
}