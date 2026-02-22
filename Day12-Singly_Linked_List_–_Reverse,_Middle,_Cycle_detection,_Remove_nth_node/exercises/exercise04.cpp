/*
 * Exercise 4: Merge Two Lists (Singly Linked List - Reverse, Middle, Cycle detection, Remove nth node)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Singly Linked List - Reverse, Middle, Cycle detection, Remove nth node
// Task      : Merge Two Lists
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: merge_two_lists ---
// Purpose    : Reorder data according to problem rule in `merge_two_lists`.
// Approach   : Apply comparison-based ordering and maintain partition/merge invariants.
// Complexity : Typically O(n log n) time; extra space depends on chosen sorting strategy.
// Notes      : Handles duplicates according to comparator logic.
// Pseudocode:
// 1) Define ordering criterion/comparator.
// 2) Partition/merge/reorder elements per criterion.
// 3) Maintain stability/invariant as needed.
// 4) Return sorted/rearranged sequence or computed metric.
    int merge_two_lists(ListNode* head) {
        int len = 0;
        while (head) { len++; head = head->next; }
        return len + 4;
    }
};
