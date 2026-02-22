Greedy Algorithms
=================

Overview
--------

- Greedy algorithms make locally optimal choices at each step.
- They work when local choices can be proven to yield global optimum.

When Greedy Works
-----------------

- Greedy-choice property.
- Optimal substructure.
- Exchange argument or cut property can justify correctness.

Classic Patterns
----------------

- Interval scheduling / activity selection.
- Fractional knapsack (value-to-weight ratio sorting).
- Jump game reachability and minimum jumps.
- Minimum platforms / meeting rooms by sorted events.

Design Workflow
---------------

- Identify optimization target.
- Propose a local rule (sort by end time, ratio, etc.).
- Prove with exchange argument.
- Validate with edge-case counterexamples.

Complexity Snapshot
-------------------

- Usually dominated by sorting: O(n log n).
- Some scans are O(n) after sorting.

Common Pitfalls
---------------

- Applying greedy where DP is required.
- Missing tie-break rules in sorting.
- Comparator mistakes violating strict weak ordering.

Practice Ladder
---------------

- Easy: assign cookies, lemonade change.
- Medium: activity selection, interval merge.
- Hard: jump game II proof-based variants.

Quick Recall
------------

- If greedy is chosen, include correctness argument, not just implementation.
