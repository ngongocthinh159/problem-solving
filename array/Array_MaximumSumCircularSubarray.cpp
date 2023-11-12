/*
  Solution for: https://leetcode.com/problems/maximum-sum-circular-subarray
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums);

int main() {
    vector<int> nums = {1,-2,3,-2};
    cout << maxSubarraySumCircular(nums);
    return 0;
}

// For normal subarray sum (not circular) => Use Kadane algorithm that:
// if the subarray end at index i, then should we concate the index i with previous max subarray? (by using max)

// For circular subarray:
// + Imagine our max subarray have two parts: one 1 head, one in tail
// => The middle part will be another subarray => We will try to find min subarray of middle part
// => Max subarray in both end = totalSum - minSubarray middle part
int maxSubarraySumCircular(vector<int>& nums) {
    vector<int> maxAt(nums.size());
    vector<int> minAt(nums.size());
    int res = maxAt[0] = minAt[0] = nums[0];
    int minSub = nums[0];
    int total = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        maxAt[i] = max(nums[i], nums[i] + maxAt[i - 1]);
        minAt[i] = min(nums[i], nums[i] + minAt[i - 1]);
        total += nums[i];
        res = max(res, maxAt[i]);
        minSub = min(minSub, minAt[i]);
    }
    return res < 0 ? res : max(res, total - minSub);
}