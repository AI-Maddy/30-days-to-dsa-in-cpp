Linked Lists
============

Overview
--------

- Linked lists are node-based dynamic sequences.
- Main variants: singly, doubly, circular.
- Strength: efficient local insert/delete.
- Weakness: no random access.

Core Operations
---------------

- Traversal from head.
- Insert/delete at head or tail.
- Reverse list (iterative and recursive).
- Fast-slow pointer techniques.

High-Value Patterns
-------------------

- Dummy node to simplify head-edge cases.
- Two pointers for remove N-th from end.
- Floyd cycle detection and cycle entry finding.
- Merge sorted lists and merge-sort on linked lists.

Complexity Snapshot
-------------------

- Traversal: O(n)
- Head insert/delete: O(1)
- Tail insert: O(1) with tail pointer, otherwise O(n)
- Search/access by index: O(n)

Common Pitfalls
---------------

- Losing `next` pointer before rewiring links.
- Null pointer dereference on short lists.
- Forgetting to update both `next` and `prev` in doubly lists.

Practice Ladder
---------------

- Easy: reverse list, middle node.
- Medium: remove N-th from end, detect cycle.
- Hard: merge k lists, flatten multilevel list.

Quick Recall
------------

- Draw pointer movement first, then code.
