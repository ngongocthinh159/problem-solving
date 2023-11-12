/*
  Solution for: https://leetcode.com/problems/maximum-subarray/
*/

#include <bits/stdc++.h>
using namespace std;

/* clang-format on */
int maxSubArray(vector<int>& nums);

/* Main()  function */
int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    return 0;
}

/**
 * Dùng Kadane algorithm, xét với 1 index i ta coi index i là end index của 1 possible maximum subarray. 
 * Vậy ta sẽ tự hỏi xem phần tử ở index i hiện tại có nên nối với subarray trước đó để tạo nên 1 subarray tổng lớn hơn không?
 * Ta có mối quan hệ:
 *  maxOfSubArrayEndAt[i] = max(nums[i], nums[i] + maxOfSubArrayEndAt[i - 1])
 *  => 2 trường hợp: trường hợp đầu là ko nối với subarray trước đó, trường hợp sau là có nối nếu tổng cộng vào tăng.
*/
int maxSubArray(vector<int>& nums) {
    vector<int> maxAt(nums.size(), -1);
    int res = maxAt[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        maxAt[i] = max(nums[i], nums[i] + maxAt[i - 1]);
        res = max(res, maxAt[i]);
    }
    return res;
}

/* Main() Ends Here */