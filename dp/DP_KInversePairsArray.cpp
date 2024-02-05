/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://leetcode.com/problems/k-inverse-pairs-array/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Recurrence relation cho inverse pair:
 * Tưởng tượng ta biết kết quả cho f(n,k) là số permutation của n số mà có k inverse pairs
 * Nếu ta thêm số n + 1 vào mà vẫn muốn có k inverse pairs. Thì:
 *      + Số n + 1 là số lớn nhất với dãy f(n,k) ta chỉ thêm số n + 1 vào cuối (ko tạo thêm inverse pair nào thêm)
 *      + Với dãy f(n,k-1) ta cần tạo thêm 1 inverse pair => Đặt số n + 1 vào vị trí số 1 từ phải sang
 *          ví dụ: 2 1 3 4 có 1 inverse pair
 *                 2 1 3 4 5 => cũng có 1
 * 
 *                 1 2 3 4 có 0 inverse pair (cần thêm 1)
 *                 1 2 3 5 4 => Đặt 5 vị trí 1 từ phải qua (tạo thêm 1 inverse pair)
 *      + Tương tự các số inverse pair nhỏ hơn
 *  
 *      => f(n,k) = f(n-1,k) + f(n-1,k-1) + ... + f(n-1,k-(n-1))
*/

class Solution_MathFormula {
public:
    /**
     * Trick: f(n,k)   = f(n-1,k) + f(n-1,k-1) +...+ f(n-1,k-(n-1))
     *        f(n,k-1) = f(n-1,k-1) + f(n-1,k-2) +...+ f(n-1,k-(n-1)) + f(n-1,k-1-(n-1))
     * 
     * => f(n,k) = f(n-1,k) + f(n,k-1) - f(n-1,k-n)
    */
    const int mod = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = ((j - 1 >= 0 ? dp[i][j - 1] : 0) + dp[i - 1][j])%mod;
                dp[i][j] = (dp[i][j] - (j >= i ? dp[i - 1][j - i] : 0))%mod;
                if (dp[i][j] < 0) dp[i][j] += mod;
            }
        }
        return dp[n][k];
    }
};


class Solution_PrefixSum {
public:
    const int mod = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0) dp[i][j] = 1;
                else {
                    // prefix sum for cumulation of previous row sum
                    int val = (dp[i - 1][j] - (j - i >= 0 ? dp[i - 1][j - i] : 0))%mod;
                    if (val < 0) val += mod;
                    dp[i][j] = (dp[i][j - 1] + val)%mod;
                }
            }
        }
        int res = (dp[n][k] - (k - 1 >= 0 ? dp[n][k - 1] : 0))%mod;
        if (res < 0) res += mod;
        return res;
    }
};

int main() {
    int n = 3, k = 1;
    cout << Solution_PrefixSum().kInversePairs(n, k);
    return 0;
}


 