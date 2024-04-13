/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://leetcode.com/problems/valid-parenthesis-string/
 * Submission: https://leetcode.com/problems/valid-parenthesis-string/submissions/1225676981/
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
/*--------------------------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    bool checkValidString(string s) {
        vector<int> open; // hold open bracket idx
        vector<int> star; // hold star idx
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') open.push_back(i);
            else if (c == '*') star.push_back(i);
            else { // close bracket case need 1 open or star
                if (open.size()) open.pop_back(); // greedy use open bracket first if have (star can be empty so use open first)
                else if (star.size()) { // if open bracket is empty => use star as open bracket
                    star.pop_back();
                } else return false;
            }
        }
        // If can reach here meaning all the close bracket can be satisfied
        // Start to check for remaining open brackets, which are already in the open array
        // The remaining open bracket only can be satisfied by star because all the close brackets have been delete from above for loop
        int i = 0, j = 0;
        while (i < open.size() && j < star.size()) {
            if (star[j] < open[i]) j++;
            else if (open[i] < star[j]) {i++; j++;} // use star to satisfy an open bracket when idx star > idx bracket
        }
        return i == open.size(); // only valid if we can satisfy all open bracket
    }
};

int main() {
    fastio();
    string s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    cout << (Solution().checkValidString(s) ? "true" : "false") << "\n";
    return 0;
}