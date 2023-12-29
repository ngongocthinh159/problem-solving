/**
 * Solution for: https://leetcode.com/problems/sliding-window-median/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Ý tưởng: dùng 2 heap để maintain k smallest element đầu tiên (top - max heap)
     * Số element còn lại giữ trong 1 remaining heap (res - min heap)
     * 
     * Mỗi khi insert 1 phần tử ta sẽ quyết định xem nên insert vào heap top hay heap remaining
     * 
     * Ở đây nên dùng set hoặc multiset thay cho priority queue (set và multiset có thể dùng làm cả min và max heap)
    */
    struct qx {
        set<pair<int,int>> top;
        set<pair<int,int>> res;
        int size;
        int topSize;
        qx (int size) {
            this->size = size;
            this->topSize = (size + 1)/2;
        }
        void push(pair<int,int> p) {
            if (top.size() < topSize) {
                top.insert(p);
            } else {
                auto maxTop = *top.rbegin();
                if (p.first < maxTop.first) {
                    top.erase(*top.rbegin());
                    top.insert(p);
                    res.insert(maxTop);
                } else {
                    res.insert(p);
                }
            }
        }
        void erase(pair<int,int> p) {
            if (res.count(p)) {
                res.erase(p);
            } else {
                top.erase(p);
                auto minRes = res.begin();
                if (minRes != res.end()) {
                    auto val = *minRes;
                    res.erase(res.begin());
                    top.insert(val);
                }
            }
        }
        double getMedian() {
            if (size & 1) return (*top.rbegin()).first;
            else return ((double) (*top.rbegin()).first + (*res.begin()).first)/2;
        }
    };
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        qx container(k);
        for (int i = 0; i < k; i++) {
            container.push({nums[i], i});
        }
        res.push_back(container.getMedian());
        for (int i = k; i < nums.size(); i++) {
            container.erase({nums[i - k], i - k});
            container.push({nums[i], i});
            res.push_back(container.getMedian());
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    for (auto num : Solution().medianSlidingWindow(nums, 3)) {
        printf("%.2f ", num);
    }
    cout << "\n";
    return 0;
}