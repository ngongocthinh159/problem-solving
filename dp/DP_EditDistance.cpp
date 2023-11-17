/*
  Solution for: https://leetcode.com/problems/edit-distance
*/

#include <bits/stdc++.h>
using namespace std;

int minDistance_DP_TopDown(string word1, string word2);
int dfs(string& word1, string& word2, int i, int j);
int minDistance_DP_BottomUp_SpaceOptimized(string word1, string word2);

int main() {
    string word1 = "horse";
    string word2 = "ros";
    cout << minDistance_DP_TopDown(word1, word2) << "\n";
    cout << minDistance_DP_BottomUp_SpaceOptimized(word1, word2) << "\n";
    return 0;
}

vector<vector<int>> dp;
int minDistance_DP_TopDown(string word1, string word2) {
    dp = vector<vector<int>>(word1.size(), vector<int>(word2.size(), -1));
    return dfs(word1, word2, 0, 0);
}

int dfs(string& word1, string& word2, int i, int j) {
    if (i == word1.size() && j == word2.size()) return 0;
    if (i == word1.size()) return word2.size() - j;
    if (j == word2.size()) return word1.size() - i;
    if (dp[i][j] != -1) return dp[i][j];

    if (word1[i] == word2[j]) return dp[i][j] = dfs(word1, word2, i + 1, j + 1);
    else if (word1[i] != word2[j]) {
        return dp[i][j] = 1 + min(dfs(word1, word2, i + 1, j), min(dfs(word1, word2, i + 1, j + 1), dfs(word1, word2, i, j + 1)));
    }
    return -1;
}

/*
    This solution using O(n) space
*/
int minDistance_DP_BottomUp_SpaceOptimized(string word1, string word2) {
    if (word1.size() == 0) return word2.size();
    if (word2.size() == 0) return word1.size();
    int n = word1.size(), m = word2.size();
    vector<int> dp(m + 1, 0);
    vector<int> pre(m + 1, 0);
    pre[m] = 0;
    for (int i = word2.size() - 1; i >= 0; i--) {
        pre[i] = word2.size() - i;
    }
    for (int i = word1.size() - 1; i >= 0; i--) {
        dp[m] = word1.size() - i;
        for (int j = word2.size() - 1; j >= 0; j--) {
            if (word1[i] == word2[j]) dp[j] = pre[j + 1];
            else {
                dp[j] = 1 + min(pre[j], min(pre[j + 1], dp[j + 1]));
            }
        }
        pre = dp;
    }
    return dp[0];
}
