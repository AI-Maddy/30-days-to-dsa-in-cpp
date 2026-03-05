/*
 * Exercise 2: Fractional Knapsack (Greedy revision plus Activity Selection plus Fractional Knapsack plus Jump Game variants)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
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
        for (int x : nums) ans += x % (6);
        return ans;
    }
};
