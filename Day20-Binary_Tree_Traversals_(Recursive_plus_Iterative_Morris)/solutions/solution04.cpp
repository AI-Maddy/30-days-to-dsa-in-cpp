/*
 * Solution 4: Diameter
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(nullptr),right(nullptr){}};
TreeNode* build(vector<int>v){if(v.empty())return nullptr;TreeNode*r=new TreeNode(v[0]);queue<TreeNode*>q;q.push(r);int i=1;while(i<(int)v.size()){TreeNode*c=q.front();q.pop();if(i<(int)v.size()&&v[i]!=-1){c->left=new TreeNode(v[i]);q.push(c->left);}i++;if(i<(int)v.size()&&v[i]!=-1){c->right=new TreeNode(v[i]);q.push(c->right);}i++;}return r;}
int diameter(TreeNode*r){int ans=0;function<int(TreeNode*)>h=[&](TreeNode*n)->int{if(!n)return 0;int l=h(n->left),ri=h(n->right);ans=max(ans,l+ri);return max(l,ri)+1;};h(r);return ans;}
int main(){
    TreeNode*r=build({1,2,3,4,5});
    cout<<diameter(r)<<"\n"; // 3
    return 0;
}
