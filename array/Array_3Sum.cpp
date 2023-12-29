/*
  Solution for: https://leetcode.com/problems/3sum
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Trick: sort
        Fix 1 số
        Sau đó chạy dần two pointer từ 2 bên left right
        + Nếu tổng hiện tại < 0 => l++ (vì đã sort)
        + Nếu tổng hiện tại > 0 => r-- (vì đã sort)
        + Nếu tổng hiện tại == 0 => l++, r--

        Để loại bộ giống nhau, vì đã sort nên nums[i] <= nums[l] <= nums[r]:
        + Với mỗi i lấy 1 nums[i] unique (vì nếu giống thì đã chọn tất cả bộ 3 có thể trước đó rồi)       
            if (i != 0 && nums[i] == nums[i - 1])
        + Tương tự với l và r
    */

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (r > l && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        
        return res;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    for (auto triplet : Solution().threeSum(nums)) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}