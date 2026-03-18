/*
 * Exercise 1: Build from Pre+In
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
// Exercise 1: Build tree from preorder + inorder
// Hint: preorder[0] is root; find root in inorder to split left/right subtrees. Use hashmap for O(1) lookup.
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { return nullptr; /* TODO */ }
int main() {}
