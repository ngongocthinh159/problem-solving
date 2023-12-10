/*
  Solution for: https://leetcode.com/problems/subarray-sum-equals-k
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Idea to O(n): use Two Sum problem idea
        => Define the target, check if the target can be found in the previous indexes
        
        For each i, find relation: 
        pre[i] - pre[j] + nums[j] = k
        => target = k - pre[i] = nums[j] - pre[j] 
    */
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            pre[i] = i == 0 ? nums[i] : nums[i] + pre[i - 1];
        }
        unordered_map<int,int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k) ans++;
            int target = k - pre[i];
            ans += mp[target];

            // Update previous position cnt
            mp[nums[i] - pre[i]]++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    int k = 3;

    cout << Solution().subarraySum(nums, k);

    return 0;
}