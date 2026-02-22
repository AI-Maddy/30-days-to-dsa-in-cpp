---

# **Day 23 – 🌳 Construct Tree from Traversals + 🔄 Serialize/Deserialize + 🌿 Morris Traversal Deep Dive**  
`theory.rst`

---

# **🌈 1. Why Day 23 Matters**
Today’s patterns unlock the **structural understanding** of binary trees:

- 🧱 How to **rebuild** a tree from traversal sequences  
- 🔄 How to **serialize/deserialize** trees for storage or transmission  
- 🌿 How Morris traversal achieves **O(1) space**  
- 🧠 How traversal orders encode tree structure  
- 🧩 How to use recursion + indices + hash maps efficiently  

This is one of the most **conceptually deep** days in the entire 30‑day curriculum.

---

# **🌟 MEMORY ANCHOR: “C‑S‑M”**
Three pillars of Day 23:

- **C** – Construct Tree  
- **S** – Serialize/Deserialize  
- **M** – Morris Traversal Deep Dive  

Remember: **C‑S‑M** → Construct, Serialize, Morris.

---

# **🌈 2. Construct Binary Tree from Traversals**

This is one of the most important FAANG topics.

You will learn:

- Preorder + Inorder → Build Tree  
- Postorder + Inorder → Build Tree  
- Why Pre+Post cannot uniquely build a binary tree (unless full binary tree)  

---

# **🌈 2.1 Preorder + Inorder → Construct Tree**

---

## **🎯 Key Observations**
- Preorder: **Root first**  
- Inorder: **Root in the middle**  

---

## **🔥 Steps**
1. Preorder[preIndex] = root  
2. Find root in inorder using a hash map  
3. Left subtree = inorder left segment  
4. Right subtree = inorder right segment  
5. Recursively build  

---

## **🧠 MEMORY ANCHOR:**  
**Preorder gives root → Inorder splits tree**

---

# **🌈 2.2 Postorder + Inorder → Construct Tree**

---

## **🎯 Key Observations**
- Postorder: **Root last**  
- Inorder: **Root in the middle**  

---

## **🔥 Steps**
1. Postorder[postIndex] = root  
2. Find root in inorder  
3. Build **right subtree first**  
4. Then build left subtree  

---

## **🧠 MEMORY TIP:**  
**Postorder builds Right → Left (reverse)**

---

# **🌈 2.3 Preorder + Postorder → Construct Tree (Full Binary Tree Only)**

---

## **🎯 Why not unique?**
Pre + Post does **not** uniquely define a binary tree unless it is **full** (each node has 0 or 2 children).

---

## **🔥 Logic**
- Preorder gives root  
- Next preorder element = left child  
- Find left subtree size in postorder  
- Recursively build  

---

# **🌈 3. Serialize + Deserialize Binary Tree**

This is a **must‑know** FAANG problem.

Serialization = convert tree → string  
Deserialization = convert string → tree  

---

# **🌈 3.1 BFS (Level Order) Serialization**

---

## **🔥 Serialize**
Use queue:

- Append value or `"null"`  
- Level order traversal  

---

## **🔥 Deserialize**
Use queue:

- First value = root  
- For each node:  
  - Read next two values → left, right  

---

## **🧠 MEMORY ANCHOR:**  
**Queue = Level Order = BFS Serialization**

---

# **🌈 3.2 DFS (Preorder) Serialization**

---

## **🔥 Serialize**
```
root, left, right
```
Use `"null"` markers.

---

## **🔥 Deserialize**
Use recursion:

- Read next token  
- If `"null"` → return null  
- Else create node → build left → build right  

---

## **🧠 MEMORY TIP:**  
**Preorder + null markers = perfect reconstruction**

---

# **🌈 3.3 Comparison Table**

| Method | Pros | Cons |
|--------|------|------|
| BFS | Easy to visualize | Longer string |
| Preorder DFS | Compact | Requires recursion |
| Postorder DFS | Also works | Less intuitive |
| Inorder DFS | ❌ Cannot uniquely reconstruct | Not used |

---

# **🌈 4. Morris Traversal (Deep Dive)**  
You learned Morris traversal earlier — today we go **deep**.

---

# **🌈 4.1 Why Morris Traversal Works**

Morris traversal uses **threaded binary trees**:

- Each node’s predecessor temporarily points to the node  
- This creates a path back without stack/recursion  
- After visiting, the thread is removed  

---

## **🧠 MEMORY ANCHOR:**  
**Thread → Visit → Remove**

---

# **🌈 4.2 Morris Inorder Traversal (Deep)**

---

## **🔥 Steps**
1. If no left child → visit → go right  
2. Else find predecessor  
3. If predecessor.right is null → create thread → go left  
4. Else → remove thread → visit → go right  

---

## **Why it works**
Because inorder predecessor is the **last node** in left subtree.

---

# **🌈 4.3 Morris Preorder Traversal (Deep)**

---

## **🔥 Steps**
1. If no left child → visit → go right  
2. Else find predecessor  
3. If predecessor.right is null →  
   - **Visit now**  
   - Create thread → go left  
4. Else → remove thread → go right  

---

## **Why it works**
Preorder visits root **before** exploring left subtree.

---

# **🌈 4.4 Morris Postorder Traversal (Advanced)**

Rare but possible using:

- Dummy root  
- Reverse right edges  
- Visit reversed path  

---

# **🌈 5. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to remove Morris threads  
- 🚩 Searching inorder index in O(n) (use hash map)  
- 🚩 Building wrong subtree first in postorder+inorder  
- 🚩 Using inorder serialization (not reversible)  
- 🚩 Forgetting null markers in DFS serialization  
- 🚩 Infinite loops in Morris traversal  

---

# **🌈 6. Problems You Can Now Solve**

### **Tree Construction**
- Pre + In → build  
- Post + In → build  
- Pre + Post → build (full tree)  

### **Serialization**
- BFS serialize/deserialize  
- DFS serialize/deserialize  

### **Morris**
- Morris inorder  
- Morris preorder  
- Morris postorder (advanced)  

---

# **🌈 7. What You Must Master Today**

- Traversal order logic  
- Hash map for inorder indices  
- Preorder vs postorder reconstruction  
- BFS vs DFS serialization  
- Morris threading logic  
- Predecessor computation  
- Thread creation/removal  

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Differentiate preorder/inorder/postorder use-cases.
- Use level-order when distance/width is asked.
- In BST, exploit ordering before brute force.
- Reconstruct tree only when traversal pair is sufficient.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Not checking null before child access.
- Confusing node-level and subtree-level recursion state.
- Using global vars where return struct/pair is cleaner.
- Forgetting base cases in serialization/deserialization.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: depth, traversals.
- Medium: LCA, zigzag, boundary traversal.
- Hard: serialize/deserialize, construct from traversals, Morris tweaks.

