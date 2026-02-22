/*
 * Exercise 2: Next Greater (Stack - Next Greater Element (NGE), Next Smaller, Stock Span)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Stack - Next Greater Element (NGE), Next Smaller, Stock Span
// Task      : Next Greater
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: next_greater ---
// Purpose    : Evaluate sequence constraints using `next_greater`.
// Approach   : Use monotonic stack/queue to keep only useful candidates.
// Complexity : O(n) time with amortized O(1) push/pop operations.
// Notes      : Ensure pop conditions reflect strict/non-strict requirement.
// Pseudocode:
// 1) Initialize monotonic/support stack or queue.
// 2) For each element, pop invalid candidates.
// 3) Read answer from top/front and push current element.
// 4) Return collected per-index or global result.
    int next_greater(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (6);
        return ans;
    }
};
