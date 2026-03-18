/*
 * Solution 2: Floor and Ceil
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
pair<int,int> floorCeil(TreeNode* root, int key) {
    int fl=-1,ce=-1; auto cur=root;
    while (cur) {
        if (cur->val==key) return {key,key};
        if (cur->val<key) { fl=cur->val; cur=cur->right; }
        else { ce=cur->val; cur=cur->left; }
    }
    return {fl,ce};
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r=new TreeNode(8);
    r->left=new TreeNode(4); r->right=new TreeNode(12);
    r->left->left=new TreeNode(2); r->left->right=new TreeNode(6);
    r->right->left=new TreeNode(10); r->right->right=new TreeNode(14);
    auto [f,c]=floorCeil(r,11); cout<<f<<" "<<c<<"\n";
}
