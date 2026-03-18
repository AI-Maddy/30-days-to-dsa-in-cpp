/*
 * Solution 1: Level Order BFS
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size(); vector<int> lv;
        for (int i = 0; i < sz; i++) {
            auto n = q.front(); q.pop();
            lv.push_back(n->val);
            if (n->left)  q.push(n->left);
            if (n->right) q.push(n->right);
        }
        res.push_back(lv);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    root->left->left = new TreeNode(4); root->left->right = new TreeNode(5);
    for (auto& lv : levelOrder(root)) { for (int x : lv) cout << x << " "; cout << "\n"; }
}
