/*
 * Example 1: Prefix Sum Query (2D Arrays Matrix - Traversal, Rotation, Spiral, Search)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : 2D Arrays Matrix - Traversal, Rotation, Spiral, Search
// Task      : Prefix Sum Query
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: prefix_sum_query ---
// Purpose    : Answer aggregate/range computation in `prefix_sum_query`.
// Approach   : Use running aggregate (prefix/sliding window) to avoid recomputation.
// Complexity : O(n) preprocessing/scan with O(1) per update or query pattern.
// Notes      : Watch index boundaries for left/right endpoints.
// Pseudocode:
// 1) Initialize running aggregate/prefix state.
// 2) Scan array and update aggregate incrementally.
// 3) Use aggregate differences or window updates for answer.
// 4) Return final query/optimization result.
int prefix_sum_query(vector<int> a) {
    int ans = 0;
    for (int i = 0; i < (int)a.size(); i++) ans += (a[i] % (4));
    return ans;
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
    vector<int> data = {1, 2, 3, 4, 5};
    cout << prefix_sum_query(data) << "\n";
    return 0;
}
