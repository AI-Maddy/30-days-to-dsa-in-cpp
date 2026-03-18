/*
 * Solution 1: Validate BST
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
bool isValidBST(TreeNode* root, long lo=LONG_MIN, long hi=LONG_MAX) {
    if (!root) return true;
    if (root->val<=lo || root->val>=hi) return false;
    return isValidBST(root->left,lo,root->val) && isValidBST(root->right,root->val,hi);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r = new TreeNode(2); r->left=new TreeNode(1); r->right=new TreeNode(3);
    cout << isValidBST(r) << "\n"; // 1
}
