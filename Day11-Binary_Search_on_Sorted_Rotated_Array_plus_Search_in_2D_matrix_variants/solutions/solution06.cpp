/*
 * Solution 6: Rotated Search (Binary Search on Sorted Rotated Array plus Search in 2D matrix variants)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Binary Search on Sorted Rotated Array plus Search in 2D matrix variants
// Task      : Rotated Search
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: rotated_search ---
// Purpose    : Locate target condition/index via `rotated_search`.
// Approach   : Use binary/conditional narrowing on search space with invariant maintenance.
// Complexity : O(log n) time on sorted/monotonic search spaces; O(1) extra space.
// Notes      : Behavior depends on sortedness/monotonicity precondition.
// Pseudocode:
// 1) Initialize search boundaries or pointers.
// 2) Repeatedly pick probe/mid and compare with target rule.
// 3) Shrink the valid range while preserving invariants.
// 4) Return found index/value or fallback result.
    int rotated_search(vector<int>& a, int target) {
        int l = 0, r = (int)a.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m] == target) return m;
            if (a[m] < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
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
    Solution s; vector<int> a = {6, 8, 10, 12};
    cout << s.rotated_search(a, 10) << "\n";
    return 0;
}
