.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> O(1) &lt; O(log n) &lt; O(n) &lt; O(n log n) &lt; O(n²) &lt; O(2ⁿ) &lt; O(n!). </span>
      <span style="color:#0f766e;">Ask: what is n? What loop structure drives the complexity?</span>
   </div>

==============================
⏱️ Complexity Analysis Cheatsheet
==============================

----

📐 Big-O Notation
==================

Big-O describes the **worst-case upper bound** on growth rate, ignoring constants.

+------------+---------------+--------+---------+------------------------------+
| Notation   | Name          | n=100  | n=10000 | Typical usage                |
+============+===============+========+=========+==============================+
| O(1)       | Constant      | 1      | 1       | Hash lookup, array index     |
+------------+---------------+--------+---------+------------------------------+
| O(log n)   | Logarithmic   | 7      | 14      | Binary search, BST ops       |
+------------+---------------+--------+---------+------------------------------+
| O(n)       | Linear        | 100    | 10000   | Single loop, linear scan     |
+------------+---------------+--------+---------+------------------------------+
| O(n log n) | Linearithmic  | 664    | 133000  | Merge sort, heap sort        |
+------------+---------------+--------+---------+------------------------------+
| O(n²)      | Quadratic     | 10000  | 10⁸     | Nested loops, bubble sort    |
+------------+---------------+--------+---------+------------------------------+
| O(n³)      | Cubic         | 10⁶    | 10¹²    | Floyd-Warshall, 3-sum naive  |
+------------+---------------+--------+---------+------------------------------+
| O(2ⁿ)      | Exponential   | huge   | —       | Subsets brute-force          |
+------------+---------------+--------+---------+------------------------------+
| O(n!)      | Factorial     | huge   | —       | Permutations brute-force     |
+------------+---------------+--------+---------+------------------------------+

----

⚡ Common Algorithms
====================

+------------------------------+------------------+----------+
| Algorithm                    | Time             | Space    |
+==============================+==================+==========+
| Binary Search                | O(log n)         | O(1)     |
+------------------------------+------------------+----------+
| Bubble / Selection Sort      | O(n²)            | O(1)     |
+------------------------------+------------------+----------+
| Merge Sort                   | O(n log n)       | O(n)     |
+------------------------------+------------------+----------+
| Quick Sort (average)         | O(n log n)       | O(log n) |
+------------------------------+------------------+----------+
| Counting Sort                | O(n + k)         | O(k)     |
+------------------------------+------------------+----------+
| BFS / DFS                    | O(V + E)         | O(V)     |
+------------------------------+------------------+----------+
| Dijkstra (min-heap)          | O((V+E) log V)   | O(V)     |
+------------------------------+------------------+----------+
| Bellman-Ford                 | O(V × E)         | O(V)     |
+------------------------------+------------------+----------+
| Floyd-Warshall               | O(V³)            | O(V²)    |
+------------------------------+------------------+----------+
| 0-1 Knapsack DP              | O(n × W)         | O(n × W) |
+------------------------------+------------------+----------+
| LCS                          | O(m × n)         | O(m × n) |
+------------------------------+------------------+----------+

----

🔁 Master Theorem
==================

For T(n) = aT(n/b) + f(n), let c = log_b(a):

.. code-block:: text

    Case 1: f(n) = O(n^(c-ε))   →  T(n) = Θ(nᶜ)
    Case 2: f(n) = Θ(nᶜ)        →  T(n) = Θ(nᶜ log n)
    Case 3: f(n) = Ω(n^(c+ε))   →  T(n) = Θ(f(n))

    Examples:
    Merge Sort:    T(n) = 2T(n/2) + O(n)  → O(n log n)  [Case 2, c=1]
    Binary Search: T(n) = T(n/2)  + O(1)  → O(log n)    [Case 2, c=0]
    Strassen:      T(n) = 7T(n/2) + O(n²) → O(n^2.81)   [Case 1]

----

💾 Space Complexity
====================

.. code-block:: text

    O(1)      — in-place: sorting, two-pointer, sliding window
    O(log n)  — recursion stack for balanced divide-and-conquer
    O(n)      — storing output, or O(n) recursion depth (skewed tree)
    O(n²)     — 2D DP table, adjacency matrix

    Stack depth:
      Balanced BST / merge sort  → O(log n)
      Linear/skewed recursion    → O(n)

----

🎯 Estimation Rules (Interview)
================================

.. code-block:: text

    ~10⁸ simple operations per second in C++

    n ≤ 10        → O(n!) fine
    n ≤ 20        → O(2ⁿ) fine
    n ≤ 500       → O(n³) fine
    n ≤ 5000      → O(n²) fine
    n ≤ 10⁵       → O(n log n) needed
    n ≤ 10⁶       → O(n) needed
    n ≤ 10⁹       → O(log n) or O(1) only

    Rule of thumb: if time limit is 1s and n=10⁵, you need O(n log n) or better.

----

🔄 Amortized Analysis
======================

.. code-block:: text

    vector push_back  → O(1) amortized (doubles capacity when full)
    Two-pointer BFS   → O(n) amortized (each node enqueued once)
    Union-Find        → O(α(n)) amortized (path compression + rank)

    Key insight: average cost per operation over a sequence is constant,
    even if individual ops are occasionally expensive.
