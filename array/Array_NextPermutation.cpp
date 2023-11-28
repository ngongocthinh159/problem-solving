/*
  Solution for: https://leetcode.com/problems/next-permutation
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Để tìm permutation liền sau, ta nghĩ đến cách cải thiện 1 vị trí index i bất kì trong permutation hiện tại bằng cách tăng nó lên. Vậy vị trí i này nếu ta nghĩ 1 cách greedy ta nên chọn vị trí của nó càng gần hàng đơn vị càng tốt (từ phải qua).
        => Từ đây ta có intuition, ta sẽ tìm 1 vị trí i từ phải qua mà ta có thể cải thiện được nó bằng cách swap nó với 1 phần tử nào đó bên phải nó để tăng nó lên => Cải thiện permutation 1 cách minimum nhất.
        => Từ phải qua: tại vị trí i hiện tại, ta sẽ hỏi xem từ [i+1,n] có phần tử nào lớn hơn nó không để ta swap (cải thiện permutation).

        + Trong trường hợp tại i, có nhiều phần tử lớn hơn i trong khoảng [i+1,n]
            => Ta chọn thằng vừa mới lớn hơn (best) để swap.

            => Phần còn lại sau khi swap xong, ta sort lại.
    */
    void nextPermutation(vector<int>& nums) {
        int mx = INT_MIN;
        int l = -1, r = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (mx > nums[i]) {
                l = i;
                break;
            }
            mx = max(mx, nums[i]);
        }
        if (l == -1) {reverse(nums.begin(), nums.end()); return;}
        int best = INT_MAX;
        for (int i = l + 1; i < nums.size(); i++) {
            if (nums[l] < nums[i] && best > nums[i] - nums[l]) {
                best = nums[i] - nums[l];
                r = i;
            }
        }
        swap(nums[l], nums[r]);
        sort(nums.begin() + l + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution().nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}