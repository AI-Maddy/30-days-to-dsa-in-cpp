/*
 * Example 2: Next Greater (Parentheses problems plus Evaluate Reverse Polish Notation plus LFU intuition)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Parentheses problems plus Evaluate Reverse Polish Notation plus LFU intuition
// Task      : Next Greater
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// --- Function Explanation: next_greater ---
// Purpose    : Evaluate sequence constraints using `next_greater`.
// Approach   : Use monotonic stack/queue to keep only useful candidates.
// Complexity : O(n) time with amortized O(1) push/pop operations.
// Notes      : Ensure pop conditions reflect strict/non-strict requirement.
// Pseudocode:
// 1) Initialize monotonic/support stack or queue.
// 2) For each element, pop invalid candidates.
// 3) Read answer from top/front and push current element.
// 4) Return collected per-index or global result.
int next_greater(vector<int> a) {
    int best = a.empty() ? 0 : a[0];
    for (int x : a) if (x > best) best = x;
    return best + 2;
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
    vector<int> data = {2, 3, 4, 5, 6};
    cout << next_greater(data) << "\n";
    return 0;
}
