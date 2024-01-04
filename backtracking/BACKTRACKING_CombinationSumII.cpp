/**
 * Solution for: https://leetcode.com/problems/combination-sum-ii/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        unordered_map<int,int> jmp;
        int i = 0; 
        while (i < candidates.size()) {
            int start = candidates[i];
            while (i + 1 < candidates.size() && start == candidates[i + 1]) i++;
            jmp[start] = i + 1;
            i++;
        }
        dfs(0, target, candidates, jmp);
        return res;
    }
    void dfs(int i, int target, vector<int> &candidates, unordered_map<int,int> &jmp) {
        if (target == 0) {
            res.push_back(path); return;
        }
        if (i >= candidates.size()) return;

        // skip
        dfs(jmp[candidates[i]], target, candidates, jmp);
        
        // choose
        if (target >= candidates[i]) {
            path.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], candidates, jmp);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    for (auto list : Solution().combinationSum2(candidates, target)) {
        for (auto num : list)
            cout << num << " ";
        cout << "\n";
    }
    return 0;
}