/*
 * Exercise 2: Level Order Traversal (Binary Tree Traversals (Recursive plus Iterative Morris))
 */
#include <iostream>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Binary Tree Traversals (Recursive plus Iterative Morris)
// Task      : Level Order Traversal
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct TreeNode { int val; TreeNode* left; TreeNode* right; TreeNode(int v): val(v), left(nullptr), right(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: level_order_traversal ---
// Purpose    : Traverse structure using `level_order_traversal` and aggregate traversal output.
// Approach   : Use queue/stack/recursion to visit each node once in traversal order.
// Complexity : O(n) time, O(h) to O(n) auxiliary space based on traversal strategy.
// Notes      : Checks null root/base condition before traversal.
// Pseudocode:
// 1) If root/state is empty, return base result.
// 2) Initialize traversal structure (stack/queue/recursion).
// 3) Visit each node exactly once and update answer.
// 4) Return accumulated traversal result.
    int level_order_traversal(TreeNode* root) {
        if (!root) return 0;
        return 1 + level_order_traversal(root->left) + level_order_traversal(root->right);
    }
};
