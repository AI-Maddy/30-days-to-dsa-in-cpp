/*
 * Example 2: Zigzag Traversal
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 2: Zigzag Level-Order Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; i++) {
            auto node = q.front(); q.pop();
            int idx = leftToRight ? i : sz - 1 - i;
            level[idx] = node->val;
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
        leftToRight = !leftToRight;
    }
    return res;
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9); root->right = new TreeNode(20);
    root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);
    for (auto& lv : zigzagLevelOrder(root)) { for (int x : lv) cout << x << " "; cout << "\n"; }
}
