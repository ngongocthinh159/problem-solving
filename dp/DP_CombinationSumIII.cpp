/**
 * Solution for: https://leetcode.com/problems/combination-sum-iv/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0LL);
        dp[0] = 1LL;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};

int main() {
    vector<int> nums = {1,2,3};
    int target = 4;
    cout << Solution().combinationSum4(nums, target);
    return 0;
}