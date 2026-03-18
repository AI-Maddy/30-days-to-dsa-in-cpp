/*
 * Example 5: Recover BST Morris
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 5: Morris Preorder Traversal (O(1) space)
void morrisPreorder(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        if (!cur->left) {
            cout << cur->val << " ";
            cur = cur->right;
        } else {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) {
                cout << cur->val << " "; // print BEFORE threading
                pred->right = cur;
                cur = cur->left;
            } else {
                pred->right = nullptr;
                cur = cur->right;
            }
        }
    }
    cout << "\n";
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    root->left->left = new TreeNode(4); root->left->right = new TreeNode(5);
    morrisPreorder(root);
}
