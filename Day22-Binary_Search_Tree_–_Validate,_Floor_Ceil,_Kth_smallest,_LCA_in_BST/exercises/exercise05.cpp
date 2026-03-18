/*
 * Exercise 5: Insert and Delete BST
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
// Exercise 5: Delete a node from BST
// Hint: Find the inorder successor (min of right subtree) to replace deleted node.
TreeNode* deleteNode(TreeNode* root, int key) { return root; /* TODO */ }
int main() {}
