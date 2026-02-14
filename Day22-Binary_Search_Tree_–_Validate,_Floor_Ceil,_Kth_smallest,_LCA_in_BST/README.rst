---

# **Day 22 — Tree DP: Path Sums, Zigzag Traversal, Boundary Traversal, Views (Top/Bottom/Left/Right) (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Today’s problems combine:

- BFS  
- DFS  
- Hashing  
- Recursion  
- Tree DP  
- Queue + map patterns  

These are the problems that separate beginners from advanced tree programmers.

You’ll master:

- Zigzag level order  
- Boundary traversal  
- Top view  
- Bottom view  
- Left view  
- Right view  
- Vertical order traversal  
- Path sum problems  
- Root‑to‑leaf path generation  

These patterns appear in system design, compilers, file systems, and graph algorithms.

---

# **2. Zigzag Level Order Traversal**

Level order but alternate direction each level.

### **Implementation**

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;


        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            int idx = leftToRight ? i : sz - i - 1;
If you want, I’ll prepare **Day 23 — Graphs: BFS, DFS, Adjacency List, Cycle Detection (Directed + Undirected)** with the same ultra‑premium depth.

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}
```

---

# **3. Boundary Traversal of Binary Tree**

Boundary =  
1. Left boundary  
2. Leaf nodes  
3. Right boundary (reverse)

---

## **3.1 Left Boundary**

```cpp
void leftBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* cur = root->left;
    while (cur) {
        if (cur->left || cur->right) res.push_back(cur->val);
        cur = cur->left ? cur->left : cur->right;
    }
}
```

---

## **3.2 Leaf Nodes**

```cpp
void leafNodes(TreeNode* root, vector<int>& res) {
    if (!root) return;
    if (!root->left && !root->right) {
        res.push_back(root->val);
        return;
    }
    leafNodes(root->left, res);
    leafNodes(root->right, res);
}
```

---

## **3.3 Right Boundary**

```cpp
void rightBoundary(TreeNode* root, vector<int>& res) {
    vector<int> temp;
    TreeNode* cur = root->right;

    while (cur) {
        if (cur->left || cur->right) temp.push_back(cur->val);
        cur = cur->right ? cur->right : cur->left;
    }

    reverse(temp.begin(), temp.end());
    for (int x : temp) res.push_back(x);
}
```

---

## **3.4 Full Boundary Traversal**

```cpp
vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    res.push_back(root->val);

    leftBoundary(root, res);
    leafNodes(root, res);
    rightBoundary(root, res);

    return res;
}
```

---

# **4. Top View of Binary Tree**

Nodes visible from the top.

Use BFS + horizontal distance (hd).

### **Implementation**

```cpp
vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();

        if (!mp.count(hd))
            mp[hd] = node->val;

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto &p : mp) ans.push_back(p.second);
    return ans;
}
```

---

# **5. Bottom View of Binary Tree**

Same as top view, but overwrite values.

```cpp
vector<int> bottomView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();

        mp[hd] = node->val;

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto &p : mp) ans.push_back(p.second);
    return ans;
}
```

---

# **6. Left View of Binary Tree**

First node at each level.

```cpp
vector<int> leftView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) ans.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}
```

---

# **7. Right View of Binary Tree**

Last node at each level.

```cpp
vector<int> rightView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == sz - 1) ans.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}
```

---

# **8. Vertical Order Traversal**

Group nodes by horizontal distance.

```cpp
vector<vector<int>> verticalOrder(TreeNode* root) {
    map<int, vector<int>> mp;
    queue<pair<TreeNode*,int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();

        mp[hd].push_back(node->val);

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    vector<vector<int>> ans;
    for (auto &p : mp) ans.push_back(p.second);
    return ans;
}
```

---

# **9. Path Sum Problems**

---

## **9.1 Path Sum I — Does a path exist?**

```cpp
bool hasPathSum(TreeNode* root, int target) {
    if (!root) return false;

    if (!root->left && !root->right)
        return target == root->val;

    return hasPathSum(root->left, target - root->val) ||
           hasPathSum(root->right, target - root->val);
}
```

---

## **9.2 Path Sum II — Return all root‑to‑leaf paths**

```cpp
void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& ans) {
    if (!root) return;

    path.push_back(root->val);

    if (!root->left && !root->right && target == root->val)
        ans.push_back(path);

    dfs(root->left, target - root->val, path, ans);
    dfs(root->right, target - root->val, path, ans);

    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(root, target, path, ans);
    return ans;
}
```

---

# **10. Root‑to‑Leaf Paths**

```cpp
void solve(TreeNode* root, vector<int>& path, vector<vector<int>>& ans) {
    if (!root) return;

    path.push_back(root->val);

    if (!root->left && !root->right)
        ans.push_back(path);

    solve(root->left, path, ans);
    solve(root->right, path, ans);

    path.pop_back();
}
```

---

# **11. Real‑World Examples**

---

### **Example 1 — File System Explorer**  
Left/right/top/bottom views mimic directory visualizations.

---

### **Example 2 — Compiler AST Traversal**  
Zigzag and vertical order mimic AST passes.

---

### **Example 3 — Network Routing Trees**  
Path sum = cost constraints.

---

### **Example 4 — UI Layout Trees**  
Top/bottom view logic used in rendering.

---

# **12. Interview‑Level Problems**

---

### **Problem 1 — Zigzag traversal**  
Alternate direction BFS.

---

### **Problem 2 — Boundary traversal**  
Left + leaves + right.

---

### **Problem 3 — Top/Bottom view**  
Horizontal distance mapping.

---

### **Problem 4 — Path sum**  
DFS with backtracking.

---

### **Problem 5 — Vertical order traversal**  
Map + BFS.

---

# **13. Exercises (Try First)**

---

### **Exercise 1**  
Implement zigzag traversal.

---

### **Exercise 2**  
Compute boundary traversal.

---

### **Exercise 3**  
Compute top and bottom view.

---

### **Exercise 4**  
Return all root‑to‑leaf paths.

---

### **Exercise 5**  
Solve Path Sum I & II.

---

# **14. Solutions**

Use the implementations from sections 2–10.

---

# **15. Summary**

Today you mastered:

- Zigzag traversal  
- Boundary traversal  
- Top, bottom, left, right views  
- Vertical order traversal  
- Path sum problems  
- Root‑to‑leaf path generation  
- BFS + DFS + Tree DP patterns  

This day is a major milestone — you now understand the full breadth of binary tree traversal patterns used in interviews.

---
