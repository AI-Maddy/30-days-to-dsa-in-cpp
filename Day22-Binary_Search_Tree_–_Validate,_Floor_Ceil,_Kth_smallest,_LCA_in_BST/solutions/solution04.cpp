/*
 * Solution 4: LCA in BST
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
TreeNode* lcaBST(TreeNode* root, int p, int q) {
    while (root) {
        if (p<root->val&&q<root->val) root=root->left;
        else if (p>root->val&&q>root->val) root=root->right;
        else return root;
    }
    return nullptr;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r=new TreeNode(6);
    r->left=new TreeNode(2); r->right=new TreeNode(8);
    r->left->left=new TreeNode(0); r->left->right=new TreeNode(4);
    cout<<lcaBST(r,2,4)->val<<"\n";
}
