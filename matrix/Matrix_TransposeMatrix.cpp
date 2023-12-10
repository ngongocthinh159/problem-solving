/*
  Solution for: https://leetcode.com/problems/transpose-matrix/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};

int main () {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> transposedMatrix = Solution().transpose(matrix);

    for (int i = 0; i < transposedMatrix.size(); i++) {
        for (int j = 0; j < transposedMatrix[0].size(); j++) {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

