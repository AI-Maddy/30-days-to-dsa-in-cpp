/*
 * Solution 1: Fibonacci DP (1D DP patterns plus Mini revision plus Solve mixed medium hard problems)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : 1D DP patterns plus Mini revision plus Solve mixed medium hard problems
// Task      : Fibonacci DP
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: fibonacci_dp ---
// Purpose    : Compute optimal substructure value using `fibonacci_dp`.
// Approach   : Build DP state transitions from smaller subproblems.
// Complexity : Usually O(states × transitions), space O(states) unless compressed.
// Notes      : State definition and transition order are the key correctness points.
// Pseudocode:
// 1) Define DP state and base conditions.
// 2) Iterate states in dependency-safe order.
// 3) Apply transition recurrence to update best value.
// 4) Return target state result.
    int fibonacci_dp(int n) {
        vector<int> dp(n + 1, 0);
        if (n >= 1) dp[1] = 1;
        for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n] + 1;
    }
};

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
    Solution s; cout << s.fibonacci_dp(10) << "\n"; return 0;
}
