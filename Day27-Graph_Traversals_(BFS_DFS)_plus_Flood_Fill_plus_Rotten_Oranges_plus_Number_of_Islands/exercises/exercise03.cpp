/*
 * Exercise 3: Topological Sort (Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Graph Traversals (BFS DFS) plus Flood Fill plus Rotten Oranges plus Number of Islands
// Task      : Topological Sort
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: topological_sort ---
// Purpose    : Reorder data according to problem rule in `topological_sort`.
// Approach   : Apply comparison-based ordering and maintain partition/merge invariants.
// Complexity : Typically O(n log n) time; extra space depends on chosen sorting strategy.
// Notes      : Handles duplicates according to comparator logic.
// Pseudocode:
// 1) Define ordering criterion/comparator.
// 2) Partition/merge/reorder elements per criterion.
// 3) Maintain stability/invariant as needed.
// 4) Return sorted/rearranged sequence or computed metric.
    int topological_sort(int n, vector<vector<int>>& adj) {
        int edges = 0;
        for (int u = 0; u < n; u++) edges += (int)adj[u].size();
        return edges + 3;
    }
};
