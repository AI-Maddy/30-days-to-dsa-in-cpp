Day 30 — 1D DP Patterns + Mini‑Revision + Mixed Medium/Hard Problems
======================================================================

*30 Days to DSA in C++ — Ultra‑Premium Edition*

1. Introduction
---------------

You've reached the final day — and today is all about **consolidation + mastery**.

Dynamic Programming is not about memorizing formulas.
It's about recognizing **patterns**.

Today you will:

- Revisit the most important **1D DP patterns**
- Understand how to convert problems into DP states
- Solve a curated set of **medium/hard DP problems**
- Learn how to identify the right recurrence
- Practice space optimization
- Build confidence for real interviews

This day transforms your DP intuition from "I can solve some DP problems" to "I can solve ANY DP problem."

2. Mini‑Revision: Core 1D DP Patterns
---------------------------------------

These patterns appear in 80% of interview DP problems.

2.1 Pattern 1 — Pick / Not Pick (House Robber Pattern)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Used in:

- House Robber
- Max sum non‑adjacent
- Delete and Earn
- Stickers to Spell Word

General recurrence::

    dp[i] = max(dp[i-1], value[i] + dp[i-2])

2.2 Pattern 2 — Running Best (Kadane‑Style)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Used in:

- Maximum subarray
- Best time to buy/sell stock
- Maximum circular subarray

General idea::

    bestEndingHere = max(a[i], a[i] + bestEndingHere)
    bestSoFar = max(bestSoFar, bestEndingHere)

2.3 Pattern 3 — Prefix DP (Cumulative Decisions)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Used in:

- Jump Game II
- Partitioning problems
- DP on prefix sums

2.4 Pattern 4 — Increasing Sequence DP (LIS Pattern)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Used in:

- LIS
- Russian Doll Envelopes
- Box stacking
- Maximum chain length

General recurrence::

    dp[i] = 1 + max(dp[j]) for all j < i where condition holds

2.5 Pattern 5 — Target DP (Subset Sum / Knapsack)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Used in:

- Subset sum
- Partition equal subset sum
- Target sum
- Coin change
- Rod cutting

General recurrence::

    dp[t] = dp[t] OR dp[t - a[i]]

3. Mixed Medium/Hard Problems (With Patterns)
----------------------------------------------

This section is the heart of Day 30 — solving real interview problems using the patterns above.

3.1 Problem 1 — Jump Game II (Greedy + DP Thinking)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Pattern:** Prefix DP / Greedy window

**Difficulty:** Medium

.. code-block:: cpp

    int jump(vector<int>& a) {
        int jumps = 0, end = 0, farthest = 0;

        for (int i = 0; i < a.size() - 1; i++) {
            farthest = max(farthest, i + a[i]);
            if (i == end) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }

3.2 Problem 2 — Delete and Earn (House Robber Variant)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Pattern:** Pick / Not Pick

**Difficulty:** Medium

.. code-block:: cpp

    int deleteAndEarn(vector<int>& a) {
        int maxVal = *max_element(a.begin(), a.end());
        vector<int> sum(maxVal+1, 0);

        for (int x : a)
            sum[x] += x;

        int prev2 = 0, prev1 = sum[1];

        for (int i = 2; i <= maxVal; i++) {
            int pick = sum[i] + prev2;
            int skip = prev1;
            int cur = max(pick, skip);

            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

3.3 Problem 3 — Coin Change (Minimum Coins)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Pattern:** Target DP

**Difficulty:** Medium

.. code-block:: cpp

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;

        for (int c : coins) {
            for (int t = c; t <= amount; t++)
                dp[t] = min(dp[t], 1 + dp[t - c]);
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }

3.4 Problem 4 — Longest Increasing Subsequence (O(n log n))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Pattern:** Increasing Sequence DP

**Difficulty:** Medium/Hard

.. code-block:: cpp

    int LIS(vector<int>& a) {
        vector<int> temp;

        for (int x : a) {
            auto it = lower_bound(temp.begin(), temp.end(), x);
            if (it == temp.end())
                temp.push_back(x);
            else
                *it = x;
        }
        return temp.size();
    }

3.5 Problem 5 — Maximum Product Subarray
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Pattern:** Running Best (Kadane variant)

**Difficulty:** Medium

.. code-block:: cpp

    int maxProduct(vector<int>& a) {
        int curMax = a[0], curMin = a[0], ans = a[0];

        for (int i = 1; i < a.size(); i++) {
            if (a[i] < 0) swap(curMax, curMin);

            curMax = max(a[i], curMax * a[i]);
            curMin = min(a[i], curMin * a[i]);

            ans = max(ans, curMax);
        }
        return ans;
    }

3.6 Problem 6 — Partition Equal Subset Sum
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Pattern:** Target DP

**Difficulty:** Medium

.. code-block:: cpp

    bool canPartition(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % 2) return false;

        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int x : a) {
            for (int t = target; t >= x; t--)
                dp[t] = dp[t] || dp[t - x];
        }
        return dp[target];
    }

3.7 Problem 7 — House Robber II (Circular Variant)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Pattern:** Pick / Not Pick

**Difficulty:** Medium

.. code-block:: cpp

    int robLinear(vector<int>& a) {
        int prev2 = 0, prev1 = 0;
        for (int x : a) {
            int cur = max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    int rob(vector<int>& a) {
        if (a.size() == 1) return a[0];
        vector<int> v1(a.begin(), a.end()-1);
        vector<int> v2(a.begin()+1, a.end());
        return max(robLinear(v1), robLinear(v2));
    }

4. How to Recognize DP Patterns in Interviews
----------------------------------------------

4.1 If the problem involves:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Choosing or skipping → **Pick/Not Pick DP**
- Increasing sequences → **LIS DP**
- Minimizing/maximizing subarray → **Kadane DP**
- Reaching a target → **Subset/Knapsack DP**
- Steps or jumps → **Prefix DP**
- Repeated subproblems → **Memoization**

4.2 If greedy fails → DP is usually the answer
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

5. Final Revision Checklist
----------------------------

You should now be able to solve:

- House Robber I & II
- LIS (O(n²) and O(n log n))
- Coin Change I & II
- Partition Equal Subset Sum
- Jump Game I & II
- Maximum Subarray
- Maximum Product Subarray
- Delete and Earn
- Rod Cutting
- Climbing Stairs
- Grid Paths
- Minimum Cost Path

If you can solve these confidently, your DP foundation is rock‑solid.


.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Define state clearly: index + decision context.
- Write recursion first, then memoize, then tabulate.
- Validate transition with small hand-worked example.
- Optimize space only after correctness is stable.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- State missing one variable causing wrong reuse.
- Incorrect base conditions in memo table.
- Iteration order mismatch in tabulation.
- Premature optimization before proving recurrence.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: climbing stairs, house robber.
- Medium: knapsack variants, partition equal subset.
- Hard: digit DP / bitmask DP transition-heavy tasks.

