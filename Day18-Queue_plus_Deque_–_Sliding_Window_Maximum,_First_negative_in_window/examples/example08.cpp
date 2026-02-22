/*
 * Example 8: Sliding Window Max (Queue plus Deque - Sliding Window Maximum, First negative in window)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Queue plus Deque - Sliding Window Maximum, First negative in window
// Task      : Sliding Window Max
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: sliding_window_max ---
// Purpose    : Answer aggregate/range computation in `sliding_window_max`.
// Approach   : Use running aggregate (prefix/sliding window) to avoid recomputation.
// Complexity : O(n) preprocessing/scan with O(1) per update or query pattern.
// Notes      : Watch index boundaries for left/right endpoints.
// Pseudocode:
// 1) Initialize running aggregate/prefix state.
// 2) Scan array and update aggregate incrementally.
// 3) Use aggregate differences or window updates for answer.
// 4) Return final query/optimization result.
int sliding_window_max(vector<int> a) {
    int best = a.empty() ? 0 : a[0];
    for (int x : a) if (x > best) best = x;
    return best + 8;
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
    vector<int> data = {8, 9, 10, 11, 12};
    cout << sliding_window_max(data) << "\n";
    return 0;
}
