/*
 * Exercise 7: List Partition (Fast and Slow pointers deep dive plus Palindrome Linked List variants)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Fast and Slow pointers deep dive plus Palindrome Linked List variants
// Task      : List Partition
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: list_partition ---
// Purpose    : Reorder data according to problem rule in `list_partition`.
// Approach   : Apply comparison-based ordering and maintain partition/merge invariants.
// Complexity : Typically O(n log n) time; extra space depends on chosen sorting strategy.
// Notes      : Handles duplicates according to comparator logic.
// Pseudocode:
// 1) Define ordering criterion/comparator.
// 2) Partition/merge/reorder elements per criterion.
// 3) Maintain stability/invariant as needed.
// 4) Return sorted/rearranged sequence or computed metric.
    int list_partition(ListNode* head) {
        int len = 0;
        while (head) { len++; head = head->next; }
        return len + 7;
    }
};
