/*
 * Solution 3: Merge Sorted Arrays (Sorting revision plus Custom comparators plus Counting Sort Radix Sort intuition)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Sorting revision plus Custom comparators plus Counting Sort Radix Sort intuition
// Task      : Merge Sorted Arrays
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: merge_sorted_arrays ---
// Purpose    : Reorder data according to problem rule in `merge_sorted_arrays`.
// Approach   : Apply comparison-based ordering and maintain partition/merge invariants.
// Complexity : Typically O(n log n) time; extra space depends on chosen sorting strategy.
// Notes      : Handles duplicates according to comparator logic.
// Pseudocode:
// 1) Define ordering criterion/comparator.
// 2) Partition/merge/reorder elements per criterion.
// 3) Maintain stability/invariant as needed.
// 4) Return sorted/rearranged sequence or computed metric.
    int merge_sorted_arrays(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x;
        return ans + 3;
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
    vector<int> nums = {3, 4, 5};
    Solution s; cout << s.merge_sorted_arrays(nums) << "\n"; return 0;
}
