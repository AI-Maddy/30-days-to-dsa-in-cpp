.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>

Absolutely, Sasimegala — here comes your **Day 22** theory file, crafted in the same **ultra‑premium**, **color‑rich**, **icon‑powered**, **memory‑optimized** style as all your previous days.

Day 22 is a **core BST mastery day**, covering:

- **Validate BST**  
- **Floor & Ceil in BST**  
- **Kth Smallest Element**  
- **LCA in BST**

These four patterns form the backbone of almost every FAANG BST problem.

---

# **Day 22 – 🌳 Binary Search Tree (BST) Mastery: Validate, Floor/Ceil, Kth Smallest, LCA**  
`theory.rst`

---

# **🌈 1. Why Day 22 Matters**
BSTs are one of the most elegant and powerful data structures.

Today you learn:

- 🧠 How to **validate** a BST  
- 🎯 How to compute **floor** and **ceil**  
- 🏆 How to find **Kth smallest** using inorder  
- 🔗 How to compute **LCA** in BST using BST properties  

These patterns appear in **every major interview**.

---

# **🌟 MEMORY ANCHOR: “V‑F‑K‑L”**
Today’s 4 pillars:

- **V** – Validate BST  
- **F** – Floor & Ceil  
- **K** – Kth Smallest  
- **L** – LCA in BST  

Remember: **V‑F‑K‑L** → Validate, Floor, Kth, LCA.

---

# **🌈 2. Validate BST (The Most Important BST Problem)**

A valid BST satisfies:

```
Left subtree < root < Right subtree
```

---

## **🔥 Approach 1: Min–Max Range (Recursive)**  
The most reliable method.

### **Logic**
- Each node must lie in a valid range  
- Left subtree: (min, root.val)  
- Right subtree: (root.val, max)  

---

## **🧠 MEMORY TIP:**  
**BST = Range shrinking at every step**

---

## **🔥 Approach 2: Inorder Traversal**
Inorder traversal of BST gives **sorted order**.

### **Logic**
- Do inorder  
- Check if array is strictly increasing  

---

## **🧠 MEMORY ANCHOR:**  
**Inorder sorted = valid BST**

---

# **🌈 3. Floor & Ceil in BST**

These two operations are **BST‑specific** and extremely common.

---

# **🌈 3.1 Floor in BST**
**Floor(x)** = largest value ≤ x.

---

## **🔥 Logic**
- If node.val == x → return x  
- If node.val > x → go left  
- If node.val < x → store node.val as candidate → go right  

---

## **🧠 MEMORY TIP:**  
**Floor → go right when small**

---

# **🌈 3.2 Ceil in BST**
**Ceil(x)** = smallest value ≥ x.

---

## **🔥 Logic**
- If node.val == x → return x  
- If node.val < x → go right  
- If node.val > x → store node.val as candidate → go left  

---

## **🧠 MEMORY ANCHOR:**  
**Ceil → go left when big**

---

# **🌈 4. Kth Smallest Element in BST**

BST inorder traversal gives sorted order.

---

## **🔥 Approach 1: Inorder Traversal**
- Do inorder  
- Stop at kth element  

### **Time:** O(n)  
### **Space:** O(h)

---

## **🔥 Approach 2: Iterative Inorder (Stack)**
More efficient and interview‑friendly.

---

## **🧠 MEMORY TIP:**  
**Kth smallest = Kth element in inorder**

---

## **🔥 Approach 3: Augmented BST (Node Count)**
Each node stores:

```
size of left subtree
```

Then:

- If left_size + 1 == k → answer  
- If left_size ≥ k → go left  
- Else → go right with k − left_size − 1  

### **Used in:**  
- Order statistic trees  
- Competitive programming  

---

# **🌈 5. LCA in BST (Lowest Common Ancestor)**

BST property makes LCA extremely easy.

---

## **🎯 Goal**
Find lowest node that is ancestor of both p and q.

---

## **🔥 Logic**
Use BST ordering:

- If both p and q < root → go left  
- If both p and q > root → go right  
- Else → root is LCA  

---

## **🧠 MEMORY ANCHOR:**  
**Split point = LCA**

---

## **🎨 Example**
BST:
```
      6
     / \
    2   8
```
LCA(2,8) = 6  
LCA(2,4) = 2  

---

# **🌈 6. Comparison Table**

| Problem | Key Idea | Technique |
|--------|----------|-----------|
| Validate BST | Range shrinking | Min–max recursion / inorder |
| Floor | Largest ≤ x | Move right when small |
| Ceil | Smallest ≥ x | Move left when big |
| Kth smallest | Inorder sorted | Inorder traversal / stack |
| LCA in BST | Split point | BST property |

---

# **🌈 7. Pitfalls (Red Flags 🚩)**

- 🚩 Using inorder for validation but allowing duplicates  
- 🚩 Forgetting strict inequality in BST  
- 🚩 Not updating candidate in floor/ceil  
- 🚩 Using full inorder array for kth smallest (inefficient)  
- 🚩 Using generic LCA logic instead of BST logic  
- 🚩 Forgetting that BST may be skewed (height = n)  

---

# **🌈 8. Problems You Can Now Solve**

- Validate BST  
- Floor & Ceil  
- Kth smallest  
- Kth largest  
- LCA in BST  
- Insert, search, delete  
- Recover BST  
- Range sum in BST  
- Count nodes in range  
- Predecessor & successor  
- BST iterator  

---

# **🌈 9. What You Must Master Today**

- BST property deeply  
- Range‑based validation  
- Floor & ceil logic  
- Inorder traversal mastery  
- Kth smallest using stack  
- LCA using BST ordering  
- Predecessor/successor intuition  

---

If you want, I can now generate:

🔥 **Day 22 README (ultra‑premium)**  
🧠 **C++ templates for all BST patterns**  
🎯 **20 BST interview problems**  
📘 **BST cheat sheet (colorful, icon‑rich)**

Just tell me what you want next.
