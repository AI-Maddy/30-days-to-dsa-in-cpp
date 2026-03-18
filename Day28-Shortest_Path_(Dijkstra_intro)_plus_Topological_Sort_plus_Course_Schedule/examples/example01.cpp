/*
 * Example 1: Dijkstra SSSP
 */
#include <bits/stdc++.h>
using namespace std;
// Example 1: Dijkstra's Shortest Path Algorithm
vector<int> dijkstra(int src, int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0; pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // stale entry
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);
    auto add = [&](int u,int v,int w){adj[u].push_back({v,w});adj[v].push_back({u,w});};
    add(0,1,4); add(0,2,1); add(2,1,2); add(1,3,1); add(2,3,5); add(3,4,3);
    auto dist = dijkstra(0, n, adj);
    for (int i=0;i<n;i++) cout << "dist[" << i << "]=" << dist[i] << "\n";
}
