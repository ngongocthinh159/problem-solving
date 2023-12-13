/*
    Solution for: https://leetcode.com/problems/find-the-duplicate-number
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_BinarySearch {
public:
    /*
        Trick nếu sort lại dãy ví dụ:
        1 2 3 3 3 4 5
        => Ta đếm với mỗi số tại i, số num nhỏ hơn hoặc bằng số hiện tại thì ta thấy

        Với dãy:    1 2 3 3 3 4 5
            =>      1 2 5 5 5 6 7
        
        Nhận thấy là kể từ số duplicate thì số num đếm được nhỏ hơn hoặc bằng số hiện tại sẽ > số hiện tại
        => Dùng binary search tìm số đầu tiên từ bên trái có số num nhỏ hơn hoặc bằng số hiện tại mà > số hiện tại (kết quả tốt nhất)
    */
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        int ans;
        while (l <= r) {
            int m = l + (r - l)/2;

            int cnt = 0;
            for (auto num : nums) {
                if (num <= m) cnt++;
            }
            if (cnt > m) {
                ans = m;
                r = m - 1;
            } else
                l = m + 1;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << Solution_BinarySearch().findDuplicate(nums) << "\n";
    return 0;
}