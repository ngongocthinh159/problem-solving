/*
  Solution for: https://leetcode.com/problems/word-break-ii
  This solution is a backtracking solution + early termination if can not break the word in the current path
  For early termination technique used in this solution: please refer to Word Break problem
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> wordBreak(string s, vector<string>& wordDict);
bool explore(string& s, vector<string>& wordDict, int i, vector<bool>& dp);

int main() {

    return 0;
}

vector<string> path;
vector<string> res;
vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size(), -1);
    explore(s, wordDict, 0, dp);
    return res;
}

// Gradually, try each word in side wordDict as the prefix (if matching)
// Go to each path of the tree and use backtracking (when can reach the string len => Stop and save the path)

// For early termination, Using a dp vector to save the state of index i
// Which mean, we will keep track of is there any possible path if we start from index i
// If no possible path => early terminate
bool explore(string& s, vector<string>& wordDict, int i, vector<bool>& dp) {
    if (i >= s.size()) {
        string tmp = "";
        for (int j = 0; j < path.size(); j++) {
            tmp += path[j];
            if (j != path.size() - 1) tmp += " ";
        }
        res.push_back(tmp);
        return 1;
    }
    if (dp[i] == 0) return 0;

    bool found = false;
    for (int j = 0; j < wordDict.size(); j++) {
        if (i + wordDict[j].size() - 1 < s.size() && s.substr(i, wordDict[j].size()) == wordDict[j]) {
            path.push_back(wordDict[j]);
            bool tmp = explore(s, wordDict, i + wordDict[j].size(), dp);
            if (tmp == 1) {
                found = true;
            }
            path.pop_back();
        }
    }

    if (!found) return dp[i] = 0;
    return dp[i] = 1;
}