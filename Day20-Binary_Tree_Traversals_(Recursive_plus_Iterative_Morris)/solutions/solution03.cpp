/*
 * Solution 3: Tree Height
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(nullptr),right(nullptr){}};
TreeNode* build(vector<int>v){if(v.empty())return nullptr;TreeNode*r=new TreeNode(v[0]);queue<TreeNode*>q;q.push(r);int i=1;while(i<(int)v.size()){TreeNode*c=q.front();q.pop();if(i<(int)v.size()&&v[i]!=-1){c->left=new TreeNode(v[i]);q.push(c->left);}i++;if(i<(int)v.size()&&v[i]!=-1){c->right=new TreeNode(v[i]);q.push(c->right);}i++;}return r;}
int height(TreeNode*r){return r?max(height(r->left),height(r->right))+1:0;}
int main(){
    TreeNode*r=build({3,9,20,-1,-1,15,7});
    cout<<height(r)<<"\n"; // 3
    return 0;
}
