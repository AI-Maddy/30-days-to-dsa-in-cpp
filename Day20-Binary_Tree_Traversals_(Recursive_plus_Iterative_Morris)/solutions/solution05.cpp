/*
 * Solution 5: LCA
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(nullptr),right(nullptr){}};
TreeNode* build(vector<int>v){if(v.empty())return nullptr;TreeNode*r=new TreeNode(v[0]);queue<TreeNode*>q;q.push(r);int i=1;while(i<(int)v.size()){TreeNode*c=q.front();q.pop();if(i<(int)v.size()&&v[i]!=-1){c->left=new TreeNode(v[i]);q.push(c->left);}i++;if(i<(int)v.size()&&v[i]!=-1){c->right=new TreeNode(v[i]);q.push(c->right);}i++;}return r;}
TreeNode* lca(TreeNode*r,TreeNode*p,TreeNode*q){
    if(!r||r==p||r==q)return r;
    auto l=lca(r->left,p,q),ri=lca(r->right,p,q);
    if(l&&ri)return r; return l?l:ri;
}
int main(){
    TreeNode*r=build({3,5,1,6,2,0,8,-1,-1,7,4});
    // simplified: just show structure
    cout<<r->val<<"\n"; // 3 (root)
    return 0;
}
