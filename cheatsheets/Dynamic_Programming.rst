.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> DP = overlapping subproblems + optimal substructure. State → Transition → Base Case. </span>
      <span style="color:#0f766e;">Write recurrence first, then code. Optimize space last.</span>
   </div>

==============================
💡 Dynamic Programming Cheatsheet
==============================

----

🧠 DP Mental Model
==================

.. code-block:: text

    1. Define state: dp[i] = ?  (what does it represent?)
    2. Write transition: dp[i] = f(dp[i-1], dp[i-2], ...)
    3. Set base cases: dp[0], dp[1], ...
    4. Answer: usually dp[n] or max/min over dp

    Memoization (top-down) vs Tabulation (bottom-up):
    - Memoization: natural recursion + cache (map or array)
    - Tabulation: iterative, usually faster in practice

----

🔢 1D DP Patterns
==================

.. code-block:: cpp

    // Fibonacci — O(n) time O(1) space
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) { int c = a + b; a = b; b = c; }
        return b;
    }

    // Climbing Stairs (1 or 2 steps): same as Fibonacci
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) { int c = a + b; a = b; b = c; }
        return b;
    }

    // House Robber — max sum with no two adjacent
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int x : nums) {
            int cur = max(prev1, prev2 + x);
            prev2 = prev1; prev1 = cur;
        }
        return prev1;
    }

    // Coin Change — minimum coins to make amount
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (int c : coins)
                if (c <= i) dp[i] = min(dp[i], dp[i - c] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }

----

📈 Longest Increasing Subsequence (LIS)
========================================

.. code-block:: cpp

    // O(n²) DP
    int lisDP(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    // O(n log n) patience sort
    int lisOpt(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return tails.size();
    }

----

🔡 Longest Common Subsequence (LCS)
=====================================

.. code-block:: cpp

    int lcs(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        return dp[m][n];
    }

    // Space-optimized: O(min(m,n))
    int lcsOpt(string s, string t) {
        if (s.size() > t.size()) swap(s, t);
        int m = s.size(), n = t.size();
        vector<int> prev(m+1,0), curr(m+1,0);
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                if (t[j-1] == s[i-1]) curr[i] = prev[i-1] + 1;
                else curr[i] = max(prev[i], curr[i-1]);
            }
            swap(prev, curr);
        }
        return prev[m];
    }

----

🎒 0-1 Knapsack
================

.. code-block:: cpp

    // dp[i][w] = max value using first i items with capacity w
    int knapsack(vector<int>& weights, vector<int>& values, int W) {
        int n = weights.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        for (int i = 1; i <= n; i++)
            for (int w = 0; w <= W; w++) {
                dp[i][w] = dp[i-1][w];
                if (weights[i-1] <= w)
                    dp[i][w] = max(dp[i][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            }
        return dp[n][W];
    }

    // Space-optimized: O(W)
    int knapsackOpt(vector<int>& weights, vector<int>& values, int W) {
        vector<int> dp(W+1, 0);
        for (int i = 0; i < (int)weights.size(); i++)
            for (int w = W; w >= weights[i]; w--)  // reverse to avoid reuse
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        return dp[W];
    }

----

✏️ Edit Distance
=================

.. code-block:: cpp

    int editDistance(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        return dp[m][n];
    }

----

💡 Space Optimization Pattern
===============================

.. code-block:: cpp

    // If dp[i] only depends on dp[i-1]: use two rolling arrays
    // If dp[i] only depends on dp[i-1] and a single value: use two variables

    // Example: Knapsack 1D uses reverse iteration to avoid overwriting
    // Example: LCS uses two rows (prev, curr)
    // Example: Fibonacci uses two variables (a, b)
