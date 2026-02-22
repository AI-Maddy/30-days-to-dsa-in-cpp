---

# **Day 23 — Graphs: BFS, DFS, Adjacency List, Cycle Detection (Directed + Undirected) (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Graphs are everywhere:

- Social networks  
- Maps & navigation  
- Recommendation systems  
- Compilers (dependency graphs)  
- Operating systems (deadlock detection)  
- Networking (routing algorithms)  
- AI search algorithms  

Today’s goal is to master:

- Graph representation  
- BFS (Breadth‑First Search)  
- DFS (Depth‑First Search)  
- Cycle detection in undirected graphs  
- Cycle detection in directed graphs  
- Connected components  
- Graph traversal patterns  
- Handling disconnected graphs  

This day is the foundation for Days 24–26 (Topological Sort, Shortest Paths, MSTs).

---

# **2. Graph Representation**

Graphs can be represented using:

- **Adjacency List** (most common)  
- **Adjacency Matrix**  
- **Edge List**  

---

## **2.1 Adjacency List (Recommended)**

```cpp
vector<vector<int>> adj(n);

adj[u].push_back(v);
adj[v].push_back(u); // for undirected
```

---

## **2.2 Adjacency Matrix**

```cpp
vector<vector<int>> adj(n, vector<int>(n, 0));
adj[u][v] = adj[v][u] = 1;
```

---

## **2.3 Edge List**

```cpp
vector<pair<int,int>> edges;
```

Used in Kruskal’s algorithm.

---

# **3. BFS (Breadth‑First Search)**

BFS explores level by level.

Used for:

- Shortest path in unweighted graph  
- Level order traversal  
- Connected components  
- Bipartite check  

---

## **3.1 BFS Implementation**

```cpp
vector<int> bfs(int n, vector<vector<int>>& adj, int start) {
    vector<int> vis(n, 0), order;
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                vis[nei] = 1;
                q.push(nei);
            }
        }
    }
    return order;
}
```

---

# **4. DFS (Depth‑First Search)**

DFS explores deep before wide.

Used for:

- Cycle detection  
- Topological sort  
- Connected components  
- Tree/graph DP  
- Path finding  

---

## **4.1 DFS Implementation**

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
    vis[node] = 1;
    order.push_back(node);

    for (int nei : adj[node]) {
        if (!vis[nei])
            dfs(nei, adj, vis, order);
    }
}
```

---

# **5. Connected Components**

Graphs may be disconnected.

### **Implementation**

```cpp
int countComponents(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            vector<int> order;
            dfs(i, adj, vis, order);
        }
    }
    return count;
}
```

---

# **6. Cycle Detection in Undirected Graph**

Use DFS with parent tracking.

---

## **6.1 Implementation**

```cpp
bool dfsCycle(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;

    for (int nei : adj[node]) {
        if (!vis[nei]) {
            if (dfsCycle(nei, node, adj, vis))
                return true;
        }
        else if (nei != parent)
            return true;
    }
    return false;
}

bool hasCycleUndirected(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfsCycle(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}
```

---

# **7. Cycle Detection in Directed Graph**

Use DFS + recursion stack.

---

## **7.1 Implementation**

```cpp
bool dfsDirected(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (int nei : adj[node]) {
        if (!vis[nei]) {
            if (dfsDirected(nei, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[nei])
            return true;
    }

    pathVis[node] = 0;
    return false;
}

bool hasCycleDirected(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0), pathVis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfsDirected(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}
```

---

# **8. BFS Cycle Detection (Undirected)**

```cpp
bool bfsCycle(int start, vector<vector<int>>& adj, vector<int>& vis) {
    queue<pair<int,int>> q;
    q.push({start, -1});
    vis[start] = 1;

    while (!q.empty()) {
        auto [node, parent] = q.front(); q.pop();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                vis[nei] = 1;
                q.push({nei, node});
            }
            else if (nei != parent)
                return true;
        }
    }
    return false;
}
```

---

# **9. Real‑World Examples**

---

### **Example 1 — Social Networks**  
Users = nodes  
Friendships = edges  

---

### **Example 2 — Maps & Navigation**  
Cities = nodes  
Roads = edges  

---

### **Example 3 — Deadlock Detection**  
Directed cycle = deadlock  

---

### **Example 4 — Build Systems (Make, Bazel)**  
Dependencies = directed graph  
Cycle = impossible build  

---

# **10. Interview‑Level Problems**

---

### **Problem 1 — BFS traversal**  
Classic.

---

### **Problem 2 — DFS traversal**  
Classic.

---

### **Problem 3 — Cycle detection (undirected)**  
DFS + parent.

---

### **Problem 4 — Cycle detection (directed)**  
DFS + recursion stack.

---

### **Problem 5 — Connected components**  
DFS/BFS.

---

# **11. Exercises (Try First)**

---

### **Exercise 1**  
Implement BFS from a given node.

---

### **Exercise 2**  
Implement DFS from a given node.

---

### **Exercise 3**  
Detect cycle in an undirected graph.

---

### **Exercise 4**  
Detect cycle in a directed graph.

---

### **Exercise 5**  
Count connected components.

---

# **12. Solutions**

Use the implementations from sections 3–7.

---

# **13. Summary**

Today you mastered:

- Graph representation  
- BFS and DFS  
- Connected components  
- Cycle detection (directed + undirected)  
- Traversal patterns  
- Real‑world graph applications  

This day sets the stage for **Day 24 — Topological Sort, Kahn’s Algorithm, DFS Ordering**.

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

