/*
  Solution for: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit_DP_2D(vector<int>& prices);
int dfs_2D(vector<int>& prices, int i, int k);
int maxProfit_DP_3D(vector<int>& prices);
int dfs_3D(vector<int>& prices, int i, int k, int canBuy);

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "2D DP: " << maxProfit_DP_2D(prices) << "\n";
    cout << "3D DP: " << maxProfit_DP_3D(prices) << "\n";
    return 0;
}

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

vector<vector<int>> dp;
int maxProfit_DP_2D(vector<int>& prices) {
    dp = vector<vector<int>>(prices.size(), vector<int>(2*2 + 1, -1));
    return dfs_2D(prices, 0, 4);
}

int dfs_2D(vector<int>& prices, int i, int k) {
    if (i == prices.size() || k == 0) return 0;
    if (dp[i][k] != -1) return dp[i][k];

    if (k % 2 == 0) {
        return dp[i][k] = max(-prices[i] + dfs_2D(prices, i + 1, k - 1), dfs_2D(prices, i + 1, k));
    } else {
        return dp[i][k] = max(prices[i] + dfs_2D(prices, i + 1, k - 1), dfs_2D(prices, i + 1, k));
    }
}

vector<vector<vector<int>>> dp3;
int maxProfit_DP_3D(vector<int>& prices) {
    dp3 = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(2 + 1, vector<int>(2, -1)));
    return dfs_3D(prices, 0, 2, 1);
}

int dfs_3D(vector<int>& prices, int i, int k, int canBuy) {
    if (i == prices.size()) return 0;
    if (dp3[i][k][canBuy] != -1) return dp3[i][k][canBuy];

    if (canBuy && k > 0) {
        return dp3[i][k][canBuy] = max(-prices[i] + dfs_3D(prices, i + 1, k - 1, 0), dfs_3D(prices, i + 1, k, canBuy));
    } else if (!canBuy) {
        return dp3[i][k][canBuy] = max(prices[i] + dfs_3D(prices, i + 1, k, 1), dfs_3D(prices, i + 1, k, canBuy));
    } else {
        return dp3[i][k][canBuy] = dfs_3D(prices, i + 1, k, canBuy);
    }
}