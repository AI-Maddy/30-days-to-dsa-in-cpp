Graph Algorithms Advanced
=========================

Overview
--------

- Advanced graph tasks include shortest paths, DAG ordering, and dependency constraints.
- Algorithm choice depends on edge weights, direction, and cycle properties.

Shortest Paths
--------------

- BFS (unweighted graph): shortest edges count.
- Dijkstra (non-negative weights): priority queue based.
- Bellman-Ford (negative edges allowed): detects negative cycles.
- Floyd-Warshall: all-pairs shortest paths, O(n^3).

DAG Workflows
-------------

- Topological sort (Kahn / DFS postorder).
- Course schedule feasibility via indegrees.
- Longest/shortest path in DAG with topo order DP.

Minimum Spanning Tree
---------------------

- Kruskal

  - Sort edges + DSU to avoid cycles.

- Prim

  - Grow tree via min-edge frontier.

Complexity Snapshot
-------------------

- Dijkstra: O((V + E) log V)
- Bellman-Ford: O(V * E)
- Topological sort: O(V + E)
- Kruskal: O(E log E)

Common Pitfalls
---------------

- Running Dijkstra on negative edges.
- Forgetting to process disconnected components.
- Direction mistakes when building directed graph adjacency.
- Incorrect DSU union/rank handling.

Practice Ladder
---------------

- Easy: shortest path in unweighted graph.
- Medium: course schedule, network delay time.
- Hard: cheapest flights with constraints, MST variants.

Quick Recall
------------

- Negative weight? think Bellman-Ford.
- DAG dependency order? think topological sort.
