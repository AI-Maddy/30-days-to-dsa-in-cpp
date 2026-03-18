.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> BFS = shortest path in unweighted. DFS = connectivity, cycles. Dijkstra = weighted shortest. </span>
      <span style="color:#0f766e;">Topo sort exists only on DAGs. Cycle in directed graph → no topo sort.</span>
   </div>

=====================
🌐 Graphs Cheatsheet
=====================

----

🏗️ Graph Representation
=========================

.. code-block:: cpp

    int n = 5;  // nodes 0..n-1

    // Adjacency list (most common)
    vector<vector<int>> adj(n);
    adj[u].push_back(v);        // directed
    adj[u].push_back(v); adj[v].push_back(u);  // undirected

    // Weighted adjacency list
    vector<vector<pair<int,int>>> wadj(n);  // {neighbor, weight}
    wadj[u].push_back({v, w});

    // Adjacency matrix
    vector<vector<int>> mat(n, vector<int>(n, 0));
    mat[u][v] = 1;  // or weight

----

🔵 BFS Template
================

.. code-block:: cpp

    // BFS — O(V + E)
    vector<int> bfs(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> order;
        queue<int> q;
        visited[src] = true;
        q.push(src);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return order;
    }

----

🔴 DFS Template
================

.. code-block:: cpp

    // Recursive DFS
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) dfs(adj, visited, v);
        }
    }

    // Iterative DFS
    void dfsIter(vector<vector<int>>& adj, int src) {
        vector<bool> visited(adj.size(), false);
        stack<int> st;
        st.push(src);
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (visited[u]) continue;
            visited[u] = true;
            for (int v : adj[u]) if (!visited[v]) st.push(v);
        }
    }

----

📋 Topological Sort
====================

.. code-block:: cpp

    // BFS (Kahn's Algorithm) — works only on DAG
    vector<int> topoSort(vector<vector<int>>& adj, int n) {
        vector<int> indegree(n, 0);
        for (int u = 0; u < n; u++)
            for (int v : adj[u]) indegree[v]++;
        queue<int> q;
        for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
        }
        return order;  // if order.size() < n, cycle exists
    }

    // DFS topological sort
    void dfsTopo(vector<vector<int>>& adj, int u, vector<bool>& vis, stack<int>& stk) {
        vis[u] = true;
        for (int v : adj[u]) if (!vis[v]) dfsTopo(adj, v, vis, stk);
        stk.push(u);
    }

----

🔵 Dijkstra's Shortest Path
=============================

.. code-block:: cpp

    // O((V + E) log V) with min-heap
    vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;  // outdated entry
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

----

🔄 Cycle Detection
===================

.. code-block:: cpp

    // Directed graph — DFS with recStack
    bool hasCycleDFS(vector<vector<int>>& adj, int u,
                     vector<bool>& visited, vector<bool>& inStack) {
        visited[u] = inStack[u] = true;
        for (int v : adj[u]) {
            if (!visited[v] && hasCycleDFS(adj, v, visited, inStack)) return true;
            if (inStack[v]) return true;
        }
        inStack[u] = false;
        return false;
    }

    // Undirected graph — BFS with parent tracking
    bool hasCycleUndirected(vector<vector<int>>& adj, int n) {
        vector<bool> vis(n, false);
        for (int start = 0; start < n; start++) {
            if (vis[start]) continue;
            queue<pair<int,int>> q;  // {node, parent}
            vis[start] = true; q.push({start, -1});
            while (!q.empty()) {
                auto [u, par] = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!vis[v]) { vis[v] = true; q.push({v, u}); }
                    else if (v != par) return true;
                }
            }
        }
        return false;
    }

----

🏝️ Number of Islands / Flood Fill
====================================

.. code-block:: cpp

    // Number of connected components of '1' in binary grid
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r<0||r>=n||c<0||c>=m||grid[r][c]!='1') return;
            grid[r][c] = '0';  // mark visited
            for (int d = 0; d < 4; d++) dfs(r+dx[d], c+dy[d]);
        };
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (grid[r][c] == '1') { dfs(r,c); count++; }
        return count;
    }
