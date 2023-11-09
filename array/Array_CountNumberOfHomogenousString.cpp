/**
 * Solution for: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
*/

#include <bits/stdc++.h>
using namespace std;

int m = 1e9 + 7;

int addMod(int a, int b) {
    return (a%m + b%m)%m;
}

int mulMod(int a, int b) {
    return ((long long) (a%m)*(b%m))%m;
}

int countHomogenous(string s);

int main() {
    string s = "abbcccaa";
    cout << countHomogenous(s);
    
    return 0;
}


int countHomogenous(string s) {
    int sum = 0;
    int l = 0, r = 0;
    while (r < s.size()) {
        r++;
        while (r < s.size() && s[r] == s[l]) {
            r++;
        }
        int len = r - l;
        
        sum = addMod(sum, mulMod(len, len+1)/2);
        l = r;
    }
    return sum;
}
