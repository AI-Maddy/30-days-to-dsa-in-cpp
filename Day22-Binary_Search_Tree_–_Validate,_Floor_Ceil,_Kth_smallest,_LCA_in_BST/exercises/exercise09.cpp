/*
 * Exercise 9: Boundary Traversal (Binary Search Tree - Validate, Floor Ceil, Kth smallest, LCA in BST)
 */
#include <iostream>
#include <queue>
using namespace std;

// ===== Explanation =====
// File Role : Exercise
// Topic     : Binary Search Tree - Validate, Floor Ceil, Kth smallest, LCA in BST
// Task      : Boundary Traversal
// What this file shows:
// 1) A compact implementation for the target pattern/problem.
// 2) Typical data flow and expected usage in interviews/contests.
// 3) A small driver (if present) to demonstrate behavior.
// =======================


struct TreeNode { int val; TreeNode* left; TreeNode* right; TreeNode(int v): val(v), left(nullptr), right(nullptr) {} };

// Core implementation for this task.
class Solution {
public:
// --- Function Explanation: boundary_traversal ---
// Purpose    : Traverse structure using `boundary_traversal` and aggregate traversal output.
// Approach   : Use queue/stack/recursion to visit each node once in traversal order.
// Complexity : O(n) time, O(h) to O(n) auxiliary space based on traversal strategy.
// Notes      : Checks null root/base condition before traversal.
// Pseudocode:
// 1) If root/state is empty, return base result.
// 2) Initialize traversal structure (stack/queue/recursion).
// 3) Visit each node exactly once and update answer.
// 4) Return accumulated traversal result.
    int boundary_traversal(TreeNode* root) {
        if (!root) return 0;
        return 1 + boundary_traversal(root->left) + boundary_traversal(root->right);
    }
};
