---

# **Day 26 — Floyd‑Warshall + Minimum Spanning Trees (Prim & Kruskal) (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Today’s algorithms power:

- Internet routing  
- Network design  
- Clustering  
- Logistics optimization  
- Social network analysis  
- Compiler optimization  
- Distributed systems  

You will master:

- Floyd‑Warshall (all‑pairs shortest paths)  
- Prim’s algorithm (MST using priority queue)  
- Kruskal’s algorithm (MST using DSU)  
- Disjoint Set Union (Union‑Find)  
- Cycle detection using DSU  
- When to use which algorithm  

This day is essential for advanced graph problems and competitive programming.

---

# **2. Floyd‑Warshall Algorithm (All‑Pairs Shortest Paths)**

Works on:

- Directed or undirected graphs  
- Weighted graphs  
- **Negative weights allowed**  
- **No negative cycles**  

Time complexity: **O(n³)**  
Space: **O(n²)**

---

## **2.1 Algorithm Logic**

For every pair (i, j), try improving the path using an intermediate node k:

```
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

---

## **2.2 Implementation**

```cpp
void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
```

---

## **2.3 Detecting Negative Cycles**

If `dist[i][i] < 0` for any i → negative cycle exists.

---

# **3. Minimum Spanning Tree (MST)**

A Minimum Spanning Tree:

- Connects all nodes  
- No cycles  
- Minimum total weight  

Used in:

- Network design  
- Clustering  
- Circuit design  
- Approximation algorithms  

Two major algorithms:

- **Prim’s Algorithm**  
- **Kruskal’s Algorithm**  

---

# **4. Prim’s Algorithm (Using Min‑Heap)**

Prim grows MST like Dijkstra grows shortest paths.

### **Use when:**

- Graph is dense  
- Adjacency list available  

Time: **O(E log V)**

---

## **4.1 Implementation**

```cpp
int primMST(int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(n, INT_MAX);
    vector<int> inMST(n, 0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    int total = 0;

    while (!pq.empty()) {
        auto [wt, node] = pq.top(); pq.pop();

        if (inMST[node]) continue;
        inMST[node] = 1;
        total += wt;

        for (auto &p : adj[node]) {
            int nei = p.first;
            int w = p.second;

            if (!inMST[nei] && w < key[nei]) {
                key[nei] = w;
                pq.push({w, nei});
            }
        }
    }
    return total;
}
```

---

# **5. Kruskal’s Algorithm (Using DSU)**

Kruskal sorts edges and picks the smallest edge that does not form a cycle.

### **Use when:**

- Graph is sparse  
- Edge list available  

Time: **O(E log E)**

---

# **6. Disjoint Set Union (Union‑Find)**

DSU supports:

- `find(x)` → find parent  
- `union(x, y)` → merge sets  

With optimizations:

- Path compression  
- Union by rank  

---

## **6.1 DSU Implementation**

```cpp
struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};
```

---

# **7. Kruskal’s Algorithm Implementation**

```cpp
int kruskalMST(int n, vector<tuple<int,int,int>>& edges) {
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b){ return get<2>(a) < get<2>(b); });

    DSU dsu(n);
    int total = 0;

    for (auto &[u, v, w] : edges) {
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            total += w;
        }
    }
    return total;
}
```

---

# **8. Prim vs Kruskal — When to Use What**

| Scenario | Best Algorithm |
|---------|----------------|
| Dense graph | Prim |
| Sparse graph | Kruskal |
| Edge list given | Kruskal |
| Adjacency list given | Prim |
| Need MST incrementally | Prim |
| Need MST from sorted edges | Kruskal |

---

# **9. Real‑World Examples**

### **Example 1 — Internet Backbone Design**  
MST minimizes cable cost.

### **Example 2 — Clustering Algorithms**  
Kruskal helps form clusters.

### **Example 3 — Routing Protocols**  
Floyd‑Warshall for all‑pairs shortest paths.

### **Example 4 — Logistics Optimization**  
Prim builds minimum‑cost networks.

---

# **10. Interview‑Level Problems**

### **Problem 1 — MST using Prim**  
Classic.

### **Problem 2 — MST using Kruskal**  
DSU + sorting.

### **Problem 3 — Detect cycle using DSU**  
Union‑Find.

### **Problem 4 — All‑pairs shortest paths**  
Floyd‑Warshall.

### **Problem 5 — Negative cycle detection**  
Floyd‑Warshall diagonal check.

---

# **11. Exercises (Try First)**

### **Exercise 1**  
Implement Floyd‑Warshall.

### **Exercise 2**  
Implement Prim’s MST.

### **Exercise 3**  
Implement Kruskal’s MST.

### **Exercise 4**  
Implement DSU with path compression.

### **Exercise 5**  
Detect negative cycles using Floyd‑Warshall.

---

# **12. Solutions**

Use the implementations from sections 2–7.

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

