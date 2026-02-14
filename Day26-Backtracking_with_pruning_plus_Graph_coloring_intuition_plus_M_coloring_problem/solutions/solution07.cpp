/*
 * Solution 7: Dijkstra's Algorithm for Shortest Path
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);
    
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});
    
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << "Shortest distances from 0: ";
    for (int d : dist) cout << d << " ";
    cout << endl;
    
    return 0;
}
