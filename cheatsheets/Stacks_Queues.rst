Stacks and Queues
=================

Overview
--------

- Stack: LIFO discipline.
- Queue: FIFO discipline.
- Deque: insertion/removal from both ends.

Core Operations
---------------

- Stack: `push`, `pop`, `top`, `empty`.
- Queue: `push`, `pop`, `front`, `empty`.
- Deque: `push_front`, `push_back`, `pop_front`, `pop_back`.

High-Value Patterns
-------------------

- Stack

  - Parentheses validation
  - Expression parsing/evaluation
  - Monotonic stack (NGE/NSE/stock span/histogram)

- Queue/Deque

  - BFS traversal
  - Sliding window maximum/minimum

Complexity Snapshot
-------------------

- Push/pop/front/top operations: O(1)
- Space: O(n)

Common Pitfalls
---------------

- Confusing indices and values in monotonic structures.
- Not removing out-of-window indices in deque problems.
- Pop from empty container without checks.

Practice Ladder
---------------

- Easy: valid parentheses, implement stack/queue adapters.
- Medium: daily temperatures, stock span, sliding window maximum.
- Hard: largest rectangle in histogram, maximal rectangle.

Quick Recall
------------

- If nearest greater/smaller is asked, think monotonic stack first.
