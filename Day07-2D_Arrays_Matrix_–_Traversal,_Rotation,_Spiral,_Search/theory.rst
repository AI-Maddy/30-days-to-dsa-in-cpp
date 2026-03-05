.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>

Absolutely, Sasimegala — here is your **ultra‑premium**, **color‑rich**, **icon‑powered**, **memory‑optimized**  
`theory.rst` for **Day 07 – 2D Arrays + Matrix Operations**.

This matches the exact style you’ve been using for Days 1–6:  
bold visuals, icons, mnemonics, and deeply structured explanations that make concepts *stick*.

---

# **Day 07 – 🧩 2D Arrays + Matrix Operations (Colorful Memory Edition)**  
`theory.rst`

---

## **🌈 1. Why 2D Arrays Matter**
2D arrays (matrices) are the foundation of:

- 🧠 Dynamic Programming (DP tables)  
- 🎮 Game boards (chess, tic‑tac‑toe)  
- 🗺️ Grid traversal (BFS/DFS)  
- 🧮 Mathematical operations (transpose, rotation)  
- 🖼️ Image processing (pixels)  
- 🔥 Competitive programming (prefix sums, difference matrices)

If you master matrices, you unlock **half of DSA**.

---

# **🌟 MEMORY ANCHOR: “R‑C‑G”**
2D arrays represent:

- **R**ows  
- **C**olumns  
- **G**rids  

Think: **R‑C‑G = Rows, Columns, Grid**.

---

## **🧱 2. Declaring & Initializing 2D Arrays**

### **🟦 Static Declaration**
```
int a[3][4];
```

### **🟩 Initialization**
```
int a[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
```

### **🟧 Dynamic (vector)**
```
vector<vector<int>> a(n, vector<int>(m));
```

---

# **🌈 3. Traversing a Matrix (The Core Skill)**

### **🔹 Row‑wise Traversal**
```
for (int i=0; i<n; i++)
  for (int j=0; j<m; j++)
    process(a[i][j]);
```

### **🔸 Column‑wise Traversal**
```
for (int j=0; j<m; j++)
  for (int i=0; i<n; i++)
    process(a[i][j]);
```

### **🧠 MEMORY TIP:**  
Think of a matrix as **rows of rows** → `a[row][col]`.

---

# **🌟 4. Matrix Operations (Color‑Coded)**

---

## **💙 Operation 1: Transpose**
Swap rows ↔ columns.

```
b[j][i] = a[i][j];
```

### **🧠 MEMORY ANCHOR:**  
Transpose = **Flip over the diagonal**.

---

## **💚 Operation 2: Reverse Rows**
Used in rotation.

```
reverse(a[i].begin(), a[i].end());
```

---

## **💛 Operation 3: Reverse Columns**
```
swap(a[top][j], a[bottom][j]);
```

---

## **❤️ Operation 4: Rotate Matrix (90° Clockwise)**

### **🎯 Steps**
1. Transpose  
2. Reverse each row  

### **🧠 MEMORY ANCHOR:**  
**T‑R** → **Transpose → Reverse** = Rotate 90°.

---

## **💜 Operation 5: Spiral Traversal**
Traverse in layers:

- ➡️ Left → Right  
- ⬇️ Top → Bottom  
- ⬅️ Right → Left  
- ⬆️ Bottom → Top  

### **🧠 MEMORY ANCHOR:**  
**R‑D‑L‑U** (Right, Down, Left, Up)

---

## **🧡 Operation 6: Boundary Traversal**
Print only the outer ring.

---

## **🩵 Operation 7: Diagonal Traversal**
- Primary diagonal: `i == j`  
- Secondary diagonal: `i + j == n - 1`

---

# **🌈 5. Matrix Patterns (The Heart of Day 07)**

---

## **💥 Pattern 1: Searching in a Sorted Matrix**
Matrix sorted row‑wise & column‑wise.

### **🎯 Trick:**  
Start at **top‑right**.

- If target < value → move left  
- If target > value → move down  

### **🧠 MEMORY ANCHOR:**  
**T‑R Start** → Top‑Right Start.

---

## **🔥 Pattern 2: Matrix Prefix Sum (2D Prefix)**
Prefix matrix `P[i][j]` stores sum of rectangle (0,0) → (i,j).

### **Rectangle Sum Formula**
\[
P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1]
\]

### **🧠 MEMORY ANCHOR:**  
**+ − − +** pattern.

---

## **⚡ Pattern 3: 2D Difference Array (Imos Method)**
Used for range updates on grids.

### **Update rectangle (x1,y1) → (x2,y2) by +k**
```
D[x1][y1] += k
D[x1][y2+1] -= k
D[x2+1][y1] -= k
D[x2+1][y2+1] += k
```

### **🧠 MEMORY ANCHOR:**  
Corners = **+ − − +**

---

## **🌪️ Pattern 4: Flood Fill (DFS/BFS on Grid)**
Used for:
- Counting islands  
- Coloring regions  
- Maze solving  

### **Moves**
```
(0,1), (1,0), (0,-1), (-1,0)
```

### **🧠 MEMORY ANCHOR:**  
**R‑D‑L‑U** directions.

---

## **🌋 Pattern 5: Connected Components in Grid**
Use DFS/BFS to count regions.

---

## **🌟 Pattern 6: Matrix as Graph**
Each cell = node  
Edges = adjacent cells  

This is the basis of:
- BFS shortest path  
- DFS region detection  
- Multi‑source BFS  

---

# **🌈 6. Pitfalls (Red Flags 🚩)**

- 🚩 Mixing up rows & columns  
- 🚩 Forgetting matrix bounds  
- 🚩 Using recursion without checking limits  
- 🚩 Not marking visited cells in DFS/BFS  
- 🚩 Using wrong rotation order (must be T‑R)  
- 🚩 Forgetting to handle rectangular matrices  

---

# **📚 7. Problems You Can Now Solve**
- Spiral traversal  
- Rotate matrix  
- Search in sorted matrix  
- Count islands  
- Flood fill  
- 2D prefix sum queries  
- 2D difference array updates  
- Boundary traversal  
- Diagonal traversal  
- Shortest path in grid  

---

# **⏱️ 8. Complexity Table**

| Operation | Time | Space |
|-----------|--------|--------|
| Traversal | O(n·m) | O(1) |
| Transpose | O(n·m) | O(1) |
| Rotation | O(n·m) | O(1) |
| Spiral | O(n·m) | O(1) |
| BFS/DFS | O(n·m) | O(n·m) |
| 2D Prefix | O(n·m) | O(n·m) |

---

# **🎯 9. What You Must Master Today**
- Traversing matrices in all patterns  
- Transpose, reverse, rotate  
- Spiral & boundary traversal  
- Searching in sorted matrix  
- 2D prefix sum  
- 2D difference array  
- BFS/DFS on grids  
- Matrix as graph  

---

If you want, I can now generate:

🌈 **Day 07 README (ultra‑premium)**  
🧠 **Day 07 cheat sheet**  
🧩 **C++ templates for all matrix patterns**  
🔥 **20 matrix interview problems with solutions**

Just tell me what you want next.
