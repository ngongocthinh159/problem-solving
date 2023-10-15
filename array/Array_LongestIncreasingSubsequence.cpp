/*
  Solution for: https://leetcode.com/problems/longest-increasing-subsequence
*/

#include <bits/stdc++.h>
using namespace std;

/* Function declaration */
int BinarySearch_lengthOfLIS(vector<int>& nums);
int DP_lengthOfLIS(vector<int>& nums);

/* Main()  function */
int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << BinarySearch_lengthOfLIS(nums);
}

// We do not need print LIS, we just need the length, so we can use binary search to replace some elems
// Suppose we have an result vector v
// - Each time see new number > the last elem of v => We push back to v
// - Or if the next number could not be append:
//   Current v:    1 2 3 6 7 8,     we reach 4  (4 can not be append before 8)
//   + We can replace 6 with 4 => 1 2 3 4 7 8
//   + So, now our LIS is actually not 1 2 3 4 7 8 but the length of the LIS is still correct
//   + And in the future when there is some better value > 4 and < 8 can also be replaced for 7, 8 like that
//   (we replace for hoping that we will take a better result in the future (the smaller nums the better))
//   + But if in the future there is no value > 4 and < 8, which mean we can not have LIS 1 2 3 4...
//   + Then notice that we still have a correct LIS length
int BinarySearch_lengthOfLIS(vector<int>& nums) {
    vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
        if (!v.size()) {v.push_back(nums[i]); continue;}    // There is no element in v => push_back
        auto it = lower_bound(v.begin(), v.end(), nums[i]);
        if (it != v.end()) {    // At least one elem >= cur
            if (*it != nums[i]) *it = nums[i];  // That lower_bound elem must be > cur => replace
                                                // Otherwise elem == cur => ignore (strictly increasing)
        } else v.push_back(nums[i]);            // All elem < cur => push_back
    }
    return v.size();
}

// Easy to do during the interview but O(n^2)
// dp[i] = 1 + max(all dp[j] where j > i and nums[j] > nums[i])
int DP_lengthOfLIS(vector<int>& nums) {
    dp = vector(nums.size(), -1);
    int res = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        int cur = LIS(nums, i);
        res = max(res, cur);
    }

    return res;
}

int LIS(vector<int>& nums, int i) {
    if (i == nums.size() - 1) return 1;
    if (dp[i] != -1) return dp[i];

    int ans = 0;
    for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] > nums[i]) {
            ans = max(ans, LIS(nums,j));
        }
    }
    return dp[i] = 1 + ans;
}