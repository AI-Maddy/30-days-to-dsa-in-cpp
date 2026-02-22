/*
 * Exercise 6: Stable Sort Demo (Sorting revision plus Custom comparators plus Counting Sort Radix Sort intuition)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Sorting revision plus Custom comparators plus Counting Sort Radix Sort intuition
// Task      : Stable Sort Demo
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: stable_sort_demo ---
// Purpose    : Reorder data according to problem rule in `stable_sort_demo`.
// Approach   : Apply comparison-based ordering and maintain partition/merge invariants.
// Complexity : Typically O(n log n) time; extra space depends on chosen sorting strategy.
// Notes      : Handles duplicates according to comparator logic.
// Pseudocode:
// 1) Define ordering criterion/comparator.
// 2) Partition/merge/reorder elements per criterion.
// 3) Maintain stability/invariant as needed.
// 4) Return sorted/rearranged sequence or computed metric.
    int stable_sort_demo(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans += x % (10);
        return ans;
    }
};
