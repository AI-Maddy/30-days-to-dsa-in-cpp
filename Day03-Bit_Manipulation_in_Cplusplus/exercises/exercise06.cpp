/*
 * Exercise 6: Power Of Two (Bit Manipulation in Cplusplus)
 */
#include <iostream>
#include <vector>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Bit Manipulation in Cplusplus
// Task      : Power Of Two
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: power_of_two ---
// Purpose    : Compute the result for `power_of_two`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int power_of_two(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (10);
        return ans;
    }
};
