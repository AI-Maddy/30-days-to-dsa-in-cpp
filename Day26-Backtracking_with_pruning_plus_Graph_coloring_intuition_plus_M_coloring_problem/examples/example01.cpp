/*
 * Example 1: M-Coloring
 */
#include <bits/stdc++.h>
using namespace std;
// Example 1: M-Coloring Problem — can we color graph with at most m colors?
bool isSafeColor(int node, vector<vector<int>>& adj, vector<int>& color, int c) {
    for (int neighbor : adj[node])
        if (color[neighbor] == c) return false;
    return true;
}
bool mColoring(int node, int n, int m, vector<vector<int>>& adj, vector<int>& color) {
    if (node == n) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafeColor(node, adj, color, c)) {
            color[node] = c;
            if (mColoring(node + 1, n, m, adj, color)) return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}
int main() {
    int n = 4, m = 3;
    vector<vector<int>> adj(n);
    auto addEdge = [&](int u, int v){ adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0,1); addEdge(0,2); addEdge(1,2); addEdge(1,3); addEdge(2,3);
    vector<int> color(n, 0);
    cout << (mColoring(0, n, m, adj, color) ? "Possible" : "Not Possible") << "\n";
    for (int i = 0; i < n; i++) cout << "Node " << i << " -> Color " << color[i] << "\n";
}
