Prefix Sum and Difference Array
===============================

Overview
--------

- Prefix sums answer range-sum queries quickly.
- Difference arrays apply many range updates efficiently.
- Together, they convert repeated O(n) work into O(1) per query/update (plus one reconstruction pass).

Prefix Sum
----------

- Definition

  - `pref[i] = a[0] + a[1] + ... + a[i]`

- Range sum query

  - `sum(l..r) = pref[r] - (pref[l-1] if l > 0 else 0)`

- 2D prefix sum

  - `pref[r][c]` stores rectangle sum `(0,0)` to `(r,c)`.
  - Rectangle query uses inclusion-exclusion.

Difference Array
----------------

- For 1D range increment `+x` on `[l..r]`

  - `diff[l] += x`
  - `diff[r+1] -= x` (if `r+1 < n`)

- Reconstruct final array by prefixing `diff`.

Common Use Cases
----------------

- Multiple offline range updates.
- Subarray sum equals K via prefix-hash map.
- Count/range frequency contribution problems.
- Sweep-line style interval accumulation.

Complexity Snapshot
-------------------

- Prefix build: O(n)
- Prefix range query: O(1)
- Difference update: O(1) per update
- Final reconstruction after all updates: O(n)

Common Pitfalls
---------------

- Off-by-one at `r + 1` in difference arrays.
- Overflow in cumulative sums (`long long` often required).
- Confusing inclusive vs exclusive boundaries.

Practice Ladder
---------------

- Easy: range sum query immutable.
- Medium: car pooling / corporate flight bookings style updates.
- Hard: 2D range update + 2D range query combinations.

Quick Recall
------------

- Many queries -> prefix.
- Many updates -> difference.
- Many both -> segment tree / BIT.
