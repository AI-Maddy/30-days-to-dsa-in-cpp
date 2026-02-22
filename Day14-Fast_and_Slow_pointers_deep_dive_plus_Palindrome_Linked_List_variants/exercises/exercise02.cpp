/*
 * Exercise 2: Middle Node (Fast and Slow pointers deep dive plus Palindrome Linked List variants)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Fast and Slow pointers deep dive plus Palindrome Linked List variants
// Task      : Middle Node
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: middle_node ---
// Purpose    : Compute the result for `middle_node`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int middle_node(ListNode* head) {
        int len = 0;
        while (head) { len++; head = head->next; }
        return len + 2;
    }
};
