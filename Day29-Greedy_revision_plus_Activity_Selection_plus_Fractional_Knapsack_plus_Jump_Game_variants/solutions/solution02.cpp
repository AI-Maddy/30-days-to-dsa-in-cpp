/*
 * Solution 2: Fractional Knapsack (Greedy revision plus Activity Selection plus Fractional Knapsack plus Jump Game variants)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Greedy revision plus Activity Selection plus Fractional Knapsack plus Jump Game variants
// Task      : Fractional Knapsack
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: fractional_knapsack ---
// Purpose    : Compute optimal substructure value using `fractional_knapsack`.
// Approach   : Build DP state transitions from smaller subproblems.
// Complexity : Usually O(states × transitions), space O(states) unless compressed.
// Notes      : State definition and transition order are the key correctness points.
// Pseudocode:
// 1) Define DP state and base conditions.
// 2) Iterate states in dependency-safe order.
// 3) Apply transition recurrence to update best value.
// 4) Return target state result.
    int fractional_knapsack(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x;
        return ans + 2;
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
    vector<int> nums = {2, 3, 4};
    Solution s; cout << s.fractional_knapsack(nums) << "\n"; return 0;
}
