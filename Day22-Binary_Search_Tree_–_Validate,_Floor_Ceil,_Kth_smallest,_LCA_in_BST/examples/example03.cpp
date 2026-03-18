/*
 * Example 3: Kth Smallest
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 3: Kth Smallest in BST (inorder = sorted)
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    int count = 0;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        if (++count == k) return cur->val;
        cur = cur->right;
    }
    return -1;
}
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3); root->right = new TreeNode(6);
    root->left->left = new TreeNode(2); root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    cout << kthSmallest(root, 3) << "\n"; // 3
}
