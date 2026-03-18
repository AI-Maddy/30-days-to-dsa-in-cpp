/*
 * Example 1: BFS and DFS
 */
#include <bits/stdc++.h>
using namespace std;
// Example 1: BFS and DFS on undirected graph
void bfs(int src, vector<vector<int>>& adj, int n) {
    vector<bool> vis(n, false);
    queue<int> q; q.push(src); vis[src] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); cout << u << " ";
        for (int v : adj[u]) if (!vis[v]) { vis[v] = true; q.push(v); }
    }
    cout << "\n";
}
void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true; cout << u << " ";
    for (int v : adj[u]) if (!vis[v]) dfs(v, adj, vis);
}
int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    auto add = [&](int u, int v){ adj[u].push_back(v); adj[v].push_back(u); };
    add(0,1); add(0,2); add(1,3); add(2,4); add(3,5);
    cout << "BFS from 0: "; bfs(0, adj, n);
    cout << "DFS from 0: "; vector<bool> vis(n,false); dfs(0, adj, vis); cout << "\n";
}
