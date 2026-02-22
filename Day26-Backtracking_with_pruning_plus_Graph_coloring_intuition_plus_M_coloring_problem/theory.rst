---

# **Day 26 – 🔥 Backtracking with Pruning + Graph Coloring Intuition + M‑Coloring Problem**  
`theory.rst`

---

# **🌈 1. Why Day 26 Matters**
Today you learn the **strategic side** of backtracking:

- How to **prune** recursion trees early  
- How to **model constraints** using graph theory  
- How to solve **NP‑Complete** problems using backtracking  
- How to reason about **coloring**, **conflicts**, and **constraints**  
- How to reduce exponential complexity with **smart pruning**  

This day transforms you from a backtracking implementer into a **backtracking architect**.

---

# **🌟 MEMORY ANCHOR: “P‑C‑M”**
Three pillars of Day 26:

- **P** – Pruning  
- **C** – Coloring intuition  
- **M** – M‑Coloring problem  

Remember: **P‑C‑M** → Prune, Color, M‑Color.

---

# **🌈 2. Backtracking With Pruning (Advanced)**

Backtracking explores a **decision tree**.  
Pruning cuts off branches that **cannot** lead to a valid solution.

---

## **🔥 Why Pruning Is Essential**
Without pruning:

- Time complexity explodes  
- Many branches are useless  
- Recursion depth becomes huge  

With pruning:

- You eliminate invalid states early  
- You reduce search space drastically  
- You solve NP‑hard problems efficiently  

---

# **🌈 2.1 Types of Pruning**

---

## **1️⃣ Constraint Pruning**
Stop recursion when constraints are violated.

Examples:
- N‑Queens: diagonal/column conflict → prune  
- Sudoku: row/col/box conflict → prune  

---

## **2️⃣ Bound Pruning**
Stop when partial solution cannot reach target.

Examples:
- Combination Sum: if sum > target → prune  
- Knapsack: if weight > capacity → prune  

---

## **3️⃣ Duplicate Pruning**
Avoid exploring identical states.

Examples:
- Subsets II: skip duplicates  
- Permutations II: avoid repeated swaps  

---

## **4️⃣ Early Exit Pruning**
Stop recursion as soon as a solution is found.

Examples:
- Word Search: return true immediately  
- M‑Coloring (decision version): stop after first valid coloring  

---

## **🧠 MEMORY ANCHOR:**  
**Pruning = “Stop early when impossible.”**

---

# **🌈 3. Graph Coloring Intuition (The Foundation of M‑Coloring)**

Graph coloring assigns **colors** to vertices such that:

- Adjacent vertices have **different colors**  
- Colors represent **constraints**  

---

## **🎨 Real‑world analogies**
- Scheduling exams (no two adjacent exams share a student)  
- Register allocation in compilers  
- Map coloring  
- Frequency assignment in networks  

---

## **🔥 Key Insight**
Graph coloring is a **constraint satisfaction** problem.

Each vertex has choices:

```
color ∈ {1, 2, …, M}
```

But only if **no neighbor** has that color.

---

## **🧠 MEMORY TIP:**  
**Color = Choice  
Edge = Constraint**

---

# **🌈 4. M‑Coloring Problem (Backtracking + Graph Theory)**

This is a **classic NP‑Complete** problem.

---

## **🎯 Goal**
Given:

- A graph with N vertices  
- M available colors  

Determine if you can color the graph so that:

```
No two adjacent vertices share the same color.
```

---

# **🌈 4.1 Backtracking Strategy**

We color vertices **one by one**.

For vertex `v`:

1. Try each color `c` from 1 to M  
2. Check if assigning `c` is safe  
3. If safe → assign and recurse  
4. If recursion fails → undo and try next color  
5. If no color works → return false  

---

## **🧠 MEMORY ANCHOR:**  
**Try → Check → Assign → Recurse → Undo**

---

# **🌈 4.2 Safety Check**

For vertex `v` and color `c`:

```
For all neighbors u of v:
    if color[u] == c → conflict → not safe
```

---

## **🔥 Pruning Insight**
If a vertex has **degree ≥ M**, coloring may fail early.

---

# **🌈 4.3 Complexity**

Worst case:  
\[
O(M^N)
\]

But pruning reduces it drastically.

---

# **🌈 5. Decision Tree Visualization**

### **Each vertex = a level in recursion**  
### **Each color = a branch**  
### **Invalid color = prune branch**  

This is the same structure as:

- N‑Queens  
- Sudoku  
- Knight’s Tour  
- Hamiltonian Path  
- M‑Coloring  

---

# **🌈 6. Comparison With Other Backtracking Problems**

| Problem | Constraint Type | Pruning Strength |
|--------|------------------|------------------|
| N‑Queens | Diagonal + column | Very strong |
| Sudoku | Row/col/box | Extremely strong |
| Word Search | Character match | Early exit |
| M‑Coloring | Adjacent vertices | Medium |

---

# **🌈 7. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to undo color assignment  
- 🚩 Not checking all neighbors  
- 🚩 Using adjacency matrix incorrectly  
- 🚩 Not pruning early  
- 🚩 Trying colors in random order  
- 🚩 Forgetting that M may be too small  

---

# **🌈 8. Problems You Can Now Solve**

### **Backtracking**
- N‑Queens  
- Sudoku  
- Word Search  
- Rat in a Maze  
- M‑Coloring  
- Knight’s Tour  
- Hamiltonian Path  
- Graph partitioning  
- Constraint satisfaction problems  

### **Graph Theory**
- Bipartite check  
- Greedy coloring  
- Chromatic number approximation  

---

# **🌈 9. What You Must Master Today**

- Backtracking with pruning  
- Graph coloring intuition  
- M‑Coloring recursion  
- Safety checks  
- Constraint propagation  
- Decision tree visualization  
- Efficient pruning strategies  

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Choose BFS for shortest path in unweighted graphs.
- Use visited timing correctly (enqueue-time vs dequeue-time).
- Know adjacency list complexity and memory tradeoffs.
- Detect cycle differently for directed vs undirected graphs.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Revisiting nodes due to late visited marking.
- Mixing 0-based and 1-based graph indexing.
- Forgetting disconnected components loop.
- Using DFS recursion without stack-limit awareness.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: BFS/DFS traversal templates.
- Medium: number of islands, flood fill, course schedule.
- Hard: shortest paths with constraints and topological-DP hybrids.

