/*
  Solution for: https://leetcode.com/problems/find-peak-element
*/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums);

int main() {
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << findPeakElement(nums);
    return 0;
}

int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + (r - l)/2;

        // Stop conditions
        if (m == 0 && m + 1 < nums.size() && nums[m] > nums[m + 1]) { // Outer left
            return m;
        } else if (m == nums.size() - 1 && m - 1 >= 0 && nums[m] > nums[m - 1]) { // Outer right
            return m;
        } else if (0 <= m - 1 && m + 1 < nums.size() && nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) { // Peak elem
            return m;
        }

        // Always go to the half that have bigger elem
        // => In the end, we will reach the peak elem
        if (m - 1 >= 0 && nums[m] < nums[m - 1]) {
            r = m - 1;
        } else if (m + 1 < nums.size() && nums[m] < nums[m + 1]) {
            l = m + 1;
        } else { // Go random, when mid elem smaller than both left and right
            r = m - 1;
        }
    }
    return -1;
}