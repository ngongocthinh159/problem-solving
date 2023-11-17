/*
  Solution for: https://leetcode.com/problems/interleaving-string
*/

#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3);
int explore(string& s1, string& s2, string& s3, int i, int j);

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << (isInterleave(s1, s2, s3) ? "true" : "false") << "\n";
    return 0;
}

vector<vector<int>> dp;
bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return (explore(s1, s2, s3, 0, 0) == 1 ? true : false);
}

int explore(string& s1, string& s2, string& s3, int i, int j) {
    if (i == s1.size() && j == s2.size()) return true;
    if (i == s1.size()) return dp[i][j] = s3.substr(i + j) == s2.substr(j);
    if (j == s2.size()) return dp[i][j] = s3.substr(i + j) == s1.substr(i);
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s3[i + j] && s2[j] == s3[i + j]) {
        return dp[i][j] = ((explore(s1, s2, s3, i + 1, j) == 1 || explore(s1, s2, s3, i, j + 1) == 1) ? 1 : 0);
    } else if (s1[i] == s3[i + j]) {
        return dp[i][j] = explore(s1, s2, s3, i + 1, j);
    } else if (s2[j] == s3[i + j]) {
        return dp[i][j] = explore(s1, s2, s3, i, j + 1);
    } else {
        return dp[i][j] = 0;
    }
}