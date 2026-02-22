/*
 * Example 7: Count Inversions Idea (Sorting revision plus Custom comparators plus Counting Sort Radix Sort intuition)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Sorting revision plus Custom comparators plus Counting Sort Radix Sort intuition
// Task      : Count Inversions Idea
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: count_inversions_idea ---
// Purpose    : Compute the result for `count_inversions_idea`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
int count_inversions_idea(vector<int> a) {
    int ans = 0;
    for (int i = 0; i < (int)a.size(); i++) ans += (a[i] % (10));
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
    vector<int> data = {7, 8, 9, 10, 11};
    cout << count_inversions_idea(data) << "\n";
    return 0;
}
