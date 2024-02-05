/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://leetcode.com/problems/permutation-sequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        say n = 4, you have {1, 2, 3, 4}

            If you were to list out all the permutations you have

            1 + (permutations of 2, 3, 4)

            2 + (permutations of 1, 3, 4)

            3 + (permutations of 1, 2, 4)

            4 + (permutations of 1, 2, 3)
        
        + We construct gradually the k-th permutation by choosing each number of the permutation
        + The first number will fall into (1 or 2 or 3 or 4)
            - To fall into 1: k <= (n-1)!   (first (n-1)! permutations will start with 1)
            - To fall into 2: (n-1)! < k <= 2*(n-1)! (k must pass first (n-1)! permutation start with 1)
            ...

        Note: This can be called Factorial Number System
        ex:
        k = 3 = 1x2! + 1x1! + 0x0! = 110    => {2,3,1}  (k start from 0 => k=3 is 4-th permutation)
    */
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> fact = {1};
        for (int i = 1; i <=n; i++) {
            nums.push_back(i);
            fact.push_back(i*fact.back());
        }
        string res = "";
        for (int i = n - 1; i >= 0; i--) {
            int idx = ceil((double)k/fact[i]) - 1;
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            k -= idx*fact[i];
        }
        return res;
    }
};

int main() {
    int n = 3, k = 3;
    cout << Solution().getPermutation(n, k) << "\n";
    return 0;
}