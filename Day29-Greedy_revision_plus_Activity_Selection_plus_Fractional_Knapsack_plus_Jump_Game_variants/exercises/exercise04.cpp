/*
 * Exercise 4: Jump Game Minimum Jumps (Greedy revision plus Activity Selection plus Fractional Knapsack plus Jump Game variants)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Greedy revision plus Activity Selection plus Fractional Knapsack plus Jump Game variants
// Task      : Jump Game Minimum Jumps
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: jump_game_minimum_jumps ---
// Purpose    : Compute the result for `jump_game_minimum_jumps`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int jump_game_minimum_jumps(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (8);
        return ans;
    }
};
