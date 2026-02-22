Dynamic Programming
===================

Overview
--------

- DP solves problems with overlapping subproblems and optimal substructure.
- Typical flow: recursion -> memoization -> tabulation -> space optimization.

State Design
------------

- Define state minimally but completely.
- State often includes index plus context (capacity, previous choice, mask, etc.).
- Write recurrence before coding.

Core Patterns
-------------

- 1D DP

  - Examples: climbing stairs, house robber.

- 2D DP

  - Examples: knapsack, LCS, edit distance.

- Include/exclude transitions

  - Choose current item or skip it.

- Sequence extension transitions

  - Build best answer ending at position `i`.

Implementation Styles
---------------------

- Memoization

  - Easy to derive from recursion.
  - Good when many states are unreachable.

- Tabulation

  - Predictable and iterative.
  - Requires correct iteration order.

Complexity Snapshot
-------------------

- Usually O(number of states * transition cost).
- Space can often be reduced by keeping only previous row/columns.

Common Pitfalls
---------------

- Incomplete state (causes invalid reuse).
- Incorrect base cases.
- Wrong loop order in tabulation.
- Optimizing space before validating correctness.

Practice Ladder
---------------

- Easy: Fibonacci variants, house robber.
- Medium: knapsack family, partition equal subset sum.
- Hard: digit DP, bitmask DP.

Quick Recall
------------

- State + transition + base case = DP skeleton.
