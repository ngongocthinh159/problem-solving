/*
  Solution for: https://leetcode.com/problems/contains-duplicate-ii
*/

#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k);

int main() {
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout << (containsNearbyDuplicate(nums, k) ? "true" : "false");
    return 0;
}

// Hashset, maintain a windows with length = k + 1, gradually add new elem in the windows (remove the first elem each loop)
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> st;
    int l = 0, r = 0;
    while (r < nums.size()) {
        while (r < nums.size() && (r - l) <= k - 1) {
            if (st.find(nums[r]) != st.end()) return true;
            else st.insert(nums[r]);
            r++;
        }

        if (r < nums.size()) {
            if (st.find(nums[r]) != st.end()) return true;
            else {st.insert(nums[r]); st.erase(nums[l]); l++;};
            r++;
        }
    }
    return false;
}