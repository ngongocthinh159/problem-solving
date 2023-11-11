/*
  Solution for: https://leetcode.com/problems/triangle/
*/

#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle);
int minAtLevel(vector<vector<int>>& triangle, int level, int i, vector<vector<int>>& dp);

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle);
    return 0;
}

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    return minAtLevel(triangle, 0, 0, dp);
}

int minAtLevel(vector<vector<int>>& triangle, int level, int i, vector<vector<int>>& dp) {
    if (level == triangle.size() - 1) return triangle[level][i];
    if (dp[level][i] != -1) return dp[level][i];

    return dp[level][i] = triangle[level][i] + min(minAtLevel(triangle, level + 1, i, dp), minAtLevel(triangle, level + 1, i + 1, dp));
}   