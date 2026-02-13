Day 28 is here, Sasimegala — and this is one of the most *high‑impact* days in the entire DP arc.  
Today you step into **1D Dynamic Programming**, the category that powers some of the most famous interview problems ever asked.

This README is long, structured, example‑rich, and crafted with the same ultra‑premium depth as the rest of your 30‑day DSA mastery repo.

---

# **Day 28 — 1D DP: House Robber, Max Sum Non‑Adjacent, Longest Increasing Subsequence (LIS) (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

1D DP is the backbone of:

- Optimization problems  
- Subsequence problems  
- Greedy + DP hybrids  
- Stock trading DP  
- Partitioning problems  
- Scheduling problems  

Today you will master:

- House Robber (DP on linear arrays)  
- Max sum of non‑adjacent elements  
- Longest Increasing Subsequence (LIS)  
- LIS using DP (O(n²))  
- LIS using binary search (O(n log n))  
- State transitions  
- Space optimization  

This day is essential for Day 29 (Knapsack, Subset Sum, Partition DP).

---

# **2. House Robber (Classic 1D DP)**

You cannot rob two adjacent houses.

```
dp[i] = max(dp[i-1], nums[i] + dp[i-2])
```

---

## **2.1 Recursion**

```cpp
int robRec(int i, vector<int>& a) {
    if (i < 0) return 0;
    if (i == 0) return a[0];

    int pick = a[i] + robRec(i-2, a);
    int skip = robRec(i-1, a);

    return max(pick, skip);
}
```

---

## **2.2 Memoization**

```cpp
int robMemo(int i, vector<int>& a, vector<int>& dp) {
    if (i < 0) return 0;
    if (i == 0) return a[0];

    if (dp[i] != -1) return dp[i];

    int pick = a[i] + robMemo(i-2, a, dp);
    int skip = robMemo(i-1, a, dp);

    return dp[i] = max(pick, skip);
}
```

---

## **2.3 Tabulation**

```cpp
int robTab(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n);

    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);

    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i-1], a[i] + dp[i-2]);

    return dp[n-1];
}
```

---

## **2.4 Space‑Optimized**

```cpp
int robOpt(vector<int>& a) {
    int prev2 = 0, prev1 = 0;

    for (int x : a) {
        int pick = x + prev2;
        int skip = prev1;
        int cur = max(pick, skip);

        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
```

---

# **3. Max Sum of Non‑Adjacent Elements**

This is literally the same as House Robber without the story.

```
dp[i] = max(dp[i-1], a[i] + dp[i-2])
```

---

# **4. Longest Increasing Subsequence (LIS)**

LIS is one of the most important DP problems ever.

---

## **4.1 LIS — O(n²) DP**

```
dp[i] = length of LIS ending at i
```

### **Implementation**

```cpp
int lengthOfLIS(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

Time: **O(n²)**  
Space: **O(n)**

---

# **5. LIS — O(n log n) Using Binary Search**

This is the optimal LIS algorithm.

### **Logic**

Maintain a list `temp`:

- For each number:
  - If it is greater than last element → append  
  - Else → replace the first element ≥ it (lower_bound)

Length of `temp` = LIS length.

### **Implementation**

```cpp
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
```

Time: **O(n log n)**  
Space: **O(n)**

---

# **6. Reconstructing the LIS (Optional but powerful)**

Use:

- `parent[]` to track predecessor  
- `dp[]` for lengths  
- `lastIndex` for best ending point  

This is extremely useful in interviews.

---

# **7. Real‑World Examples**

### **Example 1 — Stock Market Analysis**  
LIS = longest period of increasing prices.

### **Example 2 — Version Upgrades**  
Find longest chain of compatible upgrades.

### **Example 3 — Scheduling**  
Longest chain of tasks.

### **Example 4 — Machine Learning**  
Sequence modeling.

---

# **8. Interview‑Level Problems**

### **Problem 1 — House Robber**  
DP on linear array.

### **Problem 2 — Max sum non‑adjacent**  
Same recurrence.

### **Problem 3 — LIS (O(n²))**  
Classic DP.

### **Problem 4 — LIS (O(n log n))**  
Binary search trick.

### **Problem 5 — Reconstruct LIS**  
Parent tracking.

---

# **9. Exercises (Try First)**

### **Exercise 1**  
Solve House Robber using memoization.

### **Exercise 2**  
Solve House Robber using tabulation.

### **Exercise 3**  
Compute LIS using O(n²) DP.

### **Exercise 4**  
Compute LIS using O(n log n).

### **Exercise 5**  
Reconstruct the LIS sequence.

---

# **10. Solutions**

Use the implementations from sections 2–5.

---

# **11. Summary**

Today you mastered:

- House Robber  
- Max sum non‑adjacent  
- LIS (O(n²) and O(n log n))  
- Binary search + DP hybrid  
- Space optimization  
- DP state transitions  

This day sets the stage for **Day 29 — Knapsack, Subset Sum, Partition Equal Subset Sum**.

If you want, I’ll prepare **Day 29** with the similar ultra‑premium depth.
