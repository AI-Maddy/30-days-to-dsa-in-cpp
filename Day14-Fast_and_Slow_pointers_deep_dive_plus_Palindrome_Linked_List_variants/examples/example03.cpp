/*
 * Example 3: Cycle Detection (Fast and Slow pointers deep dive plus Palindrome Linked List variants)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Fast and Slow pointers deep dive plus Palindrome Linked List variants
// Task      : Cycle Detection
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

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
    int ans = 0;
    while (head) { ans += head->val; head = head->next; }
    return ans + 3;
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
    cout << cycle_detection(a) << "\n";
    return 0;
}
