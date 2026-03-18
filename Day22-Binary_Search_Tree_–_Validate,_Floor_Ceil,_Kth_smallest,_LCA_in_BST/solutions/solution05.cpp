/*
 * Solution 5: Insert and Delete BST
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
TreeNode* findMin(TreeNode* n){while(n->left)n=n->left;return n;}
TreeNode* deleteNode(TreeNode* root,int key){
    if(!root)return nullptr;
    if(key<root->val) root->left=deleteNode(root->left,key);
    else if(key>root->val) root->right=deleteNode(root->right,key);
    else{
        if(!root->left)return root->right;
        if(!root->right)return root->left;
        auto s=findMin(root->right); root->val=s->val;
        root->right=deleteNode(root->right,s->val);
    }
    return root;
}
TreeNode* ins(TreeNode* r,int v){if(!r)return new TreeNode(v);if(v<r->val)r->left=ins(r->left,v);else r->right=ins(r->right,v);return r;}
void io(TreeNode* n){if(!n)return;io(n->left);cout<<n->val<<" ";io(n->right);}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r=nullptr;
    for(int x:{5,3,7,1,4,6,8})r=ins(r,x);
    r=deleteNode(r,3); io(r); cout<<"\n";
}
