/*
  Solution for: https://leetcode.com/problems/rotate-image
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix);

int main() {
    vector<vector<int>> matrix =    {{1,2,3},
                                     {4,5,6},
                                     {7,8,9}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }    
    return 0;
}

// This problem is like the typical matrix cycle traversing
// Just traverse through the outer cycle of the matrix each loop and replace following the correct conditions
void rotate(vector<vector<int>>& matrix) {
    int startX = 0, endX = matrix.size() - 1, startY = 0, endY = matrix[0].size() - 1;
    
    // Gradually rotate from the outer cycle of the matrix
    while (startX < endX && startY < endY) {

        // For each outer cycle, we choose the start points of rotating
        // => There is endX - startX - 1 starting points
        for (int ele = 0; ele < endX - startX; ele++) {
            int prev, next;

            // For each starting point, we rotate 4 times (around the cycle)
            // Each time rotate we save the previous state of current point and the current state of next point (point that will be rotated in)
            // Replace point that be rotated in with the previous (original) state of current point
            // And update the prev = current state of next point
            for (int cnt = 1; cnt <= 4; cnt++) {
                if (cnt == 1) {
                    prev = matrix[startX][startY + ele];
                    next = matrix[startX + ele][endY];
                    matrix[startX + ele][endY] = prev;
                } else if (cnt == 2) {
                    next = matrix[endX][endY - ele];
                    matrix[endX][endY - ele] = prev;
                } else if (cnt == 3) {
                    next = matrix[endX - ele][startY];
                    matrix[endX - ele][startY] = prev;
                } else {
                    next = matrix[startX][startY + ele];
                    matrix[startX][startY + ele] = prev;
                }
                prev = next;
            }
        }

        // Traverse the cycle each loop
        startX++; endX--; startY++; endY--;
    }
}