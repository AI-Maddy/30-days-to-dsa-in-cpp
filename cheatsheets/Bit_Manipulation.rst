Bit Manipulation
================

Overview
--------

- Bit manipulation gives compact and fast operations on integers.
- Core operators: `&`, `|`, `^`, `~`, `<<`, `>>`.
- Common use-cases: flags, parity, subset masks, XOR tricks.

Core Operations
---------------

- Check k-th bit: `n & (1 << k)`
- Set k-th bit: `n | (1 << k)`
- Clear k-th bit: `n & ~(1 << k)`
- Toggle k-th bit: `n ^ (1 << k)`
- Remove lowest set bit: `n & (n - 1)`
- Isolate lowest set bit: `n & -n`

High-Value Tricks
-----------------

- Power of two: `n > 0 && (n & (n - 1)) == 0`
- Count set bits

  - Builtin: `__builtin_popcount`, `__builtin_popcountll`
  - C++20: `std::popcount`

- XOR identities

  - `a ^ a = 0`
  - `a ^ 0 = a`
  - Useful for odd-frequency/single-number problems.

- Subset generation by mask

  - Iterate `mask` from `0` to `(1 << n) - 1`.

Complexity Snapshot
-------------------

- Primitive bit operations: O(1)
- Counting bits via loop: O(number of bits)
- Enumerating subsets: O(n * 2^n)

Common Pitfalls
---------------

- Shifting signed integers can produce implementation-defined behavior.
- `1 << k` may overflow for large `k` on 32-bit `int`.
- Precedence mistakes in mixed expressions (`&`, `==`, etc.).

Practice Ladder
---------------

- Easy: power of two, count bits, single number.
- Medium: subset XOR sum, bitmasking strings.
- Hard: bitmask DP and state compression.

Quick Recall
------------

- Prefer unsigned types for shifts.
- Remember the pair: `n & (n-1)` vs `n & -n`.
