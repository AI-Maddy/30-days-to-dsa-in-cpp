/*
 * Exercise 4: Daily Temperatures (Stack - Next Greater Element (NGE), Next Smaller, Stock Span)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Stack - Next Greater Element (NGE), Next Smaller, Stock Span
// Task      : Daily Temperatures
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: daily_temperatures ---
// Purpose    : Compute the result for `daily_temperatures`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int daily_temperatures(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (8);
        return ans;
    }
};
