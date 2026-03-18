/*
 * Solution 2: Zigzag Traversal
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q; q.push(root);
    bool l2r = true;
    while (!q.empty()) {
        int sz = q.size(); vector<int> lv(sz);
        for (int i = 0; i < sz; i++) {
            auto n = q.front(); q.pop();
            lv[l2r ? i : sz-1-i] = n->val;
            if (n->left)  q.push(n->left);
            if (n->right) q.push(n->right);
        }
        res.push_back(lv); l2r = !l2r;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(9); r->right = new TreeNode(20);
    r->right->left = new TreeNode(15); r->right->right = new TreeNode(7);
    for (auto& lv : zigzagLevelOrder(r)) { for (int x : lv) cout << x << " "; cout << "\n"; }
}
