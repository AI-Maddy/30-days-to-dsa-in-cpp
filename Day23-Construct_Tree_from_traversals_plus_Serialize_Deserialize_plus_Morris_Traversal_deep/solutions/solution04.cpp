/*
 * Solution 4: Morris Inorder
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
void morrisInorder(TreeNode* root){
    TreeNode* cur=root;
    while(cur){
        if(!cur->left){cout<<cur->val<<" ";cur=cur->right;}
        else{TreeNode* pred=cur->left;
            while(pred->right&&pred->right!=cur)pred=pred->right;
            if(!pred->right){pred->right=cur;cur=cur->left;}
            else{pred->right=nullptr;cout<<cur->val<<" ";cur=cur->right;}
        }
    }cout<<"\n";
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    TreeNode* r=new TreeNode(4);r->left=new TreeNode(2);r->right=new TreeNode(6);
    r->left->left=new TreeNode(1);r->left->right=new TreeNode(3);
    morrisInorder(r);}
