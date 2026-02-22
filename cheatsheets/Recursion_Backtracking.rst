Recursion and Backtracking
==========================

Overview
--------

- Recursion solves a problem by reducing it to smaller subproblems.
- Backtracking explores choices and undoes them to try alternatives.

Recursion Essentials
--------------------

- Base case to stop recursion.
- Transition to smaller subproblem.
- Correct state passed to recursive calls.

Backtracking Skeleton
---------------------

- Choose
- Explore
- Unchoose (restore state)

Core Patterns
-------------

- Subsets (include/exclude).
- Permutations (swap or visited-array method).
- Combination sum style constrained search.
- Grid backtracking (word search, maze, sudoku).

Complexity Snapshot
-------------------

- Often exponential (e.g., O(2^n), O(n!)).
- Space mainly from recursion depth and current path storage.

Common Pitfalls
---------------

- Missing or weak base cases.
- Not restoring mutable state after recursion returns.
- Duplicate generation when input contains repeated values.
- No pruning for clearly invalid branches.

Practice Ladder
---------------

- Easy: subsets, permutations.
- Medium: combination sum, palindrome partitioning.
- Hard: sudoku solver, N-queens, word search.

Quick Recall
------------

- Backtracking performance comes from pruning quality.
