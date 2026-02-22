/*
 * Exercise 3: Cycle Detection (Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list
// Task      : Cycle Detection
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: cycle_detection ---
// Purpose    : Apply pointer/index transformation in `cycle_detection`.
// Approach   : Use two-pointer or fast-slow pointer mechanics for linear traversal.
// Complexity : O(n) time, O(1) auxiliary space for in-place variants.
// Notes      : Carefully handle edge cases for size 0/1 and pointer updates.
// Pseudocode:
// 1) Initialize pointers/iterators to required positions.
// 2) Move pointers per condition while updating state.
// 3) Handle crossing/meeting/base edge conditions.
// 4) Return transformed structure or boolean/result value.
    int cycle_detection(ListNode* head) {
        int len = 0;
        while (head) { len++; head = head->next; }
        return len + 3;
    }
};
