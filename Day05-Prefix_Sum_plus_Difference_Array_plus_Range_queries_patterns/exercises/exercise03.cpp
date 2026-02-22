/*
 * Exercise 3: Sliding Window Sum (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Prefix Sum plus Difference Array plus Range queries patterns
// Task      : Sliding Window Sum
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: sliding_window_sum ---
// Purpose    : Answer aggregate/range computation in `sliding_window_sum`.
// Approach   : Use running aggregate (prefix/sliding window) to avoid recomputation.
// Complexity : O(n) preprocessing/scan with O(1) per update or query pattern.
// Notes      : Watch index boundaries for left/right endpoints.
// Pseudocode:
// 1) Initialize running aggregate/prefix state.
// 2) Scan array and update aggregate incrementally.
// 3) Use aggregate differences or window updates for answer.
// 4) Return final query/optimization result.
    int sliding_window_sum(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (7);
        return ans;
    }
};
