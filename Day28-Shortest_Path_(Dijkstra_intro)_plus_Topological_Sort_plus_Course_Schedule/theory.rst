---

# **Day 28 – 🚀 Shortest Path (Dijkstra Intro) + 🔗 Topological Sort + 🎓 Course Schedule**  
`theory.rst`

---

# **🌈 1. Why Day 28 Matters**
Today’s patterns unlock the **core logic** behind:

- Shortest paths in weighted graphs  
- Dependency resolution  
- Scheduling problems  
- Cycle detection  
- DAG (Directed Acyclic Graph) reasoning  
- BFS/DFS on directed graphs  
- Priority queue–based graph algorithms  

These are **must‑know** for interviews and competitive programming.

---

# **🌟 MEMORY ANCHOR: “D‑T‑C”**
Three pillars of Day 28:

- **D** – Dijkstra  
- **T** – Topological Sort  
- **C** – Course Schedule  

Remember: **D‑T‑C** → Dijkstra, Topo, Course.

---

# **🌈 2. Shortest Path – Dijkstra’s Algorithm (Intro)**  
Dijkstra is the **most important shortest‑path algorithm** for:

- Weighted graphs  
- Non‑negative weights  
- Single‑source shortest path  

---

# **🌈 2.1 When to Use Dijkstra**
Use Dijkstra when:

- Graph is weighted  
- All weights ≥ 0  
- You need shortest path from one source  

---

# **🌈 2.2 Core Intuition**
Dijkstra is a **greedy algorithm**:

- Always pick the **closest unvisited node**  
- Relax its edges  
- Repeat  

---

## **🔥 Data Structures**
- **Priority Queue (Min‑Heap)** → picks smallest distance  
- **Distance array** → stores best known distances  
- **Visited set** (optional)  

---

# **🌈 2.3 Dijkstra Algorithm Steps**

1. Initialize `dist[] = ∞`, except `dist[src] = 0`  
2. Push `(0, src)` into min‑heap  
3. While heap not empty:  
   - Pop node with smallest distance  
   - Relax all neighbors  
   - If new distance < old → update + push into heap  

---

## **🧠 MEMORY ANCHOR:**  
**Pick min → Relax edges → Update heap**

---

# **🌈 2.4 Relaxation (The Heart of Dijkstra)**

For edge `u → v` with weight `w`:

```
if dist[u] + w < dist[v]:
    dist[v] = dist[u] + w
```

---

# **🌈 2.5 Complexity**
Using min‑heap:

\[
O(E \log V)
\]

---

# **🌈 2.6 When Dijkstra Fails**
Dijkstra **cannot** handle:

- Negative weights  
- Negative cycles  

Use **Bellman‑Ford** or **Floyd‑Warshall** instead.

---

# **🌈 3. Topological Sort (Ordering in DAGs)**  
Topological sort gives an ordering of nodes such that:

```
For every edge u → v, u appears before v.
```

Works **only for DAGs** (Directed Acyclic Graphs).

---

# **🌈 3.1 Applications**
- Course scheduling  
- Build systems  
- Dependency resolution  
- Task ordering  
- Compiler pipelines  

---

# **🌈 3.2 Two Ways to Do Topological Sort**

---

## **🔥 Method 1: DFS + Stack**

### **Steps**
1. DFS from each unvisited node  
2. After exploring all neighbors → push node into stack  
3. Reverse stack → topological order  

---

## **🧠 MEMORY TIP:**  
**Postorder DFS → reverse → topo order**

---

---

## **🔥 Method 2: BFS (Kahn’s Algorithm)**  
This is the **most intuitive** method.

### **Steps**
1. Compute indegree of each node  
2. Push all nodes with indegree 0 into queue  
3. Pop → add to topo order  
4. Reduce indegree of neighbors  
5. If neighbor indegree becomes 0 → push  
6. Continue until queue empty  

---

## **🧠 MEMORY ANCHOR:**  
**Indegree 0 → ready to process**

---

# **🌈 3.3 Detecting Cycles Using Topological Sort**

If:

- Using Kahn’s algorithm  
- Topo order size < number of nodes  

Then **cycle exists**.

---

# **🌈 4. Course Schedule (Cycle Detection + Topo Sort)**  
This is the **canonical** topological sort problem.

---

## **🎯 Problem**
Given `numCourses` and `prerequisites[]`, determine if you can finish all courses.

---

## **🔥 Graph Model**
Each course = node  
Each prerequisite `a → b` = edge `b → a` (b must come before a)

---

# **🌈 4.1 Approach 1: BFS (Kahn’s Algorithm)**

### **Steps**
1. Build graph  
2. Compute indegree  
3. Push all indegree‑0 nodes  
4. BFS  
5. Count processed nodes  
6. If count == numCourses → possible  
7. Else → cycle → impossible  

---

## **🧠 MEMORY TIP:**  
**Course Schedule = Kahn’s Algorithm**

---

# **🌈 4.2 Approach 2: DFS Cycle Detection**

### **States**
- 0 = unvisited  
- 1 = visiting  
- 2 = visited  

### **Cycle rule**
If DFS hits a node with state = 1 → cycle.

---

## **🧠 MEMORY ANCHOR:**  
**Back‑edge = cycle**

---

# **🌈 4.3 Course Schedule II (Return Order)**

Use topological sort to return valid ordering.

---

# **🌈 5. Comparison Table**

| Problem | Technique | Key Idea | Data Structure |
|--------|-----------|----------|----------------|
| Dijkstra | Greedy + PQ | Relax edges | Min‑heap |
| Topological Sort | DFS/BFS | Indegree 0 first | Stack/Queue |
| Course Schedule | Cycle detection | DAG check | Indegree array |

---

# **🌈 6. Pitfalls (Red Flags 🚩)**

- 🚩 Using Dijkstra on negative weights  
- 🚩 Forgetting to relax edges  
- 🚩 Not using priority queue for Dijkstra  
- 🚩 Forgetting to compute indegree  
- 🚩 Not detecting cycles in Course Schedule  
- 🚩 Wrong edge direction in prerequisites  
- 🚩 Using DFS topo on cyclic graph (infinite recursion)  

---

# **🌈 7. Problems You Can Now Solve**

### **Shortest Path**
- Dijkstra  
- Shortest path in weighted graph  
- Network delay time  
- Path with minimum effort  

### **Topological Sort**
- Course Schedule I  
- Course Schedule II  
- Alien Dictionary  
- Build order problems  

### **Graph Theory**
- Cycle detection  
- DAG problems  
- Dependency resolution  

---

# **🌈 8. What You Must Master Today**

- Dijkstra’s greedy logic  
- Relaxation  
- Priority queue usage  
- Indegree computation  
- Kahn’s algorithm  
- DFS cycle detection  
- DAG reasoning  
- Course schedule modeling  

---
