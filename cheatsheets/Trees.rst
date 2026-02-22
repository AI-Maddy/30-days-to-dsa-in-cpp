Trees
=====

Overview
--------

- Trees represent hierarchical data with parent-child relationships.
- Binary tree and BST are the most common interview variants.

Traversal Fundamentals
----------------------

- DFS traversals

  - Preorder: root-left-right
  - Inorder: left-root-right
  - Postorder: left-right-root

- BFS traversal

  - Level-order using queue.

BST Essentials
--------------

- BST invariant: left subtree < node < right subtree.
- Search/insert/delete depend on preserving this ordering.
- Inorder traversal of BST yields sorted order.

High-Value Patterns
-------------------

- Height/depth recursion.
- Diameter and balanced-tree checks.
- LCA in binary tree and in BST.
- Serialization/deserialization patterns.

Complexity Snapshot
-------------------

- Traversals: O(n)
- BST operations: O(h), where `h` is height
- Balanced BST gives O(log n), skewed tree gives O(n)

Common Pitfalls
---------------

- Missing null checks in recursive calls.
- Mixing node-level and subtree-level logic.
- Forgetting edge cases in reconstruction/serialization.

Practice Ladder
---------------

- Easy: depth, basic traversals.
- Medium: LCA, zigzag, boundary traversal.
- Hard: tree construction from traversals, Morris traversal variants.

Quick Recall
------------

- Decide BFS vs DFS by question type (levels/views vs path/subtree logic).
