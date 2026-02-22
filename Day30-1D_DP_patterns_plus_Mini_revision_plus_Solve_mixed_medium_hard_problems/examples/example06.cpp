/*
 * Example 6: Coin Change Minimum (1D DP patterns plus Mini revision plus Solve mixed medium hard problems)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : 1D DP patterns plus Mini revision plus Solve mixed medium hard problems
// Task      : Coin Change Minimum
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: coin_change_minimum ---
// Purpose    : Compute optimal substructure value using `coin_change_minimum`.
// Approach   : Build DP state transitions from smaller subproblems.
// Complexity : Usually O(states × transitions), space O(states) unless compressed.
// Notes      : State definition and transition order are the key correctness points.
// Pseudocode:
// 1) Define DP state and base conditions.
// 2) Iterate states in dependency-safe order.
// 3) Apply transition recurrence to update best value.
// 4) Return target state result.
int coin_change_minimum(vector<int> a) {
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
    cout << coin_change_minimum(data) << "\n";
    return 0;
}
