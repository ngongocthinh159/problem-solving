/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://leetcode.com/problems/meeting-rooms-iii/
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
/*--------------------------------------------------------------------------------------------------------------------------*/
/**
 * Xử lý từng meeting 1:
 * + Khi còn avail room thì assign room nhỏ nhất
 * + Khi không còn room nào trống thì kiểm tra thời gian kết thúc gần nhất của 1 room nào đó => Assign room đó cho meeting hiện tại
 * 
 * Note: trước khi xử lý từng room, ta phải release tất cả các room mà có ending trước khi meeting hiện tại bắt đầu
*/

#define ll long long
class Solution {
public:
    struct sort_compare {
        bool operator() (const vector<int>&v1, const vector<int>&v2) {
            if (v1[0] < v2[0])return true;
            return false;
        }
    }; 
    struct pq_compare {
        bool operator() (const pair<ll,ll>&p1, const pair<ll,ll>&p2) const {
            if (p2.first <p1.first) return true;
            if (p2.first == p1.first && p2.second < p1.second) return true;
            return false;
        }
    };
    ll mostBooked(int n, vector<vector<int>>& meetings) {
        vector<ll> cnt(n,0);
        sort(meetings.begin(), meetings.end(), sort_compare());
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, pq_compare> u_room;
        priority_queue<ll,vector<ll>,greater<ll>> a_room;
        for (ll i = 0; i < n; i++) {
            a_room.push(i);
        }
        for (auto &m : meetings) {
            while (u_room.size() && u_room.top().first <= m[0]) {
                a_room.push(u_room.top().second);
                u_room.pop();
            }

            if (a_room.size()) {
                int mn_room = a_room.top(); a_room.pop();
                u_room.push({m[1],mn_room});
                cnt[mn_room]++;
            } else {
                auto p = u_room.top(); u_room.pop();
                u_room.push({p.first+m[1]-m[0],p.second});
                cnt[p.second]++;
            }
        }
        ll mx = LONG_MIN, ans = LONG_MAX;
        for (ll i = 0; i < cnt.size(); i++) {
            if (mx < cnt[i]) {mx=cnt[i]; ans=i;}
        }
        return ans;
    }
};

int main() {
    fastio();
    int n = 2;
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    cout << Solution().mostBooked(n,meetings) << "\n";
    return 0;
}


/**
 * Sweep line idea: Xử lý bằng event (more intuitive)
 * 
#define ll long long
class Solution {
public:
    struct Event {
        ll type; // 0: start, 1: end, 2: delayed
        ll time;
        ll room;
        ll len;
        Event(ll t, ll time, ll room, ll l) {
            this->type = t; this->time = time; this->room = room; this->len = l;
        }
    };
    struct comparator {
        bool operator() (const Event &e1, const Event &e2) const {
            if (e2.time < e1.time) return true;
            if (e2.time==e1.time && e2.type==1 && (e1.type==0 || e1.type==2)) return true;
            if (e2.time==e1.time && e2.type==2 && e1.type==0) return true;
            return false;
        }
    };
    ll mostBooked(int n, vector<vector<int>>& meetings) {
        vector<ll> cnt(n,0);
        priority_queue<Event, vector<Event>, comparator> pq;
        priority_queue<ll,vector<ll>,greater<ll>> a_rooms;
        deque<Event> delayed;
        for (ll i = 0; i < n; i++) {
            a_rooms.push(i);
        }
        for (auto &m : meetings) {
            ll s = m[0];
            ll e = m[1];
            ll len = e-s;
            pq.push(Event(0,s,-1,len));
        }
        while (pq.size()) {
            auto e = pq.top(); pq.pop();
            if (e.type==0||e.type==2) {
                if (a_rooms.size()) {
                    ll mn_room = a_rooms.top(); a_rooms.pop();
                    ++cnt[mn_room];
                    ll new_time = e.time + e.len;
                    pq.push(Event(1,new_time,mn_room,e.len));
                } else {
                    delayed.push_front(Event(0,e.time,-1,e.len));
                }
            } else {
                a_rooms.push(e.room);
                if (delayed.size()) {
                    auto d_e = delayed.back(); delayed.pop_back();
                    pq.push(Event(2,e.time,-1,d_e.len));
                }
            }
        }
        ll mx = LONG_MIN, ans = LONG_MAX;
        for (ll i = 0; i < cnt.size(); i++) {
            if (mx < cnt[i]) {mx=cnt[i]; ans=i;}
        }
        return ans;
    }
};
*/