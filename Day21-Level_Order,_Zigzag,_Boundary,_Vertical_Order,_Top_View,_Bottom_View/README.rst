---

# **Day 21 — AVL Trees: Self‑Balancing BST + Rotations + Insert/Delete (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

A Binary Search Tree (BST) becomes inefficient when it gets skewed:

```
1
 \
  2
   \
    3
```

Height becomes **O(n)** → operations degrade to **O(n)**.

**AVL Trees** fix this by maintaining strict balance:

```
|height(left) - height(right)| ≤ 1
```

This ensures:

- Search → O(log n)  
- Insert → O(log n)  
- Delete → O(log n)  
- Height always ≈ log₂(n)  

Today’s goal is to master:

- AVL tree properties  
- Node height & balance factor  
- Rotations (LL, RR, LR, RL)  
- Insert with rebalancing  
- Delete with rebalancing  
- Real interview patterns  

This day is essential for understanding Red‑Black Trees, Treaps, and Segment Trees later.

---

# **2. AVL Node Structure**

```cpp
struct Node {
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int x) : val(x), left(NULL), right(NULL), height(1) {}
};
```

---

# **3. Height & Balance Factor**

### **Height**

```cpp
int height(Node* root) {
    return root ? root->height : 0;
}
```

### **Balance Factor**

```
balance = height(left) - height(right)
```

```cpp
int getBalance(Node* root) {
    return root ? height(root->left) - height(root->right) : 0;
}
```

---

# **4. Rotations — The Heart of AVL Trees**

There are **four** rotations:

- **LL Rotation** (Right rotation)  
- **RR Rotation** (Left rotation)  
- **LR Rotation** (Left‑Right rotation)  
- **RL Rotation** (Right‑Left rotation)  

---

## **4.1 Right Rotation (LL Case)**

```
    y
   /
  x
   \
    T2
```

Becomes:

```
    x
     \
      y
```

### **Implementation**

```cpp
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}
```

---

## **4.2 Left Rotation (RR Case)**

```
  x
   \
    y
   /
  T2
```

Becomes:

```
    y
   /
  x
```

### **Implementation**

```cpp
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}
```

---

# **5. Insert in AVL Tree (with Rebalancing)**

### **Steps**

1. Insert like normal BST  
2. Update height  
3. Compute balance factor  
4. Apply rotation if needed  

---

## **5.1 Implementation**

```cpp
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->val)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->val)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
```

---

# **6. Delete in AVL Tree (with Rebalancing)**

Deletion is:

1. Delete like BST  
2. Update height  
3. Rebalance using rotations  

---

## **6.1 Implementation**

```cpp
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* succ = root->right;
            while (succ->left) succ = succ->left;
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
    }

    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
        return leftRotate(root);


    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
```

---

# **7. Why AVL Trees Matter**

- Guaranteed **O(log n)** operations  
- Perfect for ordered data  
- Used in:
  - Databases  
  - Compilers  
  - Memory allocators  
  - Ordered maps/sets  
  - Indexing systems  

---

# **8. Real‑World Examples**

---

### **Example 1 — C++ `map` and `set`**  
Implemented using Red‑Black Trees (a cousin of AVL).

---

### **Example 2 — Database Indexing**  
AVL‑like balancing ensures fast lookups.

---

### **Example 3 — Memory Allocation Trees**  
Balanced trees track free blocks.

---

### **Example 4 — Event Scheduling Systems**  
Balanced BSTs maintain sorted events.

---

# **9. Interview‑Level Problems**

---

### **Problem 1 — Insert into AVL Tree**  
Rotation logic.

---

### **Problem 2 — Delete from AVL Tree**  
Complex but essential.

---

### **Problem 3 — Validate AVL Tree**  
Check height balance.

---

### **Problem 4 — Predecessor/Successor in AVL**  
Same as BST.

---

### **Problem 5 — Build AVL from sorted array**  
Middle element = root.

---

# **10. Exercises (Try First)**

---

### **Exercise 1**  
Insert values into AVL and print inorder.

---

### **Exercise 2**  
Delete values from AVL and print inorder.

---

### **Exercise 3**  
Check if a tree is AVL‑balanced.

---

### **Exercise 4**  
Implement LL, RR, LR, RL rotations.

---

### **Exercise 5**  
Build AVL from sorted array.

---

# **11. Solutions**

---

### **Solution 1 — Insert**  
Use code from section 5.

---

### **Solution 2 — Delete**  
Use code from section 6.

---

### **Solution 3 — Validate AVL**  
Check height difference ≤ 1.

---

### **Solution 4 — Rotations**  
Use section 4.

---

### **Solution 5 — Build from sorted array**

```cpp
Node* buildAVL(vector<int>& a, int l, int r) {
    if (l > r) return NULL;

    int mid = (l + r) / 2;
    Node* root = new Node(a[mid]);

    root->left = buildAVL(a, l, mid - 1);
    root->right = buildAVL(a, mid + 1, r);

    root->height = 1 + max(height(root->left), height(root->right));
    return root;
}
```

---

# **12. Summary**

Today you mastered:

- AVL tree fundamentals  
- Height & balance factor  
- LL, RR, LR, RL rotations  
- Insert with rebalancing  
- Delete with rebalancing  
- Balanced tree guarantees  
- Real‑world applications  

This day is essential for **Day 22 — Tree DP: Path Sums, Zigzag Traversal, Boundary Traversal, Views (Top/Bottom/Left/Right)**.

---
