/*
 * Exercise 10: First Negative Window (Parentheses problems plus Evaluate Reverse Polish Notation plus LFU intuition)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Parentheses problems plus Evaluate Reverse Polish Notation plus LFU intuition
// Task      : First Negative Window
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: first_negative_window ---
// Purpose    : Answer aggregate/range computation in `first_negative_window`.
// Approach   : Use running aggregate (prefix/sliding window) to avoid recomputation.
// Complexity : O(n) preprocessing/scan with O(1) per update or query pattern.
// Notes      : Watch index boundaries for left/right endpoints.
// Pseudocode:
// 1) Initialize running aggregate/prefix state.
// 2) Scan array and update aggregate incrementally.
// 3) Use aggregate differences or window updates for answer.
// 4) Return final query/optimization result.
    int first_negative_window(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (14);
        return ans;
    }
};
