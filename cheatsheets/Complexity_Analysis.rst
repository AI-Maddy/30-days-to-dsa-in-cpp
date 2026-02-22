Complexity Analysis
===================

Overview
--------

- Complexity estimates growth as input size increases.
- Main notations: Big-O (upper bound), Big-Omega (lower bound), Big-Theta (tight bound).

Time Complexity Essentials
--------------------------

- O(1): constant work
- O(log n): halving search space
- O(n): full scan
- O(n log n): divide + combine sorts
- O(n^2): nested loops
- O(2^n), O(n!): combinatorial explosion

Space Complexity Essentials
---------------------------

- Auxiliary space counts extra memory beyond input storage.
- Recursive solutions include call stack usage.

Analysis Workflow
-----------------

- Loops: count iterations and nesting.
- Recurrence relations: apply Master theorem or expansion.
- Amortized analysis: average over operation sequences.

Complexity in Interviews
------------------------

- Always report both time and auxiliary space.
- Mention average vs worst-case when it changes decisions.
- Explain tradeoffs (faster time for more memory, or vice versa).

Common Pitfalls
---------------

- Ignoring hidden nested work in library calls.
- Missing recursion stack space.
- Reporting average case as guaranteed worst case.

Practice Ladder
---------------

- Easy: classify common loop constructs.
- Medium: analyze recursive divide-and-conquer patterns.
- Hard: amortized proofs and mixed data structure operations.

Quick Recall
------------

- Drop constants and lower-order terms for asymptotic comparison.
- Dominant term decides growth for large `n`.
