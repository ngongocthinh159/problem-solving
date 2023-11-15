/*
  Solution for: https://leetcode.com/problems/word-break
*/

#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict);
int isValid(string& s, int k, vector<int>& dp, vector<string>& wordDict);

int main () {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict);
    return 0;
}

bool wordBreak(string s, vector<string>& wordDict) {
    vector<int> dp(s.size(), -1);
    return (isValid(s, 0, dp, wordDict) == 1 ? true : false);
}

int isValid(string& s, int k, vector<int>& dp, vector<string>& wordDict) {
    if (k >= s.size()) return true;
    if (dp[k] != -1) return dp[k];

    // For each word inside the wordDict => Match the prefix fromt he current index (k)
    for (int i = 0; i < wordDict.size(); i++) {
        if (k + wordDict[i].size() - 1 < s.size() && s.substr(k, wordDict[i].size()) == wordDict[i] && isValid(s, k + wordDict[i].size(), dp, wordDict) == 1) {
            return dp[k] = 1;
        }
    }
    return dp[k] = 0;
}

bool wordBreak_BottomUp(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[s.size()] = true;
    for (int i = s.size() - 1; i >=0; i--) {
        for (int j = 0; j < wordDict.size(); j++) {
            if (i + wordDict[j].size() - 1 < s.size()) {
                if (s.substr(i, wordDict[j].size()) == wordDict[j]) {
                    if (dp[i + wordDict[j].size()]) {dp[i] = true; break;}
                }
            }
        }
    }
    return dp[0];
}