/*
 * Example 5: Insert and Delete BST
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 5: Insert into BST and Delete from BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}
TreeNode* findMin(TreeNode* n) { while (n->left) n = n->left; return n; }
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* succ = findMin(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }
    return root;
}
void inorder(TreeNode* n) { if(!n)return; inorder(n->left); cout<<n->val<<" "; inorder(n->right); }
int main() {
    TreeNode* root = nullptr;
    for (int x : {5,3,7,1,4,6,8}) root = insert(root, x);
    inorder(root); cout << "\n";
    root = deleteNode(root, 3);
    inorder(root); cout << "\n";
}
