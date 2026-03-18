/*
 * Solution 4: Bottom View
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

void bottomView(TreeNode* root) {
    if (!root) return;
    map<int,int> m; queue<pair<TreeNode*,int>> q; q.push({root,0});
    while (!q.empty()) {
        auto [node,col] = q.front(); q.pop();
        m[col] = node->val;
        if (node->left)  q.push({node->left,  col-1});
        if (node->right) q.push({node->right, col+1});
    }
    for (auto& [c,v] : m) cout << v << " "; cout << "\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r = new TreeNode(20);
    r->left = new TreeNode(8); r->right = new TreeNode(22);
    r->left->left = new TreeNode(5); r->left->right = new TreeNode(3);
    r->left->right->left = new TreeNode(10); r->left->right->right = new TreeNode(14);
    bottomView(r);
}
