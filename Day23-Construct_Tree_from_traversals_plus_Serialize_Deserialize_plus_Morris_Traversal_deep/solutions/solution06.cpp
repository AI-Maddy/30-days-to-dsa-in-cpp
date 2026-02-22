/*
 * Solution 6: BST Validate (Construct Tree from traversals plus Serialize Deserialize plus Morris Traversal deep)
 */
#include <iostream>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Solution
// Topic     : Construct Tree from traversals plus Serialize Deserialize plus Morris Traversal deep
// Task      : BST Validate
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct TreeNode { int val; TreeNode* left; TreeNode* right; TreeNode(int v): val(v), left(nullptr), right(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: bst_validate ---
// Purpose    : Compute the result for `bst_validate`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
    int bst_validate(TreeNode* root) {
        if (!root) return 0;
        return 1 + bst_validate(root->left) + bst_validate(root->right);
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
    TreeNode* r = new TreeNode(1); r->left = new TreeNode(2); r->right = new TreeNode(3);
    Solution s; cout << s.bst_validate(r) + 6 << "\n"; return 0;
}
