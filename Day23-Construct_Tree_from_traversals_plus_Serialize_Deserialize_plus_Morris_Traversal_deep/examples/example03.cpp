/*
 * Example 3: Serialize/Deserialize
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left,*right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Example 3: Serialize and Deserialize Binary Tree (BFS-based)
string serialize(TreeNode* root) {
    if (!root) return "";
    string s; queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        auto n = q.front(); q.pop();
        if (!n) { s += "# "; continue; }
        s += to_string(n->val) + " ";
        q.push(n->left); q.push(n->right);
    }
    return s;
}
TreeNode* deserialize(const string& data) {
    if (data.empty()) return nullptr;
    istringstream ss(data); string token;
    ss >> token;
    TreeNode* root = new TreeNode(stoi(token));
    queue<TreeNode*> q; q.push(root);
    while (ss >> token) {
        auto parent = q.front(); q.pop();
        if (token != "#") { parent->left = new TreeNode(stoi(token)); q.push(parent->left); }
        ss >> token;
        if (token != "#") { parent->right = new TreeNode(stoi(token)); q.push(parent->right); }
    }
    return root;
}
void inorderPrint(TreeNode* n) { if(!n)return; inorderPrint(n->left); cout<<n->val<<" "; inorderPrint(n->right); }
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); root->right = new TreeNode(3);
    root->right->left = new TreeNode(4); root->right->right = new TreeNode(5);
    string s = serialize(root);
    cout << s << "\n";
    TreeNode* root2 = deserialize(s);
    inorderPrint(root2); cout << "\n";
}
