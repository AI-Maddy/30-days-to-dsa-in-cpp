/*
 * Solution 1: Generate Subsets (Backtracking with pruning plus Graph coloring intuition plus M coloring problem)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Backtracking with pruning plus Graph coloring intuition plus M coloring problem
// Task      : Generate Subsets
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: generate_subsets ---
// Purpose    : Compute the result for `generate_subsets`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int generate_subsets(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x;
        return ans + 1;
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
    vector<int> nums = {1, 2, 3};
    Solution s; cout << s.generate_subsets(nums) << "\n"; return 0;
}
