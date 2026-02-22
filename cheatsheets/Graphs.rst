Graphs
======

Overview
--------

- Graphs model pairwise relationships between entities.
- Representation and traversal choices determine performance.

Representations
---------------

- Adjacency list

  - Preferred for sparse graphs.
  - Space: O(V + E)

- Adjacency matrix

  - Useful for dense graphs or O(1) edge checks.
  - Space: O(V^2)

Core Traversals
---------------

- BFS

  - Level-order exploration using queue.
  - Shortest path in unweighted graphs.

- DFS

  - Deep exploration using recursion/stack.
  - Useful for components, cycle checks, topological workflows.

High-Value Algorithms
---------------------

- Shortest paths: BFS, Dijkstra, Bellman-Ford.
- Topological sorting: Kahn's algorithm / DFS postorder.
- Minimum spanning tree: Kruskal / Prim.
- Connectivity and components via BFS/DFS.

Complexity Snapshot
-------------------

- BFS/DFS: O(V + E)
- Dijkstra (heap): O((V + E) log V)
- Kruskal: O(E log E)

Common Pitfalls
---------------

- Marking visited too late causing duplicates.
- Forgetting disconnected components.
- Mixing 0-based and 1-based indexing.
- Using Dijkstra with negative edges.

Practice Ladder
---------------

- Easy: BFS/DFS traversal, number of islands.
- Medium: course schedule, bipartite checks.
- Hard: constrained shortest paths and DAG DP hybrids.

Quick Recall
------------

- Unweighted shortest path -> BFS.
- Weighted non-negative shortest path -> Dijkstra.
