/*
  Solution for: https://leetcode.com/problems/find-peak-element
*/

#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine);

int main() {
    string ransomNote = "a", magazine = "b";
    cout << canConstruct(ransomNote, magazine);

    return 0;
}

bool canConstruct(string ransomNote, string magazine) {
    vector<int> v(26,0);
    for (int i = 0; i < magazine.size(); i++) {
        v[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.size(); i++) {
        if (--v[ransomNote[i] - 'a'] == -1) return false;
    }
    return true;
}