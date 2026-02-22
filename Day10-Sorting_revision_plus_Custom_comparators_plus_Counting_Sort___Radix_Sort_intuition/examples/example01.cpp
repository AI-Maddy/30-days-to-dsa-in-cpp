/*
 * Example 1: Insertion Sort Pass (Sorting revision plus Custom comparators plus Counting Sort Radix Sort intuition)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Sorting revision plus Custom comparators plus Counting Sort Radix Sort intuition
// Task      : Insertion Sort Pass
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: insertion_sort_pass ---
// Purpose    : Reorder data according to problem rule in `insertion_sort_pass`.
// Approach   : Apply comparison-based ordering and maintain partition/merge invariants.
// Complexity : Typically O(n log n) time; extra space depends on chosen sorting strategy.
// Notes      : Handles duplicates according to comparator logic.
// Pseudocode:
// 1) Define ordering criterion/comparator.
// 2) Partition/merge/reorder elements per criterion.
// 3) Maintain stability/invariant as needed.
// 4) Return sorted/rearranged sequence or computed metric.
int insertion_sort_pass(vector<int> a) {
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
    cout << insertion_sort_pass(data) << "\n";
    return 0;
}
