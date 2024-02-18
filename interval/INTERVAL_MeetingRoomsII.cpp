/**
 * Author: Thinh Ngo Ngoc
 * Solution for: https://leetcode.com/problems/meeting-rooms-ii/
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
/*--------------------------------------------------------------------------------------------------------------------------*/


/**
 * Lưu giữ lại thời gian kết thúc của 1 used room:
 * + Nếu không có room nào kết thúc trước start time của meeting hiện tại => Tăng room
 * + Nếu có thì pop room kết thúc nhỏ nhất (greedy)
 * + Mỗi khi allocate room cho meeting hiện tại thì push thời gian kết thúc lên pq
*/
class Solution {
public:
    struct comparator {
        bool operator() (const vector<int>&v1, const vector<int>&v2) const {
            if (v1[0] < v2[0]) return true;
            return false;
        }
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator());
        priority_queue<int,vector<int>,greater<int>> pq;
        int mx_room = 0;
        for (auto i : intervals) {
            if (!pq.size() || pq.top()>i[0]) mx_room++;
            else {
                pq.pop();
            }
            pq.push(i[1]);
        }
        return mx_room;
    }
};

int main() {
    fastio();
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    cout << Solution().minMeetingRooms(intervals) << "\n";
    return 0;
}

/**
 * Sweep line idea: dùng event để xử lý bài toán
class Solution {
public:
    struct Event {
        int type;
        int time;
        int len;
        Event(int type, int time, int len) {
            this->type = type;
            this->time = time;
            this->len = len;
        }
        bool operator< (const Event&other) const {
            if (this->time > other.time) return true;
            if (this->time == other.time && this->type==0 && other.type==1) return true;
            return false;
        }
    };
    struct comparator {
        bool operator() (const Event&e1, const Event&e2) const {
            if (e2.time < e1.time) return true;
            if (e2.time==e1.time && e2.type==1 && e1.type==0) return true;
            return false;
        }
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<Event,vector<Event>> pq;
        for (auto i : intervals) {
            pq.push(Event(0,i[0],i[1]-i[0]));
        }
        int mx_room = 0;
        int a_room = 0;
        while (pq.size()) {
            auto e = pq.top(); pq.pop();
            int type = e.type;
            int time = e.time;
            int len = e.len;
            if (type == 0) {
                if (a_room) {
                    a_room--;
                } else {
                    mx_room++;
                }
                pq.push(Event(1,time+len,len));
            } else {
                a_room++;
            }
        }
        return mx_room;
    }
};
*/