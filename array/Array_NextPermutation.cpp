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
                + Để ý rằng [i+1,n] luôn là mảng giảm dần vì trước đó ko tìm đc thằng nào lớn hơn với mỗi i => nums[i] luôn là số lớn nhất

                => Để chọn thằng vừa lớn hơn i hiện tại ta chỉ cần traverse từ i+1 và tìm thằng cuối cùng lớn hơn nums[i]
            
            => Sau đó swap i và thằng vừa lớn hơn

            => Sau khi swap thì [i+1,n] vẫn là mảng giảm dần => Ta chỉ cần reverse lại lấy mảng tăng dần (next permutation)
    */
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = i + 1;
            while (j + 1 < nums.size() && nums[j + 1] > nums[i]) {
                j++;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
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