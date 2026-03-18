/*
 * Example 5: Vertical Order
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 5: Vertical Order Traversal
vector<vector<int>> verticalOrder(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes; // col -> row -> values
    queue<tuple<TreeNode*, int, int>> q;
    q.push({root, 0, 0});
    while (!q.empty()) {
        auto [node, col, row] = q.front(); q.pop();
        nodes[col][row].insert(node->val);
        if (node->left)  q.push({node->left,  col - 1, row + 1});
        if (node->right) q.push({node->right, col + 1, row + 1});
    }
    vector<vector<int>> res;
    for (auto& [col, rowMap] : nodes) {
        vector<int> col_vals;
        for (auto& [row, vals] : rowMap)
            col_vals.insert(col_vals.end(), vals.begin(), vals.end());
        res.push_back(col_vals);
    }
    return res;
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9); root->right = new TreeNode(20);
    root->right->left = new TreeNode(15); root->right->right = new TreeNode(7);
    for (auto& col : verticalOrder(root)) { for (int x : col) cout << x << " "; cout << "\n"; }
}
