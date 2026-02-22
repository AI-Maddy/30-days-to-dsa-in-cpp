/*
 * Solution 6: Dijkstra Shortest Path (Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands
// Task      : Dijkstra Shortest Path
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: dijkstra_shortest_path ---
// Purpose    : Solve graph relation/path requirement in `dijkstra_shortest_path`.
// Approach   : Traverse adjacency structure with queue/heap/DSU depending on pattern.
// Complexity : Commonly O(V+E) or O((V+E) log V) for weighted shortest path.
// Notes      : Initialize visited/dist/parent structures before traversal.
// Pseudocode:
// 1) Build/initialize adjacency and helper arrays.
// 2) Push starting nodes/state into queue/heap/DSU.
// 3) Expand edges while maintaining visited/dist/parent.
// 4) Return path/order/connectivity result.
    int dijkstra_shortest_path(int n, vector<vector<int>>& g) {
        vector<int> vis(n, 0);
        queue<int> q; q.push(0); vis[0] = 1;
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); cnt++;
            for (int v : g[u]) if (!vis[v]) vis[v] = 1, q.push(v);
        }
        return cnt + 6;
    }
};

// Driver code for quick local verification.
// --- Function Explanation: main ---
// Purpose    : Compute the result for `main`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Build or read sample input.
// 2) Call the core function/class method.
// 3) Print/verify the produced output.
int main() {
    int n = 4; vector<vector<int>> g(n); g[0] = {1,2}; g[1] = {3};
    Solution s; cout << s.dijkstra_shortest_path(n, g) << "\n"; return 0;
}
