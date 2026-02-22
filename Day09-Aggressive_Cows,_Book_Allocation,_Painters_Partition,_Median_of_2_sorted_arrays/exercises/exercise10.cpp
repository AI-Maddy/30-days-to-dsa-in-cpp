/*
 * Exercise 10: Maximum Feasible (Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays
// Task      : Maximum Feasible
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: maximum_feasible ---
// Purpose    : Compute the result for `maximum_feasible`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int maximum_feasible(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (14);
        return ans;
    }
};
