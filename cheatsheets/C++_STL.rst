C++ STL
=======

Overview
--------

- STL has four pillars: containers, iterators, algorithms, function objects.
- Choosing the right container usually matters more than micro-optimizations.

Container Selection
-------------------

- Sequence

  - `vector`: default dynamic array choice.
  - `deque`: fast push/pop at both ends.
  - `list`: stable iterators, fast node insert/erase.

- Ordered associative

  - `set`, `map`, `multiset`, `multimap` (tree-based, O(log n)).

- Unordered associative

  - `unordered_set`, `unordered_map` (average O(1)).

- Adapters

  - `stack`, `queue`, `priority_queue`.

Algorithm Essentials
--------------------

- Sorting: `sort`, `stable_sort`.
- Binary search tools: `lower_bound`, `upper_bound`.
- Numeric: `accumulate`.
- Selection: `nth_element`.

Iterator Invalidation (Must Know)
---------------------------------

- `vector`: reallocation invalidates pointers/iterators/references.
- `deque`: complex rules; assume non-end operations may invalidate iterators.
- `list`: iterators remain valid except erased elements.

Complexity Snapshot
-------------------

- `vector` random access: O(1)
- `map` operations: O(log n)
- `unordered_map` operations: average O(1)
- `priority_queue` push/pop: O(log n)

Common Pitfalls
---------------

- Accidental insertion via `map[key]`.
- Forgetting strict weak ordering in custom comparators.
- Copying heavy containers instead of passing by reference.

Practice Ladder
---------------

- Easy: vector + set exercises.
- Medium: custom sorting and heap tasks.
- Hard: multi-container design problems (cache/scheduler style).

Quick Recall
------------

- Pick container by operation profile.
- Reserve vector capacity when possible.
