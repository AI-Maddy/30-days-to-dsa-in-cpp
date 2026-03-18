/*
 * Example 4: LCA in BST
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 4: LCA in BST
// In BST: LCA is first node where p <= node <= q (or q <= node <= p)
TreeNode* lcaBST(TreeNode* root, int p, int q) {
    while (root) {
        if (p < root->val && q < root->val) root = root->left;
        else if (p > root->val && q > root->val) root = root->right;
        else return root;
    }
    return nullptr;
}
int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2); root->right = new TreeNode(8);
    root->left->left = new TreeNode(0); root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3); root->left->right->right = new TreeNode(5);
    cout << lcaBST(root, 2, 4)->val << "\n"; // 2
    cout << lcaBST(root, 2, 8)->val << "\n"; // 6
}
