/*
  Solution for: https://leetcode.com/problems/permutations
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        A key insight: for each index i, choose a possible index j with nums[j] to place in index i
        Mark any choosen index j as visited
    */
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visited;
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        dfs(nums);
        return res;
    }

    void dfs(vector<int>& nums) {
        if (path.size() == nums.size()) {
            vector<int> tmp(path);
            res.push_back(tmp);
            return;
        }

        // Pick an index j not yet visited (in the decision tree)
        for (int j = 0; j < nums.size(); j++) {
            if (!visited[j]) {
                visited[j] = true;
                path.push_back(nums[j]);
                dfs(nums);
                visited[j] = false;
                path.pop_back();
            }
        }
    }
};

int main() {
    vector<int> nums = {1,2,3,1};
    for (auto& per : Solution().permute(nums)) {
        for (int num : per) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}