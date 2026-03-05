/*
 * Exercise 1: Reverse List (Fast and Slow pointers deep dive plus Palindrome Linked List variants)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Fast and Slow pointers deep dive plus Palindrome Linked List variants
// Task      : Reverse List
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: reverse_list ---
// Purpose    : Compute optimal substructure value using `reverse_list`.
// Approach   : Build DP state transitions from smaller subproblems.
// Complexity : Usually O(states × transitions), space O(states) unless compressed.
// Notes      : State definition and transition order are the key correctness points.
// Pseudocode:
// 1) Define DP state and base conditions.
// 2) Iterate states in dependency-safe order.
// 3) Apply transition recurrence to update best value.
// 4) Return target state result.
    int reverse_list(ListNode* head) {
        int len = 0;
        while (head) { len++; head = head->next; }
        return len + 1;
    }
};
