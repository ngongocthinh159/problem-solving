/**
 * Solution for: https://leetcode.com/problems/combination-sum-iii/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }

    void dfs(int i, int k, int n) {
        if (n == 0 && k == 0) {
            res.push_back(path); return;
        }
        if (i >= 10) return;

        // skip
        dfs(i + 1, k, n);

        if (n >= i) {
            path.push_back(i);
            dfs(i + 1, k - 1, n - i);
            path.pop_back();
        }
    }
};

int main() {
    int k = 3;
    int n = 7;
    for (auto list : Solution().combinationSum3(k, n)) {
        for (auto num : list)
            cout << num << " ";
        cout << "\n";
    }
    return 0;
}