---

# **Day 27 – 🌐 Graph Traversals (BFS/DFS) + 🎨 Flood Fill + 🍊 Rotten Oranges + 🏝️ Number of Islands**  
`theory.rst`

---

# **🌈 1. Why Day 27 Matters**
Today’s patterns unlock the **core traversal logic** behind:

- Connected components  
- Grid exploration  
- Multi‑source BFS  
- Shortest path in unweighted graphs  
- Region filling  
- Infection spread  
- Counting islands  
- Graph modeling of matrices  

These four problems form the **foundation** of all grid‑based graph problems.

---

# **🌟 MEMORY ANCHOR: “T‑F‑R‑I”**
Four pillars of Day 27:

- **T** – Traversals (BFS/DFS)  
- **F** – Flood Fill  
- **R** – Rotten Oranges  
- **I** – Islands  

Remember: **T‑F‑R‑I** → Traversal, Fill, Rot, Islands.

---

# **🌈 2. Graph Traversals (BFS + DFS)**

Graphs can be represented as:

- Adjacency list  
- Adjacency matrix  
- Edge list  

Traversal explores all reachable nodes.

---

# **🌈 2.1 DFS (Depth‑First Search)**

DFS explores **as deep as possible** before backtracking.

---

## **🔥 Recursive DFS Template**
```
dfs(node):
    mark node visited
    for neighbor in adj[node]:
        if not visited:
            dfs(neighbor)
```

---

## **🧠 MEMORY TIP:**  
**DFS = Stack (implicit recursion stack)**

---

## **Use cases**
- Connected components  
- Cycle detection  
- Topological sort  
- Flood fill  
- Number of islands  

---

# **🌈 2.2 BFS (Breadth‑First Search)**

BFS explores **level by level**.

---

## **🔥 BFS Template**
```
queue.push(start)
visited[start] = true

while queue not empty:
    node = queue.pop()
    for neighbor in adj[node]:
        if not visited:
            visited = true
            queue.push(neighbor)
```

---

## **🧠 MEMORY ANCHOR:**  
**BFS = Queue = Shortest Path in Unweighted Graphs**

---

## **Use cases**
- Shortest path  
- Multi‑source BFS  
- Rotten oranges  
- Level order traversal  

---

# **🌈 3. Flood Fill (Matrix DFS/BFS)**  
This is the **grid version** of DFS/BFS.

---

## **🎯 Goal**
Given a starting cell, fill all connected cells of the same color with a new color.

---

## **🔥 Key Insight**
Use DFS/BFS in **4 directions**:

- Up  
- Down  
- Left  
- Right  

---

## **🔥 DFS Flood Fill Template**
```
dfs(r, c):
    if out of bounds or color mismatch:
        return
    color cell
    dfs(r+1, c)
    dfs(r-1, c)
    dfs(r, c+1)
    dfs(r, c-1)
```

---

## **🧠 MEMORY TIP:**  
**Flood Fill = DFS/BFS on grid with color check**

---

# **🌈 4. Rotten Oranges (Multi‑Source BFS)**  
This is a **classic BFS wave propagation** problem.

---

## **🎯 Goal**
Given a grid:

- 0 = empty  
- 1 = fresh orange  
- 2 = rotten orange  

Each minute, rotten oranges infect adjacent fresh ones.

Find time to rot all oranges.

---

## **🔥 Key Insight**
Use **multi‑source BFS**:

- Push all rotten oranges into queue initially  
- BFS spreads rot level by level  
- Count minutes as BFS layers  

---

## **🔥 Steps**
1. Push all rotten oranges into queue  
2. Count fresh oranges  
3. BFS: for each minute, rot neighbors  
4. If fresh becomes 0 → return minutes  
5. Else → return -1  

---

## **🧠 MEMORY ANCHOR:**  
**Rot spreads in waves → BFS layers = minutes**

---

# **🌈 5. Number of Islands (DFS/BFS on Grid)**  
One of the most important grid problems.

---

## **🎯 Goal**
Count connected components of `'1'` (land) in a grid of `'0'` and `'1'`.

---

## **🔥 Key Insight**
Each island = one DFS/BFS traversal.

---

## **🔥 Steps**
1. Loop through grid  
2. When you find `'1'`, increment island count  
3. Run DFS/BFS to mark entire island as visited  
4. Continue scanning  

---

## **🧠 MEMORY TIP:**  
**Island = connected component of land**

---

## **Directions**
Use 4‑direction or 8‑direction depending on problem.

---

# **🌈 6. Comparison Table**

| Problem | Technique | Key Idea | Data Structure |
|--------|-----------|----------|----------------|
| BFS | Queue | Level‑wise traversal | Queue |
| DFS | Recursion | Deep exploration | Stack |
| Flood Fill | DFS/BFS | Color region fill | Stack/Queue |
| Rotten Oranges | Multi‑source BFS | Wave propagation | Queue |
| Number of Islands | DFS/BFS | Connected components | Stack/Queue |

---

# **🌈 7. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting visited matrix  
- 🚩 Infinite loops due to missing visited check  
- 🚩 Not checking boundaries  
- 🚩 Using DFS for huge grids (stack overflow risk)  
- 🚩 Forgetting to push all rotten oranges initially  
- 🚩 Counting minutes incorrectly in Rotten Oranges  
- 🚩 Not marking visited in Number of Islands  

---

# **🌈 8. Problems You Can Now Solve**

### **Graph Traversal**
- BFS  
- DFS  
- Connected components  
- Shortest path in unweighted graph  

### **Grid Problems**
- Flood Fill  
- Rotten Oranges  
- Number of Islands  
- Surrounded Regions  
- Walls and Gates  
- Pacific Atlantic Water Flow  
- Pathfinding problems  

---

# **🌈 9. What You Must Master Today**

- BFS queue logic  
- DFS recursion  
- Grid traversal patterns  
- Multi‑source BFS  
- Connected components  
- Boundary checks  
- Visited matrix logic  
- BFS layer counting  

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

