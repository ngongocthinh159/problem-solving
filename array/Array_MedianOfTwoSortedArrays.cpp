/*
  Solution for: https://leetcode.com/problems/median-of-two-sorted-arrays
*/

#include <bits/stdc++.h>
using namespace std;

/* Function declaration */
class Solution {
public:
    /*
        This problem is too tricky with lots of edge cases
        Chi tiết: https://www.youtube.com/watch?v=F9c7LpRZWVQ&t=1406s

        Ý tưởng: binary search trên 1 array bằng cách:
        Ta phải chọn median mà Median luôn ở vị trí (n + m + 1)/2
        Nếu khi merge 2 array vào thì nhìn về cơ bản thì:
            left - median - right

        => Với 1 array thứ nhất ta sẽ chọn 1 số phần tử của left
        => Ta có thể suy ra số phần tử của left chọn ở array thứ 2

        => Ta kiểm tra tiếp xem, all left1 <= all right2 và all left2 <= all right1
        Nếu thoả mãn thì ta đã chọn đúng số phần tử left trên mỗi array => Tìm đc median

        Nếu chọn ko đúng xảy ra 2 trườg hợp:
            + max(left1) > min(right2) => Ta cần giảm số phần tử left của arr1 => l = m - 1
            + max(left2) > min(right1) => Tăng số phần tử left của arr1 => r = m + 1

        Note: Trong trường hợp out_of_bound thì dùng MAX_INT và MIN_INT để coi như là default value
        
        Improve: luôn search trên array có size nhỏ hơn => Log(min(n,m))
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int pos = (nums1.size() + nums2.size() + 1)/2;

        // Nếu không search trên array có size nhỏ hơn thì khoảng search phải specify chính xác (thay vì 0 -> n)
        int l = max(0, (int) (pos - nums2.size())), r = min(pos, (int) nums1.size());

        while (l <= r) {
            int m = l + (r - l)/2;

            int l1 = m - 1 >= 0 && m - 1 < nums1.size() ? nums1[m - 1] : INT_MIN;
            int r1 = m < nums1.size() && m >= 0 ? nums1[m] : INT_MAX;
            int l2 = (pos - m) - 1 >= 0 && (pos - m) - 1 < nums2.size() ? nums2[(pos - m) - 1] : INT_MIN;
            int r2 = pos - m < nums2.size() && pos - m >= 0 ? nums2[pos - m] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if ((nums1.size() + nums2.size()) & 1) return max(l1, l2);
                else  return ((double) max(l1, l2) + min(r1, r2) )/2;
            } else if (l1 > r2) {
                r = m - 1;
            } else if (l2 > r1) {
                l = m + 1;
            }
        }

        return -1.0;
    }
};

/* Main()  function */
int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    cout << Solution().findMedianSortedArrays(nums1, nums2);
}
/* Main() Ends Here */