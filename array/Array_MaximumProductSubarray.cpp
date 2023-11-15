/*
  Solution for: https://leetcode.com/problems/maximum-product-subarray/
*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums);

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums);
    return 0;
}

/*
    Key idea là vẫn sử dụng Kadane algo (nối index i hiện tại với subarray trước đó hoặc không).
    Nhưng vì là product và trong dãy có số âm => Ta keep track 2 DP cả min và max tại index i. Sau đó để quyết định xem có nên concate với subarray hay ko chọn max của 1 trong 3:
            nums[i] * maxProd[i - 1] (nums[i] > 0 nối với max subarray)
    hoặc:   nums[i] * minProd[i - 1] (nums[i] < 0 nối với min subarray)
    hoặc:   nums[i] (khi mà nums[i] đứng một mình lớn hơn cả 2 trg hợp)
*/
int maxProduct(vector<int>& nums) {
    vector<int> minProd(nums.size(), -1);
    vector<int> maxProd(nums.size(), -1);
    minProd[0] = nums[0];
    maxProd[0] = nums[0];
    int res = INT_MIN;
    for (int i = 1; i < nums.size(); i++) {
        minProd[i] = min(nums[i], min(maxProd[i - 1]*nums[i], minProd[i - 1]*nums[i]));
        maxProd[i] = max(nums[i], max(maxProd[i - 1]*nums[i], minProd[i - 1]*nums[i]));
        res = max(res, maxProd[i]);
    }
    res = max(res, maxProd[0]);
    return res;
}