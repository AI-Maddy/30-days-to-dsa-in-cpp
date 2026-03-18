/*
 * Solution 5: Recover BST Morris
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
void recoverTree(TreeNode* root){
    TreeNode *first=nullptr,*second=nullptr,*prev=nullptr,*cur=root;
    while(cur){
        if(!cur->left){
            if(prev&&prev->val>cur->val){if(!first)first=prev;second=cur;}
            prev=cur;cur=cur->right;
        }else{
            TreeNode* pred=cur->left;
            while(pred->right&&pred->right!=cur)pred=pred->right;
            if(!pred->right){pred->right=cur;cur=cur->left;}
            else{pred->right=nullptr;
                if(prev&&prev->val>cur->val){if(!first)first=prev;second=cur;}
                prev=cur;cur=cur->right;}
        }
    }
    if(first&&second)swap(first->val,second->val);
}
void io(TreeNode* n){if(!n)return;io(n->left);cout<<n->val<<" ";io(n->right);}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    TreeNode* r=new TreeNode(3);r->left=new TreeNode(4);r->right=new TreeNode(2);
    r->left->left=new TreeNode(1);
    recoverTree(r);io(r);cout<<"\n";}
