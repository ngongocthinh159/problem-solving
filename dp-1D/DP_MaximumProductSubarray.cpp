/*
  Solution for: https://leetcode.com/problems/maximum-product-subarray
*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums);

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums);
    return 0;
}

int maxProduct(vector<int>& nums) {
    // Keep track that, if the end of sub-array is index i
    // Then what is the max/min product of sub-array ending with index i
    // This is actually like the Kadane algorithm but adding the minimum keep track
    vector<int> minProd(nums.size(), -1);
    vector<int> maxProd(nums.size(), -1);
    minProd[0] = nums[0];
    maxProd[0] = nums[0];
    int res = INT_MIN;
    for (int i = 1; i < nums.size(); i++) {
        minProd[i] = min(nums[i], min(maxProd[i - 1]*nums[i], minProd[i - 1]*nums[i]));
        maxProd[i] = max(nums[i], max(maxProd[i - 1]*nums[i], minProd[i - 1]*nums[i]));
        res = max(res, maxProd[i]);
    }
    res = max(res, maxProd[0]);
    return res;
}