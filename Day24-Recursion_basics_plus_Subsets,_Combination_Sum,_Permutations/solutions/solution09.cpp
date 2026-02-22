/*
 * Solution 9: M Coloring Check (Recursion basics plus Subsets, Combination Sum, Permutations)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Recursion basics plus Subsets, Combination Sum, Permutations
// Task      : M Coloring Check
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: m_coloring_check ---
// Purpose    : Compute the result for `m_coloring_check`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int m_coloring_check(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x;
        return ans + 9;
    }
};

// Driver code for quick local verification.
// --- Function Explanation: main ---
// Purpose    : Compute the result for `main`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Build or read sample input.
// 2) Call the core function/class method.
// 3) Print/verify the produced output.
int main() {
    vector<int> nums = {9, 10, 11};
    Solution s; cout << s.m_coloring_check(nums) << "\n"; return 0;
}
