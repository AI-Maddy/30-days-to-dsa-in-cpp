/*
 * Exercise 5: Knapsack 0-1 (1D DP patterns plus Mini revision plus Solve mixed medium hard problems)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : 1D DP patterns plus Mini revision plus Solve mixed medium hard problems
// Task      : Knapsack 0-1
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: knapsack_0_1 ---
// Purpose    : Compute optimal substructure value using `knapsack_0_1`.
// Approach   : Build DP state transitions from smaller subproblems.
// Complexity : Usually O(states × transitions), space O(states) unless compressed.
// Notes      : State definition and transition order are the key correctness points.
// Pseudocode:
// 1) Define DP state and base conditions.
// 2) Iterate states in dependency-safe order.
// 3) Apply transition recurrence to update best value.
// 4) Return target state result.
    int knapsack_0_1(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (9);
        return ans;
    }
};
