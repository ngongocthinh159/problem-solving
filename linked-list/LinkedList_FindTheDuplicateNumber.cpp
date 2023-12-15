/*
    Solution for: https://leetcode.com/problems/find-the-duplicate-number
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_FastSlowPointers {
public:
    /*
        Trick: Nếu ta coi mỗi 1 vị trí trỏ đến 1 index khác trong num array
        => Ta traverse như kiểu traverse linked list (node.next)

        Bởi vì điều kiện bài toán là các số đều unique, chỉ có 1 số duy nhất là duplicate
        => Với mỗi 1 lần traverse với các số unique ta đảm bảo đều reach đến 1 index mới trong array

        Chỉ khi ta gặp số duplicate thì tại vị trí số duplicate sẽ trỏ đến index đã từng lặp qua
        => Tạ thành 1 cycle linkedlist => Dùng fast và slow pointer để tìm nút thắt
        
        Nút thắt chính là duplicate number, vì nút thắt tượng trưng cho 1 số bị trỏ vào 2 lần
    */
    int findDuplicate(vector<int>& nums) {
        int slow = 0;   // index bắt đầu chạy của linkedlist
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int tmp = 0;
        while (tmp != slow) {
            tmp = nums[tmp];
            slow = nums[slow];
        }
        return slow;
    }
};

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
    cout << Solution_FastSlowPointers().findDuplicate(nums) << "\n";
    cout << Solution_BinarySearch().findDuplicate(nums) << "\n";
    return 0;
}