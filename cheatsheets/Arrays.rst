Arrays
======

Overview
--------

- Arrays store elements in contiguous memory.
- Indexing is zero-based in C++.
- Access by index is constant time.
- Most array interview problems reduce to one of: two pointers, sliding window,
  prefix sums, or hashing.

Core Patterns
-------------

- Fixed traversal

  - Single pass (`for i in [0..n-1]`)
  - Reverse pass (`for i in [n-1..0]`)

- Two pointers

  - Converging pointers (`l`, `r`) for pair/partition style problems.
  - Slow-fast pointers for in-place filtering (remove duplicates/zeros).

- Sliding window

  - Fixed window: maintain window of size `k`.
  - Variable window: expand right, shrink left while constraint is violated.

- Prefix techniques

  - Prefix sum for O(1) range queries.
  - Difference array for batched range updates.

STL Notes
---------

- Prefer `std::vector<T>` for dynamic arrays.
- Use `reserve()` when expected size is known.
- Use `std::array<T, N>` for fixed-size stack storage.

Complexity Snapshot
-------------------

- Access: O(1)
- Search: O(n) (linear), O(log n) if sorted + binary search
- Insert/Delete at end (`vector`): amortized O(1)
- Insert/Delete in middle: O(n)

Common Pitfalls
---------------

- Off-by-one boundaries (`< n` vs `<= n`).
- Integer overflow in sums/products (use `long long` when needed).
- Forgetting to handle empty input or size-1 input.
- Modifying container while iterating without index control.

Practice Ladder
---------------

- Easy: remove duplicates, move zeroes, best time to buy/sell stock.
- Medium: subarray sum equals K, longest substring variants, product except self.
- Hard: sliding window median, maximum subarray min-product.

Quick Recall
------------

- First think constraints, then choose pattern.
- Write invariants for window/pointers before coding.
- Dry run one edge case before finalizing.
