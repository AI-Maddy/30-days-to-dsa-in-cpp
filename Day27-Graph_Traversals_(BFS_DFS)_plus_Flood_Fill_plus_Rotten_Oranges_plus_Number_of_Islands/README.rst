---

# **Day 27 — Dynamic Programming Basics: Memoization, Tabulation, Fibonacci, Grid Paths (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Dynamic Programming (DP) is the art of solving complex problems by breaking them into overlapping subproblems and storing results to avoid recomputation.

DP is used in:

- Optimization problems  
- Path counting  
- String algorithms  
- Tree DP  
- Graph DP  
- Probability & combinatorics  
- Machine learning foundations  

Today you will master:

- Recursion → Memoization → Tabulation  
- Fibonacci (the gateway to DP)  
- Climbing stairs  
- Grid paths  
- Minimum cost path  
- Understanding DP states  
- Time & space optimization  

This day sets the foundation for Days 28–30 (Advanced DP: LIS, Knapsack, DP on Trees, DP on Graphs).

---

# **2. What Is Dynamic Programming?**

DP applies when:

1. **Overlapping subproblems**  
2. **Optimal substructure**  

Example: Fibonacci  
`f(n) = f(n-1) + f(n-2)`  
Subproblems repeat → perfect for DP.

---

# **3. Recursion (Brute Force)**

Fibonacci using plain recursion:

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

Time: **O(2ⁿ)**  
Space: **O(n)** recursion stack  
Terrible for large n.

---

# **4. Memoization (Top‑Down DP)**

Store results in a dp array.

```cpp
int fibMemo(int n, vector<int>& dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
}
```

Usage:

```cpp
vector<int> dp(n+1, -1);
fibMemo(n, dp);
```

Time: **O(n)**  
Space: **O(n)**

---

# **5. Tabulation (Bottom‑Up DP)**

Iterative DP.

```cpp
int fibTab(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}
```

Time: **O(n)**  
Space: **O(n)**

---

# **6. Space‑Optimized Fibonacci**

Only last two values needed.

```cpp
int fibOpt(int n) {
    if (n <= 1) return n;

    int prev2 = 0, prev1 = 1;

    for (int i = 2; i <= n; i++) {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
```

Space: **O(1)**

---

# **7. Climbing Stairs (Classic DP)**

You can climb 1 or 2 steps.

```
ways(n) = ways(n-1) + ways(n-2)
```

Same as Fibonacci.

---

## **7.1 Memoization**

```cpp
int climb(int n, vector<int>& dp) {
    if (n <= 2) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = climb(n-1, dp) + climb(n-2, dp);
}
```

---

# **8. Grid Paths (m x n Grid)**

You can move:

- Right  
- Down  

Number of ways to reach bottom‑right.

---

## **8.1 Recursion**

```cpp
int ways(int i, int j) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    return ways(i-1, j) + ways(i, j-1);
}
```

---

## **8.2 Memoization**

```cpp
int ways(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = ways(i-1, j, dp) + ways(i, j-1, dp);
}
```

---

## **8.3 Tabulation**

```cpp
int gridWays(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;

            int up = (i > 0) ? dp[i-1][j] : 0;
            int left = (j > 0) ? dp[i][j-1] : 0;

            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}
```

---

# **9. Minimum Cost Path (Grid)**

Each cell has a cost.  
Find minimum cost to reach bottom‑right.

---

## **9.1 Tabulation**

```cpp
int minCost(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    dp[0][0] = a[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) continue;

            int up = (i > 0) ? dp[i-1][j] : INT_MAX;
            int left = (j > 0) ? dp[i][j-1] : INT_MAX;

            dp[i][j] = a[i][j] + min(up, left);
        }
    }
    return dp[m-1][n-1];
}
```

---

# **10. Understanding DP State Design**

DP problems follow a pattern:

1. **Define state**  
   `dp[i] = answer for subproblem i`

2. **Define recurrence**  
   `dp[i] = f(dp[i-1], dp[i-2], ...)`

3. **Base cases**  
   `dp[0], dp[1]`

4. **Compute answer**  
   Either top‑down or bottom‑up.

---

# **11. Real‑World Examples**

### **Example 1 — Robot Grid Paths**  
Navigation systems.

### **Example 2 — Finance**  
DP for stock trading.

### **Example 3 — Bioinformatics**  
Sequence alignment (edit distance).

### **Example 4 — Machine Learning**  
Viterbi algorithm.

---

# **12. Interview‑Level Problems**

### **Problem 1 — Fibonacci**  
Memo + tabulation.

### **Problem 2 — Climbing stairs**  
Same recurrence.

### **Problem 3 — Grid paths**  
2D DP.

### **Problem 4 — Minimum cost path**  
Weighted grid DP.

### **Problem 5 — Unique paths with obstacles**  
DP with blocked cells.

---

# **13. Exercises (Try First)**

### **Exercise 1**  
Implement Fibonacci using memoization.

### **Exercise 2**  
Implement Fibonacci using tabulation.

### **Exercise 3**  
Solve climbing stairs.

### **Exercise 4**  
Count grid paths in m x n grid.

### **Exercise 5**  
Compute minimum cost path in a grid.

---

# **14. Solutions**

Use the implementations from sections 4–9.

---
