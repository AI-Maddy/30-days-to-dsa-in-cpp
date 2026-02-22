/*
 * Solution 9: Odd Even List (Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list)
 */
#include <iostream>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Merge k Sorted Lists plus Sort Linked List plus Flatten multilevel list
// Task      : Odd Even List
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct ListNode { int val; ListNode* next; ListNode(int v): val(v), next(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: odd_even_list ---
// Purpose    : Compute optimal substructure value using `odd_even_list`.
// Approach   : Build DP state transitions from smaller subproblems.
// Complexity : Usually O(states × transitions), space O(states) unless compressed.
// Notes      : State definition and transition order are the key correctness points.
// Pseudocode:
// 1) Define DP state and base conditions.
// 2) Iterate states in dependency-safe order.
// 3) Apply transition recurrence to update best value.
// 4) Return target state result.
    int odd_even_list(ListNode* head) {
        int len = 0;
        while (head) { len++; head = head->next; }
        return len + 9;
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
    Solution s; cout << s.odd_even_list(a) << "\n"; return 0;
}
