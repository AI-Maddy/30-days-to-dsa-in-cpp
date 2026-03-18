/*
 * Solution 3: Kth Smallest
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st; auto cur=root; int cnt=0;
    while (cur||!st.empty()) {
        while (cur){st.push(cur);cur=cur->left;}
        cur=st.top();st.pop();
        if(++cnt==k) return cur->val;
        cur=cur->right;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r=new TreeNode(5);
    r->left=new TreeNode(3); r->right=new TreeNode(6);
    r->left->left=new TreeNode(2); r->left->right=new TreeNode(4);
    r->left->left->left=new TreeNode(1);
    cout<<kthSmallest(r,3)<<"\n";
}
