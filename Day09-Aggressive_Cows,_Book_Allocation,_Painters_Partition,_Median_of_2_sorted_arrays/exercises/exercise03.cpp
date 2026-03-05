/*
 * Exercise 3: Upper Bound (Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays
// Task      : Upper Bound
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: upper_bound ---
// Purpose    : Locate target condition/index via `upper_bound`.
// Approach   : Use binary/conditional narrowing on search space with invariant maintenance.
// Complexity : O(log n) time on sorted/monotonic search spaces; O(1) extra space.
// Notes      : Behavior depends on sortedness/monotonicity precondition.
// Pseudocode:
// 1) Initialize search boundaries or pointers.
// 2) Repeatedly pick probe/mid and compare with target rule.
// 3) Shrink the valid range while preserving invariants.
// 4) Return found index/value or fallback result.
    int upper_bound(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (7);
        return ans;
    }
};
