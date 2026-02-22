Backtracking Advanced Problems
==============================

Overview
--------

- Advanced backtracking problems rely on pruning, constraint propagation, and state restoration.

Problem Families
----------------

- N-Queens
- Sudoku solver
- Word search
- Rat in a maze
- Graph coloring (M-coloring)

Pruning Strategies
------------------

- Feasibility pruning

  - Reject early if constraints already violated.

- Bound pruning

  - Stop if partial state cannot reach target.

- Duplicate-state pruning

  - Skip repeated candidates/states.

State Design
------------

- Use compact auxiliary arrays where possible.

  - Columns/diagonals arrays in N-Queens.
  - Row/column/box sets in Sudoku.

- Always restore state on backtrack.

Complexity Snapshot
-------------------

- Typically exponential in worst case.
- Pruning quality heavily affects practical runtime.

Common Pitfalls
---------------

- Forgetting to undo marks/choices.
- Recomputing expensive checks repeatedly.
- Missing termination conditions for solved states.

Practice Ladder
---------------

- Easy: combinations/permutations with constraints.
- Medium: word search, subset with duplicates.
- Hard: sudoku, N-Queens, M-coloring.

Quick Recall
------------

- Speed in backtracking comes from pruning, not brute-force depth.
