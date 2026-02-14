---

# **Day 19 — Binary Trees: Traversals, Height, Diameter, Balanced Trees (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Binary Trees are the backbone of:

- Binary Search Trees (BST)  
- Heaps  
- Segment Trees  
- Fenwick Trees  
- Tries  
- Expression Trees  
- AVL / Red‑Black Trees  
- Graph traversal intuition  

Today’s goal is to master:

- Tree representation  
- DFS traversals (preorder, inorder, postorder)  
- BFS traversal (level order)  
- Height & depth  
- Diameter of a tree  
- Balanced tree check  
- Maximum path sum  
- Mirror tree  
- Count nodes, leaves, internal nodes  

This day is foundational for Days 20–22 (BST, advanced tree DP, and recursion mastery).

---

# **2. Tree Node Structure**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

---

# **3. Depth‑First Traversals (DFS)**

DFS has three classic variants.

---

## **3.1 Preorder Traversal (Root → Left → Right)**

```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
```

Used in:

- Copying a tree  
- Serializing a tree  

---

## **3.2 Inorder Traversal (Left → Root → Right)**

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

Used in:

- BST → sorted order  

---

## **3.3 Postorder Traversal (Left → Right → Root)**

```cpp
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

Used in:

- Deleting a tree  
- Expression tree evaluation  

---

# **4. Breadth‑First Traversal (BFS / Level Order)**

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;

        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}
```

---

# **5. Height of a Binary Tree**

Height = longest path from root to leaf.

```cpp
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

---

# **6. Diameter of a Binary Tree (Longest Path)**

Diameter = longest path between any two nodes.

### **6.1 Naive — O(n²)**  
Compute height for every node.

---

### **6.2 Optimal — O(n)**

Compute height and diameter in one recursion.

```cpp
int diameter(TreeNode* root, int &ans) {
    if (!root) return 0;

    int lh = diameter(root->left, ans);
    int rh = diameter(root->right, ans);

    ans = max(ans, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    diameter(root, ans);
    return ans;
}
```

---

# **7. Balanced Binary Tree Check**

A tree is height‑balanced if:

```
|height(left) - height(right)| ≤ 1
```

### **Optimal — O(n)**

```cpp
int check(TreeNode* root) {
    if (!root) return 0;

    int lh = check(root->left);
    if (lh == -1) return -1;

    int rh = check(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root) {
    return check(root) != -1;
}
```

---

# **8. Maximum Path Sum (Hard)**

Path can start and end anywhere.

```cpp
int solve(TreeNode* root, int &ans) {
    if (!root) return 0;

    int left = max(0, solve(root->left, ans));
    int right = max(0, solve(root->right, ans));

    ans = max(ans, left + right + root->val);

    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}
```

---

# **9. Mirror of a Binary Tree**

```cpp
TreeNode* mirror(TreeNode* root) {
    if (!root) return root;

    swap(root->left, root->right);

    mirror(root->left);
    mirror(root->right);

    return root;
}
```

---

# **10. Count Nodes, Leaves, Internal Nodes**

### **Count Nodes**

```cpp
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```

### **Count Leaves**

```cpp
int countLeaves(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}
```

### **Count Internal Nodes**

```cpp
int countInternal(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + countInternal(root->left) + countInternal(root->right);
}
```

---

# **11. Real‑World Examples**

---

### **Example 1 — File System Trees**  
Folders = internal nodes  
Files = leaves  

---

### **Example 2 — Expression Trees**  
Postorder = evaluation  
Inorder = infix expression  

---

### **Example 3 — Network Routing Trees**  
Height = worst‑case hop count  

---

### **Example 4 — Game Trees**  
DFS = minimax  
BFS = shortest path  

---

# **12. Interview‑Level Problems**

---

### **Problem 1 — Height of tree**  
Classic recursion.

---

### **Problem 2 — Diameter of tree**  
Height + diameter in one pass.

---

### **Problem 3 — Balanced tree**  
Return height or -1.

---

### **Problem 4 — Maximum path sum**  
DP on trees.

---

### **Problem 5 — Level order traversal**  
Queue BFS.

---

# **13. Exercises (Try First)**

---

### **Exercise 1**  
Implement preorder, inorder, postorder.

---

### **Exercise 2**  
Compute height of a tree.

---

### **Exercise 3**  
Check if a tree is balanced.

---

### **Exercise 4**  
Compute diameter of a tree.

---

### **Exercise 5**  
Compute maximum path sum.

---

# **14. Solutions**

---

### **Solution 1 — Traversals**  
Use DFS code from section 3.

---

### **Solution 2 — Height**  
Use code from section 5.

---

### **Solution 3 — Balanced**  
Use code from section 7.

---

### **Solution 4 — Diameter**  
Use code from section 6.

---

### **Solution 5 — Max path sum**  
Use code from section 8.

---

# **15. Summary**

Today you mastered:

- DFS and BFS tree traversals  
- Height, depth, diameter  
- Balanced tree check  
- Maximum path sum  
- Mirror tree  
- Counting nodes, leaves, internal nodes  
- Real‑world tree applications  

This day is the foundation for **Day 20 — Binary Search Trees (BST): Insert, Delete, Search, Validate, LCA**.

---
