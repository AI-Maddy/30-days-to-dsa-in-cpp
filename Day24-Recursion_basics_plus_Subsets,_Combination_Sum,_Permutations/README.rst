---

# **Day 24 — Topological Sort: Kahn’s Algorithm (BFS), DFS Ordering, Cycle Detection in DAGs (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Topological sorting is defined only for **Directed Acyclic Graphs (DAGs)**.

A topological order is:

```
For every directed edge u → v, u appears before v in the ordering.
```

Used in:

- Build systems (Make, Bazel)  
- Course scheduling  
- Dependency resolution  
- Task scheduling  
- Compilers (instruction ordering)  
- Package managers (npm, pip)  

Today you will master:

- Topological sort using DFS  
- Topological sort using BFS (Kahn’s Algorithm)  
- Cycle detection in directed graphs  
- Checking if a graph is a DAG  
- Applications of topological ordering  

---

# **2. Graph Representation (Adjacency List)**

```cpp
vector<vector<int>> adj(n);
adj[u].push_back(v); // directed edge u → v
```

---

# **3. Topological Sort Using DFS (Postorder)**

### **Logic**

1. Perform DFS  
2. After exploring all neighbors, push node into stack  
3. Reverse the stack  

### **Implementation**

```cpp
void dfsTopo(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for (int nei : adj[node]) {
        if (!vis[nei])
            dfsTopo(nei, adj, vis, st);
    }

    st.push(node);
}

vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfsTopo(i, adj, vis, st);
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
```

Time: **O(V + E)**  
Space: **O(V)**

---

# **4. Topological Sort Using BFS (Kahn’s Algorithm)**

This is the most famous and widely used method.

### **Logic**

1. Compute indegree of each node  
2. Push all nodes with indegree 0 into queue  
3. Pop from queue, add to result  
4. Reduce indegree of neighbors  
5. If neighbor becomes 0, push into queue  

### **Implementation**

```cpp
vector<int> topoSortKahn(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);

    for (int i = 0; i < n; i++)
        for (int nei : adj[i])
            indeg[nei]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        ans.push_back(node);

        for (int nei : adj[node]) {
            indeg[nei]--;
            if (indeg[nei] == 0)
                q.push(nei);
        }
    }

    return ans;
}
```

---

# **5. Detect Cycle in Directed Graph Using Kahn’s Algorithm**

If graph has a cycle, topological ordering is impossible.

### **Logic**

- If topological sort does NOT include all nodes → cycle exists.

### **Implementation**

```cpp
bool hasCycleKahn(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);

    for (int i = 0; i < n; i++)
        for (int nei : adj[i])
            indeg[nei]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    int count = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;

        for (int nei : adj[node]) {
            indeg[nei]--;
            if (indeg[nei] == 0)
                q.push(nei);
        }
    }

    return count != n; // cycle if not all nodes processed
}
```

---

# **6. Detect Cycle in Directed Graph Using DFS**

Use recursion stack.

```cpp
bool dfsCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (int nei : adj[node]) {
        if (!vis[nei]) {
            if (dfsCycle(nei, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[nei])
            return true;
    }

    pathVis[node] = 0;
    return false;
}

bool hasCycleDFS(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0), pathVis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfsCycle(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}
```

---

# **7. Applications of Topological Sort**

### **1. Course Scheduling**
Prerequisites form a DAG.

### **2. Build Systems**
Make, Bazel, Gradle use topological ordering.

### **3. Dependency Resolution**
Package managers (npm, pip, apt).

### **4. Task Scheduling**
Tasks with dependencies.

### **5. Compiler Optimization**
Instruction scheduling.

---

# **8. Real‑World Examples**

### **Example 1 — University Course Planner**
Edges represent prerequisites.

### **Example 2 — Software Build Graph**
Compile A before B.

### **Example 3 — Task Scheduling in OS**
Dependencies between tasks.

### **Example 4 — Data Pipelines**
ETL jobs with dependencies.

---

# **9. Interview‑Level Problems**

### **Problem 1 — Topological Sort (DFS)**  
Classic.

### **Problem 2 — Topological Sort (Kahn)**  
Most common.

### **Problem 3 — Course Schedule I**  
Detect cycle.

### **Problem 4 — Course Schedule II**  
Return topological order.

### **Problem 5 — Alien Dictionary**  
Topological sort on characters.

---

# **10. Exercises (Try First)**

### **Exercise 1**  
Implement topological sort using DFS.

### **Exercise 2**  
Implement topological sort using Kahn’s algorithm.

### **Exercise 3**  
Detect cycle using Kahn’s algorithm.

### **Exercise 4**  
Detect cycle using DFS.

### **Exercise 5**  
Solve Course Schedule I & II.

---

# **11. Solutions**

Use the implementations from sections 3–6.

---

# **12. Summary**

Today you mastered:

- Topological sort (DFS + BFS)  
- Kahn’s algorithm  
- Cycle detection in directed graphs  
- DAG properties  
- Dependency resolution  
- Real‑world graph applications  

This day is essential for **Day 25 — Shortest Paths: Dijkstra, Bellman‑Ford, BFS on Unweighted Graphs**.

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Write choose/explore/unchoose pattern explicitly.
- Define stopping condition before recursive calls.
- Use pruning rules to cut impossible branches early.
- Track path/state restoration on backtracking return.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Mutating shared containers without rollback.
- Missing base case for empty candidate set.
- Generating duplicate permutations/subsets.
- Not sorting when pruning depends on order.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: subsets and permutations.
- Medium: combination sum and palindrome partitioning.
- Hard: sudoku solver, N-Queens, word search with pruning.

