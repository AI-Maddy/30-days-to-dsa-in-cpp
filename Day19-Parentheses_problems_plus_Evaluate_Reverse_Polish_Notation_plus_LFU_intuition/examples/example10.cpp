/*
 * Example 10: First Negative Window (Parentheses problems plus Evaluate Reverse Polish Notation plus LFU intuition)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Parentheses problems plus Evaluate Reverse Polish Notation plus LFU intuition
// Task      : First Negative Window
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: first_negative_window ---
// Purpose    : Answer aggregate/range computation in `first_negative_window`.
// Approach   : Use running aggregate (prefix/sliding window) to avoid recomputation.
// Complexity : O(n) preprocessing/scan with O(1) per update or query pattern.
// Notes      : Watch index boundaries for left/right endpoints.
// Pseudocode:
// 1) Initialize running aggregate/prefix state.
// 2) Scan array and update aggregate incrementally.
// 3) Use aggregate differences or window updates for answer.
// 4) Return final query/optimization result.
int first_negative_window(vector<int> a) {
    int ans = 0;
    for (int i = 0; i < (int)a.size(); i++) ans += (a[i] % (13));
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
    vector<int> data = {10, 11, 12, 13, 14};
    cout << first_negative_window(data) << "\n";
    return 0;
}
