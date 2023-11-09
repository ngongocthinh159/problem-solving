/*
  Solution for: https://leetcode.com/problems/sort-colors
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums);

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int n = removeDuplicates(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 0;
    while (i < nums.size()) {
        int prev = nums[i++];
        while (i < nums.size() && nums[i] == nums[i - 1]) {
            i++;
        }
        nums[j] = prev;
        j++;
    }
    return j;
}