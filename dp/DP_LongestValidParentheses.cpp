/*
    Solution for: https://leetcode.com/problems/longest-valid-parentheses
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_DP_1D {
public:
    vector<int> dp;
    int longestValidParentheses(string s) {
        dp = vector<int>(s.size(), -1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res = max(res, dfs(s, i));
        }
        return res;
    }

    /*
    And the DP idea is :

    If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.

    Else if s[i] is ')'

        If s[i-1] is '(', longest[i] = longest[i-2] + 2

        Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

    For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.
    */
    int dfs(string& s, int i) {
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        if (s[i] == ')') return dp[i] = 0;

        if (i + 1 < s.size()) {
            if (s[i + 1] == ')') return dp[i] = 2 + dfs(s, i + 2);
            else if (s[i + 1] == '(') {
                int tmp = dfs(s, i + 1);
                if (i + tmp + 1 < s.size() && s[i + tmp + 1] == ')') return dp[i] = 2 + tmp + dfs(s, i + tmp + 2);
                return dp[i] = 0;
            }
        }
        return dp[i] = 0;
    }
};

class Solution_Stack {
public:
    /*
        Stack idea is:
        Using stack we can mark the valid parenthesis (the parenthesis can be pop)
        For example after pop, we mark the position of '(' and ')' of that pop to 1:
            0 0 1 1 1 1 0
        
        => We count maxium number of 1 consecutive
    */
    vector<int> dp;
    vector<char> v;
    int longestValidParentheses(string s) {
        vector<int> v(s.size(), 0);
        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stack.push_back(i);
            else {
                if (stack.size() == 0) {stack.clear(); continue;}
                
                v[stack.back()] = 1;
                stack.pop_back();
                v[i] = 1;
            }
        }
        int l = 0, r = 0;
        int res = 0;
        while (r < v.size()) {
            if (v[r] == 0) l = r + 1;
            else res = max(r - l + 1, res);
            r++;
        }
        return res;
    }
};

int main() {
    string s = ")()())";
    cout << "1D DP: " << Solution_DP_1D().longestValidParentheses(s) << "\n";
    cout << "Stack: " << Solution_Stack().longestValidParentheses(s) << "\n";
    return 0;
}