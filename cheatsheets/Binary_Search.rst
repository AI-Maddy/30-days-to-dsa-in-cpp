Binary Search
=============

Overview
--------

- Binary search works on monotonic spaces.
- It is not only for arrays; it also applies to answer-space optimization.
- The most reliable approach is to use invariant-based templates.

Core Patterns
-------------

- Classic search in sorted array.
- First/last occurrence.
- Lower bound / upper bound.
- Search in rotated sorted arrays.
- Binary search on answer (minimum feasible or maximum feasible).

Template Thinking
-----------------

- Decide invariant first.

  - `first_true`: keep a range where answer exists, move `high = mid` on success.
  - `last_true`: keep a range where answer exists, move `low = mid` on success.

- Midpoint

  - Use `mid = low + (high - low) / 2`.

- Termination

  - Ensure each branch strictly shrinks the search space.

STL Notes
---------

- `std::lower_bound(begin, end, x)` -> first element `>= x`.
- `std::upper_bound(begin, end, x)` -> first element `> x`.
- `std::binary_search(begin, end, x)` -> boolean existence.

Complexity Snapshot
-------------------

- Time: O(log n)
- Space: O(1) iterative, O(log n) recursive

Common Pitfalls
---------------

- Infinite loops from inconsistent boundary updates.
- Returning `mid` directly without post-processing for first/last true tasks.
- Applying BS where predicate is not monotonic.
- Overflow in midpoint formula.

Practice Ladder
---------------

- Easy: binary search, lower/upper bound.
- Medium: search in rotated sorted array, first/last position.
- Hard: aggressive cows, minimum days, split array largest sum.

Quick Recall
------------

- Define monotonic predicate in one sentence.
- Choose template (`first_true` or `last_true`).
- Test with smallest and largest feasible values.
