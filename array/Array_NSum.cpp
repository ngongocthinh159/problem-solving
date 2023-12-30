/**
 * Solution for: https://leetcode.com/problems/4sum/
 * Solution for: https://leetcode.com/problems/3sum/
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Generalization for k-sum (sum of k numbers) that are unique tuples equal to target
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        kSum(4, 0, nums, target);
        return res;
    }

    void kSum(int k, int start, vector<int> &nums, long long target) {
        if (k > nums.size() || k == 0) return;
        if (k == 1) {
            for (auto num : nums)
                if (num==target) res.push_back({num});
            return;
        }
        
        if (k == 2) {
            int l = start, r = nums.size() - 1;
            while (l < r) {
                if (1LL*nums[l] + nums[r] > target) {
                    r--;
                } else if (1LL*nums[l] + nums[r] < target) {
                    l++;
                } else {
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    res.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    l++; r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }

            return;
        }

        for (int i = start; i <= nums.size() - k; i++) {
            if (i != start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            kSum(k - 1, i + 1, nums, 1LL*target - nums[i]);
            path.pop_back();
        }
    }
};