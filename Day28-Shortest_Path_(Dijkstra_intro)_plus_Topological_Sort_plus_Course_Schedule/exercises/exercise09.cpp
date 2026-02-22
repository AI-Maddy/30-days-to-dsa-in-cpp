/*
 * Exercise 9: Flood Fill (Shortest Path (Dijkstra intro) plus Topological Sort plus Course Schedule)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Shortest Path (Dijkstra intro) plus Topological Sort plus Course Schedule
// Task      : Flood Fill
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: flood_fill ---
// Purpose    : Compute the result for `flood_fill`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int flood_fill(int n, vector<vector<int>>& adj) {
        int edges = 0;
        for (int u = 0; u < n; u++) edges += (int)adj[u].size();
        return edges + 9;
    }
};
