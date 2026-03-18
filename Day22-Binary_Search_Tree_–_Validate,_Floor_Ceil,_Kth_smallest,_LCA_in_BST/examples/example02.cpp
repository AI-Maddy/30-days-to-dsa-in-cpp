/*
 * Example 2: Floor and Ceil
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 2: Floor and Ceil in BST
// Floor: largest value <= key; Ceil: smallest value >= key
pair<int,int> floorCeil(TreeNode* root, int key) {
    int floor = -1, ceil = -1;
    TreeNode* cur = root;
    while (cur) {
        if (cur->val == key) { floor = ceil = key; break; }
        if (cur->val < key) { floor = cur->val; cur = cur->right; }
        else { ceil = cur->val; cur = cur->left; }
    }
    return {floor, ceil};
}
int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4); root->right = new TreeNode(12);
    root->left->left = new TreeNode(2); root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10); root->right->right = new TreeNode(14);
    auto [f,c] = floorCeil(root, 11);
    cout << "floor=" << f << " ceil=" << c << "\n"; // 10, 12
}
