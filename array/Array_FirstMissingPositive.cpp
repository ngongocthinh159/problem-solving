/*
  Solution for: https://leetcode.com/problems/first-missing-positive
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Idea: swap each number to correct position (if can be swapped)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            // Can be swap to the right position only num is in range [1,n]
            // And swapping not making a loop (the number in the swapped to position already in correct position)

            // If the current position can be swapped to correct position => Make the swap
            // Then keep checking the new num that have been swapped to current position if it can be swapped
            if (1 <= nums[i] && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]); 
                i--; // after swapping, keep checking the new num
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};

int main() {
    vector<int> nums = {3,4,-1,1};
    cout << Solution().firstMissingPositive(nums) << "\n";
    return 0;
}

