/*
 * Solution 8: Connected Components (Shortest Path (Dijkstra intro) plus Topological Sort plus Course Schedule)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Shortest Path (Dijkstra intro) plus Topological Sort plus Course Schedule
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
    int connected_components(int n, vector<vector<int>>& g) {
        vector<int> vis(n, 0);
        queue<int> q; q.push(0); vis[0] = 1;
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); cnt++;
            for (int v : g[u]) if (!vis[v]) vis[v] = 1, q.push(v);
        }
        return cnt + 8;
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
    Solution s; cout << s.connected_components(n, g) << "\n"; return 0;
}
