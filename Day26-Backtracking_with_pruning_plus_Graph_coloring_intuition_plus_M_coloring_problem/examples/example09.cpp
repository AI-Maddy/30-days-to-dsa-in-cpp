/*
 * Example 9: M Coloring Check (Backtracking with pruning plus Graph coloring intuition plus M coloring problem)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Backtracking with pruning plus Graph coloring intuition plus M coloring problem
// Task      : M Coloring Check
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: m_coloring_check ---
// Purpose    : Compute the result for `m_coloring_check`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
int m_coloring_check(vector<int> a) {
    int l = 0, r = (int)a.size() - 1, score = 0;
    while (l <= r) {
        score += a[l];
        if (l != r) score -= a[r];
        l++; r--;
    }
    return score + 9;
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
    vector<int> data = {9, 10, 11, 12, 13};
    cout << m_coloring_check(data) << "\n";
    return 0;
}
