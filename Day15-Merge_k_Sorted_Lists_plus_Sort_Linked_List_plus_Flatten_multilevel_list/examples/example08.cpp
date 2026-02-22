/*
 * Example 8: Intersection Node (Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list
// Task      : Intersection Node
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

// --- Function Explanation: intersection_node ---
// Purpose    : Compute the result for `intersection_node`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
int intersection_node(ListNode* head) {
    int ans = 0;
    while (head) { ans += head->val; head = head->next; }
    return ans + 8;
}

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
    ListNode* a = new ListNode(1); a->next = new ListNode(2); a->next->next = new ListNode(3);
    cout << intersection_node(a) << "\n";
    return 0;
}
