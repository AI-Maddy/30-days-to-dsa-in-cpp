/*
 * Solution 3: Top View
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

void topView(TreeNode* root) {
    if (!root) return;
    map<int,int> m; queue<pair<TreeNode*,int>> q; q.push({root,0});
    while (!q.empty()) {
        auto [node,col] = q.front(); q.pop();
        if (!m.count(col)) m[col] = node->val;
        if (node->left)  q.push({node->left,  col-1});
        if (node->right) q.push({node->right, col+1});
    }
    for (auto& [c,v] : m) cout << v << " "; cout << "\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2); r->right = new TreeNode(3);
    r->left->left = new TreeNode(4); r->left->right = new TreeNode(5);
    r->right->right = new TreeNode(6);
    topView(r);
}
