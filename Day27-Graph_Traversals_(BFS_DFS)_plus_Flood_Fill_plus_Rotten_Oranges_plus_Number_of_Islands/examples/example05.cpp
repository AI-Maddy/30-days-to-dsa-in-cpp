/*
 * Example 5: Cycle Detection BFS
 */
#include <bits/stdc++.h>
using namespace std;
// Example 5: Detect Cycle in Undirected Graph (BFS)
bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    for (int src = 0; src < n; src++) {
        if (vis[src]) continue;
        queue<pair<int,int>> q; // {node, parent}
        q.push({src, -1}); vis[src] = true;
        while (!q.empty()) {
            auto [u, par] = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) { vis[v] = true; q.push({v, u}); }
                else if (v != par) return true;
            }
        }
    }
    return false;
}
int main() {
    int n = 5; vector<vector<int>> adj(n);
    auto add = [&](int u,int v){adj[u].push_back(v);adj[v].push_back(u);};
    add(0,1);add(1,2);add(2,3);add(3,4);add(4,1);
    cout << (hasCycle(n, adj) ? "Cycle detected" : "No cycle") << "\n";
}
