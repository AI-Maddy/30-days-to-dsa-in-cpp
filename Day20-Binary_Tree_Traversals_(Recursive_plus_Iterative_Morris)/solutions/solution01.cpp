/*
 * Solution 1: Inorder Traversal
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(nullptr),right(nullptr){}};
TreeNode* build(vector<int>v){if(v.empty())return nullptr;TreeNode*r=new TreeNode(v[0]);queue<TreeNode*>q;q.push(r);int i=1;while(i<(int)v.size()){TreeNode*c=q.front();q.pop();if(i<(int)v.size()&&v[i]!=-1){c->left=new TreeNode(v[i]);q.push(c->left);}i++;if(i<(int)v.size()&&v[i]!=-1){c->right=new TreeNode(v[i]);q.push(c->right);}i++;}return r;}
void inorder(TreeNode*r,vector<int>&res){if(!r)return;inorder(r->left,res);res.push_back(r->val);inorder(r->right,res);}
vector<int> inorderIter(TreeNode*r){vector<int>res;stack<TreeNode*>st;while(r||!st.empty()){while(r){st.push(r);r=r->left;}r=st.top();st.pop();res.push_back(r->val);r=r->right;}return res;}
// Morris inorder: O(1) space
vector<int> morrisInorder(TreeNode*r){vector<int>res;while(r){if(!r->left){res.push_back(r->val);r=r->right;}else{TreeNode*pre=r->left;while(pre->right&&pre->right!=r)pre=pre->right;if(!pre->right){pre->right=r;r=r->left;}else{pre->right=nullptr;res.push_back(r->val);r=r->right;}}}return res;}
int main(){
    TreeNode*r=build({1,-1,2,3}); // 1->null,2->3,null
    r=new TreeNode(1);r->right=new TreeNode(2);r->right->left=new TreeNode(3);
    for(int x:inorder(r,*(new vector<int>{})))cout<<x<<" "; // not clean - use below
    vector<int>res; inorder(r,res); for(int x:res)cout<<x<<" "; cout<<"\n"; // 1 3 2
    for(int x:morrisInorder(r))cout<<x<<" "; cout<<"\n"; // 1 3 2
    return 0;
}
