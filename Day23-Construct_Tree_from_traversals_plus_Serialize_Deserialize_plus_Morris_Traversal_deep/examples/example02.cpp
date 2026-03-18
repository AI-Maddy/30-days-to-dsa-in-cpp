/*
 * Example 2: Build from In+Post
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 2: Construct Binary Tree from Inorder + Postorder
TreeNode* buildPost(vector<int>& post, int pl, int pr,
                    vector<int>& ino, int il, int ir,
                    unordered_map<int,int>& idx) {
    if (pl > pr) return nullptr;
    int rootVal = post[pr];
    int mid = idx[rootVal];
    int leftSize = mid - il;
    TreeNode* root = new TreeNode(rootVal);
    root->left  = buildPost(post, pl, pl+leftSize-1, ino, il, mid-1, idx);
    root->right = buildPost(post, pl+leftSize, pr-1, ino, mid+1, ir, idx);
    return root;
}
TreeNode* buildTreePost(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> idx;
    for (int i = 0; i < (int)inorder.size(); i++) idx[inorder[i]] = i;
    int n = postorder.size();
    return buildPost(postorder, 0, n-1, inorder, 0, n-1, idx);
}
void pre(TreeNode* n) { if(!n)return; cout<<n->val<<" "; pre(n->left); pre(n->right); }
int main() {
    vector<int> ino={9,3,15,20,7}, post={9,15,7,20,3};
    TreeNode* root = buildTreePost(ino, post);
    pre(root); cout << "\n";
}
