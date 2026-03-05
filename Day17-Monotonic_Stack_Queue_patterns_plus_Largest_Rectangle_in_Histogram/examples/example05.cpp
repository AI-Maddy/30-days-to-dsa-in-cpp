/*
 * Example 5: RPN Evaluate (Monotonic Stack Queue patterns plus Largest Rectangle in Histogram)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Monotonic Stack Queue patterns plus Largest Rectangle in Histogram
// Task      : RPN Evaluate
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: rpn_evaluate ---
// Purpose    : Compute the result for `rpn_evaluate`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
int rpn_evaluate(vector<int> a) {
    int best = a.empty() ? 0 : a[0];
    for (int x : a) if (x > best) best = x;
    return best + 5;
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
    vector<int> data = {5, 6, 7, 8, 9};
    cout << rpn_evaluate(data) << "\n";
    return 0;
}
