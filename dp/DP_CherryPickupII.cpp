/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://leetcode.com/problems/cherry-pickup-ii/
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * The same x for both robots => 3D DP : x, y1, y2
*/
class Solution {
public:
    vector<vector<int>> moves = {{1,-1,-1}, {1,-1,0}, {1,-1,1}, {1,0,-1}, {1,0,0}, {1,0,1}, {1,1,-1}, {1,1,0}, {1,1,1}};
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m][m];
        for (int x = n - 1; x >= 0; x--) {
            for (int y1 = 0; y1 < m; y1++) {
                for (int y2 = 0; y2 < m; y2++) {
                    int cur = y1==y2 ? grid[x][y1] : grid[x][y1] + grid[x][y2];
                    int res = cur;
                    for (auto &move: moves) {
                        int X = x + move[0];
                        int Y1 = y1 + move[1];
                        int Y2 = y2 + move[2];
                        if (0 <= X && X < n && 0 <= Y1 && Y1 < m && 0 <= Y2 && Y2 < m) {
                            res = max(res, cur + dp[X][Y1][Y2]);
                        }
                    }
                    dp[x][y1][y2] = res;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

int main() {
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << Solution().cherryPickup(grid) << "\n";
    return 0;
}
