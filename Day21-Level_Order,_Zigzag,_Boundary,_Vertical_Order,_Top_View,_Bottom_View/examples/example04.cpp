/*
 * Example 4: Bottom View
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 4: Bottom View of Binary Tree
void bottomView(TreeNode* root) {
    if (!root) return;
    map<int, int> colMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, col] = q.front(); q.pop();
        colMap[col] = node->val; // overwrite — last level wins
        if (node->left)  q.push({node->left,  col - 1});
        if (node->right) q.push({node->right, col + 1});
    }
    for (auto& [c, v] : colMap) cout << v << " ";
    cout << "\n";
}
int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8); root->right = new TreeNode(22);
    root->left->left = new TreeNode(5); root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(10); root->left->right->right = new TreeNode(14);
    bottomView(root);
}
