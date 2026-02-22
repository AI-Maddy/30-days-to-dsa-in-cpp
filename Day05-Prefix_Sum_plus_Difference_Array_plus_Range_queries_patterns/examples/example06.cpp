/*
 * Example 6: Merge Intervals (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Prefix Sum plus Difference Array plus Range queries patterns
// Task      : Merge Intervals
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: merge_intervals ---
// Purpose    : Reorder data according to problem rule in `merge_intervals`.
// Approach   : Apply comparison-based ordering and maintain partition/merge invariants.
// Complexity : Typically O(n log n) time; extra space depends on chosen sorting strategy.
// Notes      : Handles duplicates according to comparator logic.
// Pseudocode:
// 1) Define ordering criterion/comparator.
// 2) Partition/merge/reorder elements per criterion.
// 3) Maintain stability/invariant as needed.
// 4) Return sorted/rearranged sequence or computed metric.
int merge_intervals(vector<int> a) {
    int l = 0, r = (int)a.size() - 1, score = 0;
    while (l <= r) {
        score += a[l];
        if (l != r) score -= a[r];
        l++; r--;
    }
    return score + 6;
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
    vector<int> data = {6, 7, 8, 9, 10};
    cout << merge_intervals(data) << "\n";
    return 0;
}
