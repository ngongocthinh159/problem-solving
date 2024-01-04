/**
 * Solution for: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_PQueue { // O(nlogk)
public:
    /**
     * Trick: for each array, hold only the smallest element
     * 
     * Same traverse idea with merge k sorted lists problem
     * For each array, push the first smallest element to pq (min)
     * From min pq, we can get the smallest among all smallests
     * Keep track of largest among all smallest
     * => The range for current smallest is [smallest, largest]
     * => Pop smallest from pq (done processing), 
     *      pop next element of the array have the smallest into queue
    */
    struct P {
        int val, i, j;
        P (int _val, int _i, int _j): val(_val), i(_i), j(_j) {}
    };
    struct comparator {
        bool operator() (const P &a, const P &b) const {
            if (b.val < a.val) return true;
            return false;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<P, vector<P>, comparator> pq;
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(P(nums[i][0], i, 0));
            mx = max(mx, nums[i][0]);
        }
        vector<int> ans = {0, INT_MAX};
        while (true) {
            auto smallest = pq.top(); pq.pop();
            if (mx - smallest.val < ans[1] - ans[0]) {
                ans = {smallest.val, mx};
            }
            int J = smallest.j + 1;
            if (J == nums[smallest.i].size()) break;
            pq.push(P(nums[smallest.i][J], smallest.i, J));
            mx = max(mx, nums[smallest.i][J]);
        }
        return ans;
    }
};

class Solution_SlidingWindow { // O(nlogn)
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> &list = nums[i];
            for (auto num : list)
                v.push_back({num, i});
        }
        sort(v.begin(), v.end());
        int l = 0, r = 0, ans = INT_MAX;
        unordered_map<int,int> mp;
        int cnt = 0, _l = -1, _r = -1;
        while (r < v.size()) {
            mp[v[r].second]++;
            if (mp[v[r].second] - 1 == 0) cnt++;

            while (cnt == nums.size()) {
                if (ans > v[r].first - v[l].first + 1) {
                    ans = v[r].first - v[l].first + 1;
                    _l = v[l].first; _r = v[r].first;
                }
                mp[v[l].second]--;
                if (mp[v[l].second]==0) cnt--;
                l++;
            }

            r++;
        }
        return {_l, _r};
    }
};

int main() {
    return 0;
}