Binary Search Tree
==================

Overview
--------

- BST invariant: keys in left subtree are smaller, right subtree are larger.
- Ordering enables efficient search-like operations.

Core Operations
---------------

- Search

  - Compare and move left/right accordingly.

- Insert

  - Traverse to null position preserving BST order.

- Delete

  - Case 1: leaf node.
  - Case 2: one child.
  - Case 3: two children (swap with inorder successor/predecessor).

High-Value Patterns
-------------------

- Validate BST with min/max bounds.
- Floor/ceil queries.
- K-th smallest via inorder traversal.
- LCA in BST using key ordering.

Complexity Snapshot
-------------------

- Search/insert/delete: O(h)
- Balanced BST: O(log n)
- Skewed BST: O(n)

Common Pitfalls
---------------

- Duplicate handling policy not defined.
- Incorrect bounds in BST validation.
- Deletion bugs when reconnecting child pointers.

Practice Ladder
---------------

- Easy: search/insert.
- Medium: validate BST, floor/ceil.
- Hard: delete node, recover swapped BST.

Quick Recall
------------

- Inorder traversal of BST gives sorted order.
