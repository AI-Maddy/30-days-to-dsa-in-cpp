/*
 * Solution 9: Minimum Feasible (Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Aggressive Cows, Book Allocation, Painters Partition, Median of 2 sorted arrays
// Task      : Minimum Feasible
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: minimum_feasible ---
// Purpose    : Compute the result for `minimum_feasible`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int minimum_feasible(vector<int>& a, int target) {
        int l = 0, r = (int)a.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m] == target) return m;
            if (a[m] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
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
    Solution s; vector<int> a = {9, 11, 13, 15};
    cout << s.minimum_feasible(a, 13) << "\n";
    return 0;
}
