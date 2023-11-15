/*
  Solution for: https://leetcode.com/problems/longest-common-subsequence
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence_DP_TopDown(string text1, string text2);
int explore(string& text1, string& text2, vector<vector<int>>& dp, int l1, int l2);
int longestCommonSubsequence_DP_BottomUp(string text1, string text2);

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << "DP top down: " << longestCommonSubsequence_DP_TopDown(text1, text2) << "\n";
    cout << "DP bottom up: " << longestCommonSubsequence_DP_BottomUp(text1, text2) << "\n";
    return 0;
}

// The KEY of this problem is using DP on LENGTH OF TWO STRINGS
// So we have recurrence:
// dp[l1][l2] = t1[l1] == t2[l2] ? 1 + dp[l1 - 1][l2 - 2] : max(dp[l1][l2 - 1], dp[l1 - 1][l2])
int longestCommonSubsequence_DP_TopDown(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
    return explore(text1, text2, dp, text1.size(), text2.size());
}

int explore(string& text1, string& text2, vector<vector<int>>& dp, int l1, int l2) {
    if (l1 == 0 || l2 == 0) return 0;
    if (dp[l1][l2] != -1) return dp[l1][l2];

    int res;
    if (text1[l1 - 1] == text2[l2 - 1]) {
        res = 1 + explore(text1, text2, dp, l1 - 1, l2 - 1);
    } else {
        res = max(explore(text1, text2, dp, l1 - 1, l2), explore(text1, text2, dp, l1, l2 -1));
    }
    return dp[l1][l2] = res;
}

int longestCommonSubsequence_DP_BottomUp(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    dp[0][0] = dp[1][0] = dp[0][1] = 0;
    for (int l1 = 1; l1 <= text1.size(); l1++) {
        for (int l2 = 1; l2 <= text2.size(); l2++) {
            if (text1[l1 - 1] != text2[l2 - 1]) {
                dp[l1][l2] = max(dp[l1 - 1][l2], dp[l1][l2 - 1]);
            } else {
                dp[l1][l2] = 1 + dp[l1 - 1][l2 - 1];
            }
        }
    }
    return dp[text1.size()][text2.size()];
}