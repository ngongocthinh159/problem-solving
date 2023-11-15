/*
  Solution for: https://leetcode.com/problems/minimum-path-sum/
*/

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid);
int explore(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j);

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(grid);
    return 0;
}

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return explore(grid, dp, 0, 0);
}

vector<vector<int>> moves = {{0, 1}, {1, 0}};
int explore(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
    if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
    if (dp[i][j] != -1) return dp[i][j];    

    int res = INT_MAX;
    for (int k = 0; k < moves.size(); k++) {
        int newI = i + moves[k][0];
        int newJ = j + moves[k][1];
        if (0 <= newI && newI < grid.size() && 0 <= newJ && newJ < grid[0].size()) {
            res = min(res, grid[i][j] + explore(grid, dp, newI, newJ));
        }
    }
    return dp[i][j] = res;
}