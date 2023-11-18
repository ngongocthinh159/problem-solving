/*
  Solution for: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
*/

#include <bits/stdc++.h>
using namespace std;

/* 
    III/IV. Dùng DP, cách này áp dụng cho cả bài II.
    Điều quan trọng của bài này là ta phải tìm ra transition variables.
     
    Có 2 cách để track trasition variables:
    Cách 1: mỗi khi ta quyết định xem mua ko mua stock tại ngày hiện tại 
            => Thì khi ta chuyển state có 3 biến sau chuyển: i (index ngày), 
            k (số transaction còn lại) và canBuy (biểu thị cho ngày hôm nay 
            ta có thể mua stock hay không nếu ngày trc ta mua thì ngày hiện
            tại canBuy = false và ngược lại). 
            => 3D DP

    Cách 2: ta sét các biến theo cách khác khá tricky, vẫn có i, nhưng ta 
            nhân đôi số transaction (tính cả lần bán), nếu k % 2 == 0 
            => Chứng tỏ ta đang ở lần được phép mua, ngược lại ta đang ở lần được phép bán. 
            => Ta không cần biến canBuy vẫn track được ngày hôm nay có thể mua hay bán
            => 2D DP.
 */

class Solution_2D_DP {
public:
    vector<vector<int>> dp;
    int maxProfit(int k, vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2*k + 1, -1));
        return dfs(0, 2*k, prices);
    }

    int dfs(int i, int k, vector<int>& prices) {
        if (i == prices.size() || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        if (k % 2 == 0) {
            return dp[i][k] = max(-prices[i] + dfs(i + 1, k - 1, prices), dfs(i + 1, k, prices));
        } else {
            return dp[i][k] = max(prices[i] + dfs(i + 1, k - 1, prices), dfs(i + 1, k, prices));
        }
    }
};

class Solution_3D_DP {
public:
    vector<vector<vector<int>>> dp;
    int maxProfit(int k, vector<int>& prices) {
        dp = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return dfs(0, k, 1, prices);
    }

    int dfs(int i, int k, int canBuy, vector<int>& prices) {
        if (i == prices.size()) return 0;
        if (dp[i][k][canBuy] != -1) return dp[i][k][canBuy];

        if (canBuy && k > 0) {
            return dp[i][k][canBuy] = max(-prices[i] + dfs(i + 1, k - 1, 0, prices), dfs(i + 1, k, canBuy, prices));
        } else if (!canBuy) {
            return dp[i][k][canBuy] = max(prices[i] + dfs(i + 1, k, 1, prices), dfs(i + 1, k, canBuy, prices));
        } else {
            return dp[i][k][canBuy] = dfs(i + 1, k, canBuy, prices);
        }
    }
};

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    Solution_2D_DP tmp_2D;
    Solution_3D_DP tmp_3D;
    
    cout << "2D DP: " << tmp_2D.maxProfit(2, prices) << "\n";
    cout << "3D DP: " << tmp_3D.maxProfit(2, prices) << "\n";
    return 0;
}


