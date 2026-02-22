Tree Views and Construction
===========================

Overview
--------

- Advanced tree tasks involve level views, vertical projections, and reconstruction from traversals.

View-Based Traversals
---------------------

- Level order and zigzag.
- Left view and right view.
- Top view and bottom view.
- Boundary traversal.
- Vertical order traversal.

Core Techniques
---------------

- BFS with queue for level-wise logic.
- Horizontal distance mapping for top/bottom/vertical views.
- Ordered maps for deterministic left-to-right output.

Tree Construction
-----------------

- Construct from preorder + inorder.
- Construct from postorder + inorder.
- Use index map for inorder positions to avoid O(n^2).

Serialization
-------------

- BFS serialization with null markers.
- DFS preorder serialization with sentinels.

Complexity Snapshot
-------------------

- Most view traversals: O(n)
- Construction with index map: O(n)
- Extra space typically O(n)

Common Pitfalls
---------------

- Wrong queue-level handling in zigzag/side views.
- Missing tie-break rules in vertical traversal.
- Incorrect subtree ranges during construction.

Practice Ladder
---------------

- Easy: level order, left/right view.
- Medium: top/bottom view, boundary traversal.
- Hard: construct tree + serialize/deserialize roundtrip.

Quick Recall
------------

- Level/view questions usually start with BFS.
