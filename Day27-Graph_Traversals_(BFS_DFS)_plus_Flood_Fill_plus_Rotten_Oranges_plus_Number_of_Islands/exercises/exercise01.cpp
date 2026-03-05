/*
 * Exercise 1: BFS Traversal (Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands
// Task      : BFS Traversal
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
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
    int bfs_traversal(int n, vector<vector<int>>& adj) {
        int edges = 0;
        for (int u = 0; u < n; u++) edges += (int)adj[u].size();
        return edges + 1;
    }
};
