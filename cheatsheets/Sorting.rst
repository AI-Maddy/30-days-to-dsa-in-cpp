Sorting
=======

Overview
--------

- Sorting orders data for faster downstream operations.
- Key properties: stability, in-place behavior, worst-case guarantees.

Comparison Sorts
----------------

- Bubble sort: educational, O(n^2).
- Insertion sort: good for nearly-sorted or small arrays.
- Merge sort: stable O(n log n), extra memory.
- Quick sort: average O(n log n), worst O(n^2).
- Heap sort: O(n log n), in-place, unstable.

Non-Comparison Sorts
--------------------

- Counting sort: O(n + k) for bounded integer range.
- Radix sort: digit-wise sorting for integer/string-like keys.

STL Notes
---------

- `std::sort` uses introsort.
- `std::stable_sort` keeps relative order of equal keys.
- Custom comparators must satisfy strict weak ordering.

Complexity Snapshot
-------------------

- Typical baseline for general sorting: O(n log n)
- Counting/radix can beat comparison lower bound under constraints.

Common Pitfalls
---------------

- Incorrect comparator leading to undefined behavior.
- Ignoring stability requirement.
- Using quadratic sorts on large inputs.

Practice Ladder
---------------

- Easy: insertion and selection dry runs.
- Medium: interval merge and custom sort tasks.
- Hard: radix/counting constraints and greedy-sort hybrids.

Quick Recall
------------

- Choose algorithm by constraints, not by habit.
