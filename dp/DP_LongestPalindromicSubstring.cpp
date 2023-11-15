/*
  Solution for: https://leetcode.com/problems/longest-palindromic-substring/
*/

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome_DP(string s);
int calLen(string& s, int l, int r, vector<vector<int>>& dp);

string longestPalindrome_ExploreFromCenter(string s);
pair<int,int> explore(int i, int j, string s);

int main() {
    string s = "babad";
    cout << longestPalindrome_DP(s) << "\n";
    cout << longestPalindrome_ExploreFromCenter(s) << "\n";
    return 0;
}

string longestPalindrome_DP(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
    int len = INT_MIN, l = 0, r = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            int tmp = calLen(s, i, j, dp);
            if (len < tmp) {
                len = tmp; l = i; r = j;
            }
        }
    }
    return s.substr(l, len);
}

int calLen(string& s, int l, int r, vector<vector<int>>& dp) {
    if (l == r) return 1;
    if (r - l + 1 == 2 && s[r] == s[l]) return 2;
    if (dp[l][r] != -1) return dp[l][r];

    if (s[l] == s[r]) {
        int tmp = calLen(s, l + 1, r - 1, dp);
        if (tmp) return dp[l][r] = tmp + 2;
        return dp[l][r] = 0;
    } else {
        return dp[l][r] = 0;
    }
}

string longestPalindrome_ExploreFromCenter(string s) {
    int res = INT_MIN, l = 0, r = 0;
    for (int i = 0; i < s.size(); i++) {
        pair<int,int> p = explore(i - 1, i + 1, s);
        if (res < p.second - p.first + 1) {
            res = p.second - p.first + 1;
            l = p.first; r = p.second;
        }
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            pair<int,int> p = explore(i - 2, i + 1, s);
            if (res < p.second - p.first + 1) {
                res = p.second - p.first + 1;
                l = p.first; r = p.second;
            }
        }
    }
    return s.substr(l, r - l + 1);
}

pair<int,int> explore(int i, int j, string s) {
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        i--; j++;
    }
    return {i + 1, j - 1};
}