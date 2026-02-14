---

# **Day 20 – 🌳 Binary Tree Traversals (Recursive + Iterative + Morris Traversal)**  
`theory.rst`

---

# **🌈 1. Why Day 20 Matters**
Tree traversals are the **foundation** for:

- Building trees  
- Searching trees  
- Serializing/deserializing  
- Solving tree DP  
- Computing height, diameter, views  
- BST operations  
- Advanced tree problems  

Today you master **all three traversal paradigms**:

- 🔁 Recursive  
- 🧱 Iterative (Stack)  
- 🌿 Morris (Threaded, O(1) space)

---

# **🌟 MEMORY ANCHOR: “R‑I‑M”**
Three traversal worlds:

- **R** – Recursive  
- **I** – Iterative  
- **M** – Morris  

Remember: **R‑I‑M** → the complete traversal toolkit.

---

# **🌈 2. Traversal Types (The Holy Trinity)**

Every binary tree traversal is one of:

- **Preorder** → Root, Left, Right  
- **Inorder** → Left, Root, Right  
- **Postorder** → Left, Right, Root  

### **🧠 MEMORY TIP:**  
**P‑I‑P** → Pre, In, Post  
Order of “Root” position defines traversal.

---

# **🌈 3. Recursive Traversals (The Classic)**

Recursive traversal is the simplest and most intuitive.

---

## **💙 3.1 Preorder (Root → Left → Right)**

### **Use cases**
- Copying tree  
- Serializing tree  
- Building prefix expressions  

---

## **💚 3.2 Inorder (Left → Root → Right)**

### **Use cases**
- BST traversal gives **sorted order**  
- Recovering BST  
- Validating BST  

---

## **💛 3.3 Postorder (Left → Right → Root)**

### **Use cases**
- Delete tree  
- Evaluate expression tree  
- Compute height, diameter  

---

# **🌈 4. Iterative Traversals (Using Stack)**

Recursive calls use an implicit stack.  
Iterative traversal uses an **explicit stack**.

---

# **🌈 4.1 Iterative Preorder**

### **🔥 Logic**
1. Push root  
2. Pop → process  
3. Push right  
4. Push left  

### **🧠 MEMORY TIP:**  
Push **right first**, so left is processed first.

---

# **🌈 4.2 Iterative Inorder**

### **🔥 Logic**
1. Go left as far as possible  
2. Pop → process  
3. Go right  

### **🧠 MEMORY ANCHOR:**  
**Left chain → process → right**

---

# **🌈 4.3 Iterative Postorder (Two Stacks)**

### **🔥 Logic**
1. First stack: root, left, right  
2. Second stack: reverse order  

### **🧠 MEMORY TIP:**  
Postorder = reverse of modified preorder.

---

# **🌈 4.4 Iterative Postorder (One Stack)**  
More complex but elegant.

### **🔥 Logic**
- Track last visited node  
- Peek stack top  
- Decide whether to go left, right, or process  

---

# **🌈 5. Morris Traversal (O(1) Space)**  
This is the **star of Day 20**.

Morris traversal uses **threaded binary trees**:

- Temporarily modifies tree  
- Creates “threads” to predecessor  
- Removes threads after use  
- Achieves **O(1) space**  
- Still **O(n) time**

---

# **🌈 5.1 Morris Inorder Traversal**

### **🎯 Goal**
Inorder traversal without stack or recursion.

---

## **🔥 Logic**
For each node:

1. If no left child → visit node → go right  
2. Else find inorder predecessor  
3. If predecessor’s right is null → create thread → go left  
4. Else → remove thread → visit node → go right  

---

## **🧠 MEMORY ANCHOR:**  
**Thread left subtree → return via thread**

---

# **🌈 5.2 Morris Preorder Traversal**

### **🔥 Logic**
Similar to inorder but visit node **before** threading.

---

## **🧠 MEMORY TIP:**  
Preorder = visit on first encounter  
Inorder = visit on second encounter

---

# **🌈 5.3 Why Morris Traversal Is Important**

- O(1) space  
- No recursion  
- No stack  
- Perfect for memory‑constrained systems  
- Used in interview problems involving:  
  - BST recovery  
  - Tree flattening  
  - Inorder predecessor/successor  

---

# **🌈 6. Traversal Comparison Table**

| Traversal | Space | Time | Notes |
|----------|--------|--------|--------|
| Recursive | O(h) | O(n) | Simple, elegant |
| Iterative | O(h) | O(n) | Explicit stack |
| Morris | O(1) | O(n) | Modifies tree temporarily |

---

# **🌈 7. Applications of Traversals**

### **Preorder**
- Serialize tree  
- Clone tree  
- Expression tree prefix  

### **Inorder**
- BST sorted order  
- Validate BST  
- Recover BST  

### **Postorder**
- Delete tree  
- Expression evaluation  
- Compute height, diameter  

### **Morris**
- Memory‑efficient traversal  
- Inorder predecessor logic  
- Flatten BST  

---

# **🌈 8. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to remove Morris threads  
- 🚩 Infinite loops due to wrong predecessor logic  
- 🚩 Pushing children in wrong order in iterative preorder  
- 🚩 Not handling null root  
- 🚩 Using recursion for very deep trees (stack overflow)  
- 🚩 Incorrect lastVisited logic in iterative postorder  

---

# **🌈 9. Problems You Can Now Solve**

- Preorder / Inorder / Postorder  
- Iterative traversals  
- Morris inorder & preorder  
- BST validation  
- BST recovery  
- Tree serialization  
- Tree flattening  
- Height, diameter, balance  
- Expression tree evaluation  
- Boundary traversal  
- Zigzag traversal  

---

# **🌈 10. What You Must Master Today**

- Recursive traversal patterns  
- Iterative traversal patterns  
- Morris traversal (inorder + preorder)  
- Predecessor logic  
- Thread creation/removal  
- Stack‑based traversal control  
- Traversal applications  

---
