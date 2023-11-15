/*
  Solution for: https://leetcode.com/problems/house-robber/
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    return 0;
}

/*
    One solution is to think about this problem as a graph problem, 
    where routes (buses) are vertice of the graph. 
    Unweighted graph => BFS to find the shortest path from source to target.
*/
unordered_map<int, unordered_set<int>> mp;   // Mapping busStop - routes
unordered_set<int> visitedStops; // Stops have been explored
int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) return 0;
    for (int i = 0; i < routes.size(); i++) {
        for (int j = 0; j < routes[i].size(); j++) {
            mp[routes[i][j]].insert(i);
        }
    }
    vector<int> visited(routes.size(), false); // Routes (buses) have been explored

    unordered_set<int>& targetRoutes = mp[target];
    queue<int> q;
    int cnt = 1;
    for (int route : mp[source]) {
        q.push(route);
        visited[route] = true;
        if (targetRoutes.count(route)) return cnt;
    }
    while (q.size()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            int curRoute = q.front(); q.pop();
            for (int j = 0; j < routes[curRoute].size(); j++) {
                if (visitedStops.count(routes[curRoute][j])) continue;
                visitedStops.insert(routes[curRoute][j]);
                for (int neighborRoute : mp[routes[curRoute][j]]) {
                    if (targetRoutes.count(neighborRoute)) return ++cnt;
                    if (!visited[neighborRoute]) {
                        visited[neighborRoute] = true;
                        q.push(neighborRoute);
                    }
                }
            }
        }
        cnt++;
    }
    
    return -1;
}