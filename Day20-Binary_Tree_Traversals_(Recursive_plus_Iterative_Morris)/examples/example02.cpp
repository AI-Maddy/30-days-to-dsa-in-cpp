/*
 * Example 2: Level Order Traversal
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(nullptr),right(nullptr){}};
TreeNode* build(vector<int>v){if(v.empty())return nullptr;TreeNode*r=new TreeNode(v[0]);queue<TreeNode*>q;q.push(r);int i=1;while(i<(int)v.size()){TreeNode*c=q.front();q.pop();if(i<(int)v.size()&&v[i]!=-1){c->left=new TreeNode(v[i]);q.push(c->left);}i++;if(i<(int)v.size()&&v[i]!=-1){c->right=new TreeNode(v[i]);q.push(c->right);}i++;}return r;}
vector<vector<int>> levelOrder(TreeNode*root){
    vector<vector<int>>res;if(!root)return res;
    queue<TreeNode*>q;q.push(root);
    while(!q.empty()){int sz=q.size();vector<int>level;for(int i=0;i<sz;i++){auto n=q.front();q.pop();level.push_back(n->val);if(n->left)q.push(n->left);if(n->right)q.push(n->right);}res.push_back(level);}
    return res;
}
int main(){
    TreeNode*r=build({3,9,20,-1,-1,15,7});
    for(auto&l:levelOrder(r)){for(int x:l)cout<<x<<" ";cout<<"\n";}
    return 0;
}
