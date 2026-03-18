/*
 * Solution 1: Build from Pre+In
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
TreeNode* build(vector<int>&pre,int pl,int pr,vector<int>&ino,int il,int ir,unordered_map<int,int>&idx){
    if(pl>pr)return nullptr;
    int rv=pre[pl],mid=idx[rv],ls=mid-il;
    TreeNode* r=new TreeNode(rv);
    r->left=build(pre,pl+1,pl+ls,ino,il,mid-1,idx);
    r->right=build(pre,pl+ls+1,pr,ino,mid+1,ir,idx);
    return r;
}
TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder){
    unordered_map<int,int> idx; for(int i=0;i<(int)inorder.size();i++)idx[inorder[i]]=i;
    return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,idx);
}
void io(TreeNode* n){if(!n)return;io(n->left);cout<<n->val<<" ";io(n->right);}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>pre={3,9,20,15,7},in={9,3,15,20,7};
    io(buildTree(pre,in));cout<<"\n";}
