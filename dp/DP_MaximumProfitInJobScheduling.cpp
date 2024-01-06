/**
 * Solution for: 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Ý tưởng: bài toán DP choose/skip kinh điển
 * Các bài toán bình thường sau khi choose/skip thì move đến next index
 * 
 * Bài này có thêm là: sau khi choose ta phải
 * biết vị trí tiếp theo valid để jump đến (next valid index sau khi choose)
 *   + Có thể dùng linear search O(n^2)
 *   + Dùng binary search vì array đã được sort O(nlogn)
*/
class Solution {
public:
    struct Job {
        int startTime, endTime, profit;
        Job (int _1, int _2, int _3): startTime(_1), endTime(_2), profit(_3) {}
    };
    struct comparator {
        bool operator() (const Job &a, const Job &b) const {
            if (a.startTime < b.startTime) return true;
            return false;
        }
    };
    vector<int> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        dp = vector<int>(startTime.size() + 1, -1);
        int n = startTime.size();
        vector<Job> v;
        for (int i = 0; i < n; i++) {
            v.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(v.begin(), v.end(), comparator());
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i], dp[i + 1]);
            auto idx = lower_bound(v.begin() + i + 1, v.end(), Job(v[i].endTime,-1,-1), comparator());
            if (idx != v.end()) dp[i] = max(dp[i], v[i].profit + dp[idx - v.begin()]);
            else dp[i] = max(dp[i], v[i].profit);
        }
        return dp[0];
    }
};

int main() {
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    cout << Solution().jobScheduling(startTime, endTime, profit);
    return 0;
}