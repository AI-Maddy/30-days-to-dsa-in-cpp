/*
 * Example 1: Validate BST
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 1: Validate BST
bool isValidBST(TreeNode* root, long lo = LONG_MIN, long hi = LONG_MAX) {
    if (!root) return true;
    if (root->val <= lo || root->val >= hi) return false;
    return isValidBST(root->left, lo, root->val) &&
           isValidBST(root->right, root->val, hi);
}
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1); root->right = new TreeNode(4);
    root->right->left = new TreeNode(3); root->right->right = new TreeNode(6);
    cout << (isValidBST(root) ? "valid" : "invalid") << "\n"; // invalid
}
