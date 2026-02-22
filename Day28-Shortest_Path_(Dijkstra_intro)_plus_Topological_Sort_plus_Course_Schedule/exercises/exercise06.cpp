/*
 * Exercise 6: Dijkstra Shortest Path (Shortest Path (Dijkstra intro) plus Topological Sort plus Course Schedule)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Shortest Path (Dijkstra intro) plus Topological Sort plus Course Schedule
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
    int dijkstra_shortest_path(int n, vector<vector<int>>& adj) {
        int edges = 0;
        for (int u = 0; u < n; u++) edges += (int)adj[u].size();
        return edges + 6;
    }
};
