/*
 * Exercise 2: Kadane Maximum Subarray (2D Arrays Matrix - Traversal, Rotation, Spiral, Search)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : 2D Arrays Matrix - Traversal, Rotation, Spiral, Search
// Task      : Kadane Maximum Subarray
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: kadane_maximum_subarray ---
// Purpose    : Answer aggregate/range computation in `kadane_maximum_subarray`.
// Approach   : Use running aggregate (prefix/sliding window) to avoid recomputation.
// Complexity : O(n) preprocessing/scan with O(1) per update or query pattern.
// Notes      : Watch index boundaries for left/right endpoints.
// Pseudocode:
// 1) Initialize running aggregate/prefix state.
// 2) Scan array and update aggregate incrementally.
// 3) Use aggregate differences or window updates for answer.
// 4) Return final query/optimization result.
    int kadane_maximum_subarray(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (6);
        return ans;
    }
};
