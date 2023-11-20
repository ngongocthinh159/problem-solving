/*
  Solution for: https://leetcode.com/problems/permutations-ii
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        This unique permutation also called partial permutation.

        A key insight to avoid generating any redundant permutation (like Permutation I problem) 
        is that at each step rather than viewing each position (index) as a candidate, 
        we consider each unique number as the true candidate.
    */
    vector<int> path;
    vector<vector<int>> res;
    unordered_map<int,int> mp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        dfs(nums);
        return res;
    }

    void dfs(vector<int>& nums) {
        if (path.size() == nums.size()) {
            vector<int> tmp(path);
            res.push_back(tmp);
            return;
        }

        for (auto& [num, cnt] : mp) {
            if (cnt == 0) continue;
            cnt--;
            path.push_back(num);

            dfs(nums);

            cnt++;
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,1,2};
    for (auto& per : Solution().permuteUnique(nums)) {
        for (auto num : per) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}