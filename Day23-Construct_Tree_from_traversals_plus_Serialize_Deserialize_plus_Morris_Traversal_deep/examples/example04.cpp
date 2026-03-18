/*
 * Example 4: Morris Inorder
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 4: Morris Inorder Traversal (O(1) space)
void morrisInorder(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        if (!cur->left) {
            cout << cur->val << " ";
            cur = cur->right;
        } else {
            // Find inorder predecessor
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) {
                pred->right = cur; // thread
                cur = cur->left;
            } else {
                pred->right = nullptr; // unthread
                cout << cur->val << " ";
                cur = cur->right;
            }
        }
    }
    cout << "\n";
}
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3); root->right = new TreeNode(7);
    root->left->left = new TreeNode(1); root->left->right = new TreeNode(4);
    morrisInorder(root);
}
