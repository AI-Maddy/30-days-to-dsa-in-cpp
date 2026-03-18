/*
 * Example 1: Build from Pre+In
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 1: Construct Binary Tree from Preorder + Inorder
TreeNode* build(vector<int>& pre, int pl, int pr,
                vector<int>& ino, int il, int ir,
                unordered_map<int,int>& idx) {
    if (pl > pr) return nullptr;
    int rootVal = pre[pl];
    int mid = idx[rootVal];
    int leftSize = mid - il;
    TreeNode* root = new TreeNode(rootVal);
    root->left  = build(pre, pl+1, pl+leftSize, ino, il, mid-1, idx);
    root->right = build(pre, pl+leftSize+1, pr, ino, mid+1, ir, idx);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> idx;
    for (int i = 0; i < (int)inorder.size(); i++) idx[inorder[i]] = i;
    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, idx);
}
void inorderPrint(TreeNode* n) { if(!n)return; inorderPrint(n->left); cout<<n->val<<" "; inorderPrint(n->right); }
int main() {
    vector<int> pre = {3,9,20,15,7}, in = {9,3,15,20,7};
    TreeNode* root = buildTree(pre, in);
    inorderPrint(root); cout << "\n";
}
