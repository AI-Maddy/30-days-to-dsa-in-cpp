Monotonic Stack and Queue
=========================

Overview
--------

- Monotonic structures maintain ordered candidates while scanning.
- They are ideal for nearest greater/smaller and sliding-window extrema.

Monotonic Stack
---------------

- Increasing stack

  - Useful for next smaller element patterns.

- Decreasing stack

  - Useful for next greater element patterns.

- Typical flow

  - While stack top violates monotonic condition: pop.
  - Current answer comes from new top.
  - Push current index/value.

Monotonic Queue (Deque)
-----------------------

- Used for sliding window maximum/minimum.
- Store indices, not just values.
- Remove out-of-window indices from front.
- Remove dominated candidates from back.

Core Problem Types
------------------

- Next greater/smaller element.
- Stock span.
- Daily temperatures.
- Largest rectangle in histogram.
- Sliding window maximum/minimum.

Complexity Snapshot
-------------------

- Most operations are amortized O(1).
- Full scan solution usually O(n).

Common Pitfalls
---------------

- Mixing indices and values inconsistently.
- Wrong comparison operator (`>` vs `>=`) for duplicate handling.
- Forgetting out-of-window eviction in deque-based problems.

Practice Ladder
---------------

- Easy: next greater element I.
- Medium: daily temperatures, stock span.
- Hard: largest rectangle in histogram, maximal rectangle.

Quick Recall
------------

- Monotonic stack -> nearest relation.
- Monotonic deque -> sliding window extrema.
