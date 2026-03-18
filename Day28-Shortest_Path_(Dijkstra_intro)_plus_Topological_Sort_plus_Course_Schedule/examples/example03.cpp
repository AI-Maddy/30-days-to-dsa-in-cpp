/*
 * Example 3: Topological Sort DFS
 */
#include <bits/stdc++.h>
using namespace std;
// Example 3: Topological Sort — DFS-based
void dfsTopoSort(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfsTopoSort(v, adj, vis, st);
    st.push(u);
}
vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false); stack<int> st;
    for (int i=0;i<n;i++) if (!vis[i]) dfsTopoSort(i, adj, vis, st);
    vector<int> order;
    while (!st.empty()) { order.push_back(st.top()); st.pop(); }
    return order;
}
int main() {
    int n = 4;
    vector<vector<int>> adj(n);
    adj[0]={1}; adj[0].push_back(2); adj[1]={3}; adj[2]={3};
    for (int x : topoSortDFS(n, adj)) cout << x << " "; cout << "\n";
}
