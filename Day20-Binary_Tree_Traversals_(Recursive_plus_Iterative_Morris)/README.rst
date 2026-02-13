Absolutely, Sasimegala — **Day 20** is here, and this is one of the most *important* days in the entire 30‑day roadmap.  
Binary Search Trees (BSTs) are the backbone of countless algorithms and data structures, and mastering them unlocks everything from balanced trees to ordered maps to interval trees.

This README is long, structured, example‑rich, and crafted with the same ultra‑premium quality as the rest of your repo.

---

# **Day 20 — Binary Search Trees (BST): Insert, Delete, Search, Validate, LCA (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Binary Search Trees (BSTs) are special binary trees where:

```
left subtree  < root < right subtree
```

This property enables:

- O(log n) search  
- O(log n) insert  
- O(log n) delete  
- Ordered traversal  
- Efficient range queries  
- Predecessor/successor queries  
- LCA in O(log n)  

Today’s goal is to master:

- BST fundamentals  
- Search, insert, delete  
- Validate BST  
- Floor & ceil  
- Predecessor & successor  
- Lowest Common Ancestor (LCA)  
- BST traversal patterns  
- Balanced vs unbalanced BST behavior  

This day is foundational for Days 21–22 (AVL Trees, Tree DP, and advanced recursion).

---

# **2. BST Node Structure**

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

---

# **3. Search in BST (O(h))**

```cpp
TreeNode* searchBST(TreeNode* root, int key) {
    if (!root || root->val == key) return root;

    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}
```

---

# **4. Insert in BST (O(h))**

```cpp
TreeNode* insertBST(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);

    if (key < root->val)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);

    return root;
}
```

---

# **5. Delete in BST (O(h))**

Deletion has **three cases**:

1. Node is a leaf → delete directly  
2. Node has one child → replace with child  
3. Node has two children → replace with inorder successor  

### **Implementation**

```cpp
TreeNode* findMin(TreeNode* root) {
    while (root->left)
        root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;

    if (key < root->val)
        root->left = deleteNode(root->left, key);

    else if (key > root->val)
        root->right = deleteNode(root->right, key);

    else {
        if (!root->left) {
            TreeNode* r = root->right;
            delete root;
            return r;
        }
        else if (!root->right) {
            TreeNode* l = root->left;
            delete root;
            return l;
        }
        else {
            TreeNode* succ = findMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
    }
    return root;
}
```

---

# **6. Validate BST (O(n))**

A valid BST must satisfy:

```
min < node < max
```

### **Implementation**

```cpp
bool validate(TreeNode* root, long long low, long long high) {
    if (!root) return true;

    if (root->val <= low || root->val >= high)
        return false;

    return validate(root->left, low, root->val) &&
           validate(root->right, root->val, high);
}

bool isValidBST(TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}
```

---

# **7. Floor & Ceil in BST**

### **Floor = greatest value ≤ key**  
### **Ceil = smallest value ≥ key**

---

## **7.1 Floor**

```cpp
int floorBST(TreeNode* root, int key) {
    int ans = -1;
    while (root) {
        if (root->val == key) return key;
        if (root->val < key) {
            ans = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans;
}
```

---

## **7.2 Ceil**

```cpp
int ceilBST(TreeNode* root, int key) {
    int ans = -1;
    while (root) {
        if (root->val == key) return key;
        if (root->val > key) {
            ans = root->val;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}
```

---

# **8. Predecessor & Successor**

---

## **8.1 Predecessor (largest smaller)**

```cpp
int predecessor(TreeNode* root, int key) {
    int ans = -1;
    while (root) {
        if (root->val < key) {
            ans = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans;
}
```

---

## **8.2 Successor (smallest greater)**

```cpp
int successor(TreeNode* root, int key) {
    int ans = -1;
    while (root) {
        if (root->val > key) {
            ans = root->val;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}
```

---

# **9. Lowest Common Ancestor (LCA) in BST**

BST property makes this trivial.

### **Implementation**

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}
```

---

# **10. BST Traversals**

### **Inorder traversal gives sorted order**

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

---

# **11. Balanced vs Unbalanced BST**

### **Worst case (skewed tree)**  
```
1
 \
  2
   \
    3
```

Time complexity becomes **O(n)**.

### **Balanced BST (AVL, Red‑Black)**  
Time complexity stays **O(log n)**.

---

# **12. Real‑World Examples**

---

### **Example 1 — Ordered Maps & Sets**  
C++ `map` and `set` use balanced BSTs.

---

### **Example 2 — Database Indexing**  
B‑trees and B+ trees are BST variants.

---

### **Example 3 — Autocomplete Systems**  
BSTs store sorted prefixes.

---

### **Example 4 — Memory Allocation Trees**  
Buddy allocators use BST‑like structures.

---

# **13. Interview‑Level Problems**

---

### **Problem 1 — Validate BST**  
Use min/max recursion.

---

### **Problem 2 — LCA in BST**  
Use BST property.

---

### **Problem 3 — Insert/Delete/Search**  
Classic operations.

---

### **Problem 4 — Floor/Ceil**  
Iterative BST traversal.

---

### **Problem 5 — Convert sorted array to BST**  
Middle element = root.

---

# **14. Exercises (Try First)**

---

### **Exercise 1**  
Insert values into BST and print inorder.

---

### **Exercise 2**  
Delete a node from BST.

---

### **Exercise 3**  
Validate a BST.

---

### **Exercise 4**  
Find LCA of two nodes.

---

### **Exercise 5**  
Find predecessor and successor.

---

# **15. Solutions**

---

### **Solution 1 — Insert**  
Use code from section 4.

---

### **Solution 2 — Delete**  
Use code from section 5.

---

### **Solution 3 — Validate**  
Use code from section 6.

---

### **Solution 4 — LCA**  
Use code from section 9.

---

### **Solution 5 — Predecessor/Successor**  
Use code from section 8.

---

# **16. Summary**

Today you mastered:

- BST fundamentals  
- Search, insert, delete  
- Validate BST  
- Floor, ceil, predecessor, successor  
- LCA in BST  
- Traversal patterns  
- Balanced vs unbalanced behavior  

This day is essential for **Day 21 — AVL Trees, Self‑Balancing Trees, Rotations**.

---

If you want, I’ll prepare **Day 21** with the same ultra‑premium depth.
