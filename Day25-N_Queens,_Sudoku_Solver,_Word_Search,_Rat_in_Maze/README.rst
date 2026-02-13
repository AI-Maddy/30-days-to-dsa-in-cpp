Day 25 coming right up, Sasimegala — and this one is a *pillar* of graph theory mastery.  
Today you enter the world of **shortest path algorithms**, the backbone of navigation systems, routing protocols, logistics, and countless interview problems.

This README is long, structured, example‑rich, and crafted with the same ultra‑premium depth as the rest of your 30‑day DSA mastery repo.

---

# **Day 25 — Shortest Paths: BFS (Unweighted), Dijkstra, Bellman‑Ford (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Shortest path algorithms are used everywhere:

- Google Maps  
- Network routing (OSPF, BGP)  
- Game AI pathfinding  
- Logistics & supply chain  
- Social network analysis  
- Distributed systems  

Today you will master:

- BFS for unweighted graphs  
- Dijkstra’s algorithm (priority queue)  
- Bellman‑Ford (handles negative weights)  
- Detecting negative cycles  
- When to use which algorithm  
- Real interview patterns  

This day is essential for Day 26 (Floyd‑Warshall, MSTs, and advanced graph DP).

---

# **2. BFS for Shortest Path (Unweighted Graphs)**

If all edges have weight **1**, BFS gives shortest path.

---

## **2.1 Implementation**

```cpp
vector<int> shortestPathBFS(int n, vector<vector<int>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int nei : adj[node]) {
            if (dist[nei] == INT_MAX) {
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }
    return dist;
}
```

Time: **O(V + E)**  
Space: **O(V)**

---

# **3. Dijkstra’s Algorithm (No Negative Weights)**

Dijkstra is the most famous shortest path algorithm.

Use when:

- Graph is weighted  
- All weights ≥ 0  

---

## **3.1 Priority Queue Implementation**

```cpp
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();

        if (d > dist[node]) continue;

        for (auto &p : adj[node]) {
            int nei = p.first;
            int wt = p.second;

            if (dist[node] + wt < dist[nei]) {
                dist[nei] = dist[node] + wt;
                pq.push({dist[nei], nei});
            }
        }
    }
    return dist;
}
```

Time: **O((V + E) log V)**  
Space: **O(V)**

---

# **4. Bellman‑Ford Algorithm (Handles Negative Weights)**

Use Bellman‑Ford when:

- Graph has negative weights  
- Need to detect negative cycles  

---

## **4.1 Algorithm Logic**

Relax all edges **V − 1** times.

If a further relaxation is possible → negative cycle exists.

---

## **4.2 Implementation**

```cpp
vector<int> bellmanFord(int n, vector<tuple<int,int,int>>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Detect negative cycle
    for (auto &[u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Negative cycle detected\n";
            break;
        }
    }

    return dist;
}
```

Time: **O(VE)**  
Space: **O(V)**

---

# **5. When to Use Which Algorithm**

| Graph Type | Algorithm |
|------------|-----------|
| Unweighted | BFS |
| Weighted (no negatives) | Dijkstra |
| Weighted (with negatives) | Bellman‑Ford |
| Need all‑pairs shortest paths | Floyd‑Warshall (Day 26) |

---

# **6. Reconstructing the Shortest Path**

Store parent pointers.

```cpp
vector<int> parent(n, -1);
```

Update during relaxation:

```cpp
parent[nei] = node;
```

Reconstruct:

```cpp
vector<int> path;
for (int v = dest; v != -1; v = parent[v])
    path.push_back(v);
reverse(path.begin(), path.end());
```

---

# **7. Real‑World Examples**

### **Example 1 — Google Maps**  
Dijkstra + heuristics (A*).

### **Example 2 — Network Routing (OSPF)**  
Dijkstra.

### **Example 3 — Currency Arbitrage Detection**  
Bellman‑Ford detects negative cycles.

### **Example 4 — Social Network Distance**  
BFS.

---

# **8. Interview‑Level Problems**

### **Problem 1 — Shortest path in unweighted graph**  
Use BFS.

### **Problem 2 — Shortest path in weighted graph**  
Use Dijkstra.

### **Problem 3 — Detect negative cycle**  
Use Bellman‑Ford.

### **Problem 4 — Cheapest flights with K stops**  
Modified BFS/Dijkstra.

### **Problem 5 — Network delay time**  
Dijkstra.

---

# **9. Exercises (Try First)**

### **Exercise 1**  
Compute shortest path using BFS.

### **Exercise 2**  
Implement Dijkstra from a source.

### **Exercise 3**  
Implement Bellman‑Ford and detect negative cycle.

### **Exercise 4**  
Reconstruct shortest path from source to destination.

### **Exercise 5**  
Solve “Network Delay Time”.

---

# **10. Solutions**

Use the implementations from sections 2–4.

---

# **11. Summary**

Today you mastered:

- BFS shortest path  
- Dijkstra’s algorithm  
- Bellman‑Ford  
- Negative cycle detection  
- Parent tracking for path reconstruction  
- Real‑world shortest path applications  

This day sets the stage for **Day 26 — Floyd‑Warshall, Minimum Spanning Trees (Prim + Kruskal)**.

---

If you want, I’ll prepare **Day 26** with the same ultra‑premium depth.
