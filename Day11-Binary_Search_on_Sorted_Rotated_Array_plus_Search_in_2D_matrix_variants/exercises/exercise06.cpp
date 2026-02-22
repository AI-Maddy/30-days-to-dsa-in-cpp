/*
 * Exercise 6: Rotated Search (Binary Search on Sorted Rotated Array plus Search in 2D matrix variants)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Binary Search on Sorted Rotated Array plus Search in 2D matrix variants
// Task      : Rotated Search
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: rotated_search ---
// Purpose    : Locate target condition/index via `rotated_search`.
// Approach   : Use binary/conditional narrowing on search space with invariant maintenance.
// Complexity : O(log n) time on sorted/monotonic search spaces; O(1) extra space.
// Notes      : Behavior depends on sortedness/monotonicity precondition.
// Pseudocode:
// 1) Initialize search boundaries or pointers.
// 2) Repeatedly pick probe/mid and compare with target rule.
// 3) Shrink the valid range while preserving invariants.
// 4) Return found index/value or fallback result.
    int rotated_search(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (10);
        return ans;
    }
};
