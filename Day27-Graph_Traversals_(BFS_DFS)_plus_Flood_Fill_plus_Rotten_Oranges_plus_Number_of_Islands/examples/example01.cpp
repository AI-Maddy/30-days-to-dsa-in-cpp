/*
 * Example 1: BFS Traversal (Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands
// Task      : BFS Traversal
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: bfs_traversal ---
// Purpose    : Traverse structure using `bfs_traversal` and aggregate traversal output.
// Approach   : Use queue/stack/recursion to visit each node once in traversal order.
// Complexity : O(n) time, O(h) to O(n) auxiliary space based on traversal strategy.
// Notes      : Checks null root/base condition before traversal.
// Pseudocode:
// 1) If root/state is empty, return base result.
// 2) Initialize traversal structure (stack/queue/recursion).
// 3) Visit each node exactly once and update answer.
// 4) Return accumulated traversal result.
int bfs_traversal(int n, vector<vector<int>>& g) {
    vector<int> vis(n, 0);
    queue<int> q; q.push(0); vis[0] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop(); cnt++;
        for (int v : g[u]) if (!vis[v]) vis[v] = 1, q.push(v);
    }
    return cnt + 1;
}

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
    int n = 5; vector<vector<int>> g(n); g[0] = {1,2}; g[1] = {3}; g[2] = {4};
    cout << bfs_traversal(n, g) << "\n";
    return 0;
}
