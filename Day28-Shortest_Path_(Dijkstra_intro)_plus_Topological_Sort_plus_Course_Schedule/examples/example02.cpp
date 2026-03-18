/*
 * Example 2: Topological Sort Kahn
 */
#include <bits/stdc++.h>
using namespace std;
// Example 2: Topological Sort — Kahn's Algorithm (BFS)
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0), order;
    for (int u=0;u<n;u++) for (int v : adj[u]) indegree[v]++;
    queue<int> q;
    for (int i=0;i<n;i++) if (indegree[i]==0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop(); order.push_back(u);
        for (int v : adj[u]) if (--indegree[v]==0) q.push(v);
    }
    return order; // size < n means cycle
}
int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[5]={2,0}; adj[4]={0,1}; adj[2]={3}; adj[3]={1};
    auto order = topoSort(n, adj);
    for (int x : order) cout << x << " "; cout << "\n";
}
