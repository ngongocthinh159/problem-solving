/*
  Solution for: https://leetcode.com/problems/house-robber-ii/
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

// For circular case:
// + We choose "can not rob" the first house => Freely rob from [1, n-1]
// + We choose "can rob" the first house => Freely rob from [0, n-2]
int rob(vector<int>& nums) {
    // Can not rob the first house
    if (nums.size() == 1) return nums[0];
    vector<int> dp(nums.size(), -1);
    int tmp1 = dfs(nums,1,dp);  // Start from index 1

    // Can rob the first house
    nums.pop_back(); // If rob first house => Pop back last house
    vector<int> dp2(nums.size(), -1);
    int tmp2 = dfs(nums,0,dp2); // Start from index 0

    // Get max among two options
    return max(tmp1,tmp2);
}

int dfs(vector<int>& nums, int i, vector<int>& dp) {
    if (i >= nums.size()) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = max(nums[i] + dfs(nums, i + 2, dp), dfs(nums, i + 1, dp));
}