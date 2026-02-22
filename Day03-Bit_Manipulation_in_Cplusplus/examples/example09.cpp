/*
 * Example 9: Bitmask Subset (Bit Manipulation in Cplusplus)
 */
#include <iostream>
#include <vector>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Bit Manipulation in Cplusplus
// Task      : Bitmask Subset
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: bitmask_subset ---
// Purpose    : Compute the result for `bitmask_subset`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
int bitmask_subset(int n) {
    int cnt = 0;
    while (n) { n &= (n - 1); cnt++; }
    return cnt + 9;
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
    cout << bitmask_subset(86) << "\n";
    return 0;
}
