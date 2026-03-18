/*
 * Exercise 5: Vertical Order
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Exercise 5: Boundary Traversal
// Print: left boundary (top-down, no leaves) + all leaves + right boundary (bottom-up, no leaves).
// Hint: Three separate passes: left boundary, leaf nodes (DFS), right boundary reversed.
void boundaryTraversal(TreeNode* root) {
    // TODO
}
int main() {}
