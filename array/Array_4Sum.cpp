/**
 * Solution for: https://leetcode.com/problems/4sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_2Pointers {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;
                long long tar = 0LL + target - nums[i] - nums[j];
                while (l < r) {
                    if (0LL + nums[l] + nums[r] > tar) {
                        r--;
                    } else if (0LL + nums[l] + nums[r] < tar) {
                        l++;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++; r--;
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (r > l && nums[r] == nums[r + 1]) r--;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution_HashMap {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        unordered_map<long long,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1; k < nums.size() - 1; k++) {
                    if (k != j + 1 && nums[k] == nums[k - 1]) continue;
                    long long tar = 0LL + target - nums[i] - nums[j] - nums[k];
                    if (mp.count(tar)) {
                        if (mp[tar] > k) ans.push_back({nums[i], nums[j], nums[k], (int) tar});
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    for (auto list : Solution_2Pointers().fourSum(nums, target)) {
        for (auto num : list) {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}