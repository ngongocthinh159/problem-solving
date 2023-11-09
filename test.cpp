#include <bits/stdc++.h>
using namespace std;

bool pairCompare(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second < b.second) return true;
    else return false;
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[i].first = tmp;
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[i].second = tmp;
    }
    sort(v.begin(), v.end(), pairCompare);
    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    // int notAvailableTil = -1;
    // int cnt = 0;
    // for (int i = 0; i < v.size();) {
    //     bool found = false;
    //     int cur = v[i].second;
    //     if (v[i].first > notAvailableTil) found = true;
    //     while (i + 1 < v.size() && v[i + 1].second == cur) {
    //         if (v[i + 1].first > notAvailableTil) found = true;
    //         i++;
    //     }
        
    //     if (found) {
    //         cnt++;
    //         notAvailableTil = cur;
    //     }
    //     i++;
    // }
    // cout << cnt;

    return 0;
}