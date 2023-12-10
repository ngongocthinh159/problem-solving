/*
  Solution for: https://leetcode.com/problems/subarray-sums-divisible-by-k
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Trick 1: giống bài Two Sum => Tìm target là những vị trí đã đi qua trước đó

        Trick 2: modulus của số âm: a%m = (a%m + m)%m

        Trick 3: Ta có thể chứng minh (a - b) % m == 0
        Khi và chỉ khi a%m == b%m

        a = q1*m + R0
        b = q2*m + R1
        a-b = (q1-q2)*m + R0 - R1
        => R0 - R1 % m == 0
        => R0 - R1 = C*m
        => R0 = C*m + R1

        Mà R0 nằm [0,m-1], R1 nằm [0,m-1]
        => C = 0 hay R0 = R1
        => a%m == b%m
    */
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> pre(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            pre[i] = i == 0 ? nums[i] : nums[i] + pre[i - 1];
        }
        int ans = 0;
        unordered_map<int,int>mp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % k == 0 || nums[i] == 0) ans++;
            if (i != 0) {
                ans += mp[(pre[i]%k+k)%k];
            }
            mp[((pre[i] - nums[i])%k + k)%k]++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;

    cout << Solution().subarraysDivByK(nums, k);

    return 0;
}