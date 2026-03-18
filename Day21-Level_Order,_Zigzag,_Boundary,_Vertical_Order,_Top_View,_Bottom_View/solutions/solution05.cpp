/*
 * Solution 5: Vertical Order
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

bool isLeaf(TreeNode* n) { return !n->left && !n->right; }
void addLeaves(TreeNode* n, vector<int>& res) {
    if (!n) return;
    if (isLeaf(n)) { res.push_back(n->val); return; }
    addLeaves(n->left, res); addLeaves(n->right, res);
}
vector<int> boundaryTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res = {root->val};
    // left boundary (not leaf)
    TreeNode* cur = root->left;
    while (cur) { if (!isLeaf(cur)) res.push_back(cur->val); cur = cur->left ? cur->left : cur->right; }
    // leaves
    addLeaves(root->left, res); addLeaves(root->right, res);
    // right boundary (not leaf), reversed
    vector<int> right;
    cur = root->right;
    while (cur) { if (!isLeaf(cur)) right.push_back(cur->val); cur = cur->right ? cur->right : cur->left; }
    reverse(right.begin(), right.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    TreeNode* r = new TreeNode(20);
    r->left = new TreeNode(8); r->right = new TreeNode(22);
    r->left->left = new TreeNode(4); r->left->right = new TreeNode(12);
    r->left->right->left = new TreeNode(10); r->left->right->right = new TreeNode(14);
    r->right->left = new TreeNode(25);
    for (int x : boundaryTraversal(r)) cout << x << " "; cout << "\n";
}
