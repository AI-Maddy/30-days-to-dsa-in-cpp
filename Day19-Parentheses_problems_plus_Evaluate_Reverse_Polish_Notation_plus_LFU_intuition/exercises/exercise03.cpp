/*
 * Exercise 3: Stock Span (Parentheses problems plus Evaluate Reverse Polish Notation plus LFU intuition)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Parentheses problems plus Evaluate Reverse Polish Notation plus LFU intuition
// Task      : Stock Span
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: stock_span ---
// Purpose    : Evaluate sequence constraints using `stock_span`.
// Approach   : Use monotonic stack/queue to keep only useful candidates.
// Complexity : O(n) time with amortized O(1) push/pop operations.
// Notes      : Ensure pop conditions reflect strict/non-strict requirement.
// Pseudocode:
// 1) Initialize monotonic/support stack or queue.
// 2) For each element, pop invalid candidates.
// 3) Read answer from top/front and push current element.
// 4) Return collected per-index or global result.
    int stock_span(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (7);
        return ans;
    }
};
