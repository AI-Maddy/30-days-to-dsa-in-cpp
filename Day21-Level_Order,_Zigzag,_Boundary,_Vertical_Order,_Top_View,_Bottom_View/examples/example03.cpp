/*
 * Example 3: Top View
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 3: Top View of Binary Tree
void topView(TreeNode* root) {
    if (!root) return;
    map<int, int> colMap; // col -> val of topmost node
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, col] = q.front(); q.pop();
        if (!colMap.count(col)) colMap[col] = node->val;
        if (node->left)  q.push({node->left,  col - 1});
        if (node->right) q.push({node->right, col + 1});
    }
    for (auto& [c, v] : colMap) cout << v << " ";
    cout << "\n";
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    root->left->left = new TreeNode(4); root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    topView(root);
}
