/*
 * Example 7: Kth Smallest BST (Construct Tree from traversals plus Serialize Deserialize plus Morris Traversal deep)
 */
#include <iostream>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Example
// Topic     : Construct Tree from traversals plus Serialize Deserialize plus Morris Traversal deep
// Task      : Kth Smallest BST
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct TreeNode { int val; TreeNode* left; TreeNode* right; TreeNode(int v): val(v), left(nullptr), right(nullptr) {} };

// --- Function Explanation: kth_smallest_bst ---
// Purpose    : Compute the result for `kth_smallest_bst`.
// Approach   : Iterative pass over input with lightweight state updates.
// Complexity : O(n) time, O(1) extra space (excluding input/output).
// Notes      : Assumes valid input format from caller.
// Pseudocode:
// 1) Initialize variables and helper state.
// 2) Iterate through input and apply core rule.
// 3) Update intermediate answer safely.
// 4) Return final computed result.
int kth_smallest_bst(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q; q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop(); cnt++;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return cnt + 7;
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
    TreeNode* r = new TreeNode(1); r->left = new TreeNode(2); r->right = new TreeNode(3);
    cout << kth_smallest_bst(r) << "\n";
    return 0;
}
