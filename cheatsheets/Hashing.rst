Hashing
=======

Overview
--------

- Hashing maps keys to buckets for near O(1) expected operations.
- Primary applications: frequency counting, deduplication, quick membership,
  and prefix-sum map tricks.

Core Concepts
-------------

- Hash function quality affects collision rates.
- Load factor controls performance.
- Collision handling: chaining or open addressing.

C++ Containers
--------------

- `unordered_map<K, V>` for key-value lookups.
- `unordered_set<K>` for membership tests.
- `map`/`set` if sorted order is required.

Common Problem Patterns
-----------------------

- Frequency table counting.
- Prefix sum + hash map for subarray counting.
- Last-seen index maps for window/string problems.
- Grouping anagrams by normalized key.

Complexity Snapshot
-------------------

- Average insert/find/erase: O(1)
- Worst-case insert/find/erase: O(n)
- Space: O(n)

Common Pitfalls
---------------

- Assuming deterministic order in unordered containers.
- Forgetting to initialize base prefix count (often `count[0] = 1`).
- Using ordered maps unnecessarily and paying O(log n) cost.

Practice Ladder
---------------

- Easy: two sum, valid anagram.
- Medium: longest consecutive sequence, subarray sum equals K.
- Hard: counting subarrays under multiple constraints.

Quick Recall
------------

- Hashing is often the shortest path from O(n^2) to O(n).
