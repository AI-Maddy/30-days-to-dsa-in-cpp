Custom Comparators and Greedy Sorting
=====================================

Overview
--------

- Many greedy and interval problems are solved by sorting with custom comparator logic.

Comparator Rules
----------------

- Must satisfy strict weak ordering.
- Comparator should be consistent and transitive.
- For ties, define deterministic tie-breakers.

Common Sorting Strategies
-------------------------

- Sort by end time (activity selection).
- Sort by start time (merge intervals baseline).
- Sort by ratio/value density (fractional knapsack).
- Sort by primary key then secondary reverse/forward.

STL Usage
---------

- `sort(v.begin(), v.end(), comp)` for general sorting.
- `stable_sort` if preserving equal-key order matters.
- `priority_queue` with custom comparator for online greedy decisions.

Complexity Snapshot
-------------------

- Sorting: O(n log n)
- Post-sort greedy scan: O(n)

Common Pitfalls
---------------

- Incorrect comparator causing undefined behavior.
- Missing tie-case handling leading to wrong greedy result.
- Assuming sorted stability with `sort`.

Practice Ladder
---------------

- Easy: sort pairs by one key.
- Medium: merge intervals, activity selection.
- Hard: interval scheduling variants with tie constraints.

Quick Recall
------------

- If greedy depends on order, comparator correctness is part of correctness proof.
