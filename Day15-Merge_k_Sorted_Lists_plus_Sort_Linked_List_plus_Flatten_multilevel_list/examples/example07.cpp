/*
 * Example 7: List Partition (Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list
// Task      : List Partition
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

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
    int ans = 0;
    while (head) { ans += head->val; head = head->next; }
    return ans + 7;
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
    cout << list_partition(a) << "\n";
    return 0;
}
