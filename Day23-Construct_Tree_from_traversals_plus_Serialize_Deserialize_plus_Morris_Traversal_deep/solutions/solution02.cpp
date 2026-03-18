/*
 * Solution 2: Build from In+Post
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
TreeNode* bp(vector<int>&post,int pl,int pr,vector<int>&ino,int il,int ir,unordered_map<int,int>&idx){
    if(pl>pr)return nullptr;
    int rv=post[pr],mid=idx[rv],ls=mid-il;
    TreeNode* r=new TreeNode(rv);
    r->left=bp(post,pl,pl+ls-1,ino,il,mid-1,idx);
    r->right=bp(post,pl+ls,pr-1,ino,mid+1,ir,idx);
    return r;
}
TreeNode* buildTree(vector<int>&inorder,vector<int>&postorder){
    unordered_map<int,int> idx; for(int i=0;i<(int)inorder.size();i++)idx[inorder[i]]=i;
    int n=postorder.size();
    return bp(postorder,0,n-1,inorder,0,n-1,idx);
}
void pre(TreeNode* n){if(!n)return;cout<<n->val<<" ";pre(n->left);pre(n->right);}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<int>in={9,3,15,20,7},post={9,15,7,20,3};
    pre(buildTree(in,post));cout<<"\n";}
