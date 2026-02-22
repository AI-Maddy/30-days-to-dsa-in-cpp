Parentheses, RPN, and Cache Design
=================================

Overview
--------

- This topic combines stack parsing and O(1) cache data-structure design.
- Common interview blend: valid parentheses, expression evaluation, LRU/LFU internals.

Parentheses Patterns
--------------------

- Validation

  - Push opening brackets.
  - Match and pop on closing brackets.

- Longest valid parentheses

  - Stack of indices or DP approaches.

- Minimum add/remove to make valid

  - Track imbalance counts.

Reverse Polish Notation
-----------------------

- Evaluate postfix tokens using stack.
- On operator, pop two operands in correct order.
- Push computed result back.

Cache Design Essentials
-----------------------

- LRU Cache

  - Hash map + doubly linked list.
  - `get`/`put`: O(1)

- LFU Cache

  - Hash maps + frequency buckets (often lists).
  - Maintain minimum frequency pointer.

Complexity Snapshot
-------------------

- Parentheses/RPN: O(n)
- LRU operations: O(1)
- LFU operations: O(1) average with careful structure

Common Pitfalls
---------------

- Operand order mistakes in RPN for subtraction/division.
- Forgetting to update recently-used order in LRU on `get`.
- Incorrect min-frequency updates in LFU.

Practice Ladder
---------------

- Easy: valid parentheses, evaluate RPN.
- Medium: min remove to make valid parentheses.
- Hard: LFU cache full implementation.

Quick Recall
------------

- Parsing problems -> stack.
- O(1) cache -> hash map + linked structure.
