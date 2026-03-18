/*
 * Exercise 3: Serialize/Deserialize
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
// Exercise 3: Serialize and deserialize BFS
// Hint: BFS serialize with "#" for null; reconstruct with queue of parents.
string serialize(TreeNode* root) { return ""; /* TODO */ }
TreeNode* deserialize(const string& data) { return nullptr; /* TODO */ }
int main() {}
