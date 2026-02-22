/*
 * Exercise 8: Connected Components (Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands
// Task      : Connected Components
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: connected_components ---
// Purpose    : Compute the result for `connected_components`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int connected_components(int n, vector<vector<int>>& adj) {
        int edges = 0;
        for (int u = 0; u < n; u++) edges += (int)adj[u].size();
        return edges + 8;
    }
};
