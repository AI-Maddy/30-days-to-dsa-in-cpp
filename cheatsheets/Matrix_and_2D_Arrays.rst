Matrix and 2D Arrays
====================

Overview
--------

- 2D arrays model grids, images, boards, and DP tables.
- Most matrix problems are traversal, transformation, or search tasks.

Core Patterns
-------------

- Traversal

  - Row-wise, column-wise, diagonal, anti-diagonal.

- Boundary simulation

  - Spiral traversal and layer-by-layer operations.

- In-place transformation

  - Matrix transpose and rotate (90/180/270).

- Grid BFS/DFS

  - Treat cells as graph nodes with directional neighbors.

Search Patterns
---------------

- Fully sorted matrix

  - Binary search on flattened index.

- Row/column sorted matrix

  - Staircase search from top-right or bottom-left.

- Constraint checks

  - Validate boundaries before each neighbor step.

Complexity Snapshot
-------------------

- Basic traversal: O(n * m)
- Flattened binary search: O(log(n * m))
- Staircase search: O(n + m)

Common Pitfalls
---------------

- Swapping row/column limits.
- Reusing visited state incorrectly.
- In-place rotate index mistakes.
- Not handling empty matrix input.

Practice Ladder
---------------

- Easy: transpose matrix, matrix diagonal sum.
- Medium: spiral matrix, set matrix zeroes.
- Hard: rotate image in-place, maximal rectangle.

Quick Recall
------------

- Grid + reachability often means BFS/DFS.
- Sorted matrix search depends on sorting structure.
