/**
 * Solution for: https://cses.fi/problemset/task/1641
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Trick: mỗi window ta maitain tổng số flip trong window đó

        Khi move đến 1 window r++, l--. Thì làm sao để ta perform l--?
            + l-- nghĩa là ta sẽ remove 1 phần tử lại vị trí l ra khỏi window,
            tại vị trí đó có thể phần tử sẽ bị flip hoặc ko (ảnh hưởng đến total coun)
                => Ta đánh dấu 1 phần tử bị flip hay ko bằng cách khi flip 1 vị trí ta cho nums[i] -= 2 < 0
                => Khi remove l ta chỉ cần check nums[l] < 0 hay ko, nếu có thì flip--

            + r++ là ta thêm 1 phần tử vào window, để biết phần tử thêm vào có nên flip hay ko
            ta dựa vào total flip của cả window hiện tại (total flip này chắc chắn effect đến phần tử r)
    */
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i - k >= 0 && nums[i - k] < 0) {flips--; nums[i - k] += 2;}
            if (flips % 2 == nums[i] % 2) {
                if (i + k - 1 >= nums.size()) return -1;
                nums[i] -= 2; flips++; total++;
            }
        }
        return total;
    }
};

int main() {
    vector<int> nums = {0,0,0,1,0,1,1,0};
    int k = 3;
    cout << Solution().minKBitFlips(nums, k);
    return 0;
}