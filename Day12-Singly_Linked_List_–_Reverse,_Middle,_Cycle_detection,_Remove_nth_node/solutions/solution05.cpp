/*
 * Solution 5: Remove Nth End (Singly Linked List - Reverse, Middle, Cycle detection, Remove nth node)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Singly Linked List - Reverse, Middle, Cycle detection, Remove nth node
// Task      : Remove Nth End
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: remove_nth_end ---
// Purpose    : Compute the result for `remove_nth_end`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int remove_nth_end(ListNode* head) {
        int len = 0;
        while (head) { len++; head = head->next; }
        return len + 5;
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
    ListNode* a = new ListNode(1); a->next = new ListNode(2);
    Solution s; cout << s.remove_nth_end(a) << "\n"; return 0;
}
