/*
 * Exercise 7: Maximum Path Sum in Binary Tree
 */
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int maxSum = INT_MIN;
    
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
    
private:
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int leftSum = max(0, dfs(node->left));
        int rightSum = max(0, dfs(node->right));
        
        maxSum = max(maxSum, leftSum + node->val + rightSum);
        
        return node->val + max(leftSum, rightSum);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution sol;
    cout << "Max path sum: " << sol.maxPathSum(root) << endl;
    
    return 0;
}
