/*
  Solution for: https://leetcode.com/problems/3sum
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getCost(int l, int r, vector<long long> &prf, vector<int> &nums) {
        int m = l + (r - l)/2;
        int median = nums[m];
        long long leftCost = 1LL*(m - l + 1)*median - (prf[m] - prf[l] + nums[l]);
        long long rightCost = 1LL*(prf[r] - prf[m] + nums[m]) - 1LL*(r - m + 1)*median;
        return leftCost + rightCost;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        vector<long long> prf(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            prf[i] = i == 0 ? 1LL*nums[i] : 1LL*nums[i] + prf[i - 1];
        }
        int mx = INT_MIN;
        int l = 0, r = 0;
        while (r < nums.size()) {
            long long cost = getCost(l, r, prf, nums);
            
            // invalid window
            while (cost > k) {
                l++;
                cost = getCost(l, r, prf, nums);
            }

            // valid window
            mx = max(mx, r - l + 1);

            r++;
        }
        return mx;
    }
};

int main() {
    vector<int> nums = {1,2,6,4};
    long long k = 3;
    cout << Solution().maxFrequencyScore(nums, k);
    return 0;
}