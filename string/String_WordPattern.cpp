/*
  Solution for: https://leetcode.com/problems/word-pattern/
*/

#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s);

int main() {
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << wordPattern(pattern, s);
    return 0;
}

bool wordPattern(string pattern, string s) {
    stringstream ss(s);
    string word;
    int i = 0;
    unordered_map<char,string> mp;
    set<string> st;
    while (ss >> word) {
        if (i == pattern.size()) return false;
        if (mp.find(pattern[i]) == mp.end()) {
            if (st.find(word) == st.end()) {mp[pattern[i]] = word; st.insert(word);}
            else return false;
        } else {
            string& tmp = mp[pattern[i]];
            if (tmp != word) return false;
        }

        i++;
    }
    if (i != pattern.size()) return false;
    return true;
}
