/**
 * Solution for: https://leetcode.com/problems/combination-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, target, candidates);
        return res;
    }
    void dfs(int i, int target, vector<int> &candidates) {
        if (target == 0) {
            res.push_back(path); return;
        }
        if (i >= candidates.size()) return;

        // skip
        dfs(i + 1, target, candidates);

        // choose
        if (target >= candidates[i]) {
            path.push_back(candidates[i]);
            dfs(i, target - candidates[i], candidates);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    for (auto list : Solution().combinationSum(candidates, target)) {
        for (auto num : list)
            cout << num << " ";
        cout << "\n";
    }
    return 0;
}