/*
 * Example 5: BST to DLL
 */
#include <bits/stdc++.h>
using namespace std;
// Convert BST to sorted doubly linked list in-place
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(nullptr),right(nullptr){}};
TreeNode*prev_node=nullptr,*head_dll=nullptr;
void inorder(TreeNode*root){
    if(!root)return;
    inorder(root->left);
    if(prev_node){prev_node->right=root;root->left=prev_node;}
    else head_dll=root;
    prev_node=root;
    inorder(root->right);
}
int main(){
    TreeNode* r=new TreeNode(4);r->left=new TreeNode(2);r->right=new TreeNode(6);r->left->left=new TreeNode(1);r->left->right=new TreeNode(3);r->right->left=new TreeNode(5);r->right->right=new TreeNode(7);
    inorder(r);
    TreeNode*c=head_dll;while(c){cout<<c->val<<" ";c=c->right;}cout<<"\n"; // 1 2 3 4 5 6 7
    return 0;
}
