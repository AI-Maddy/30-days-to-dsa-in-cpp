---

# **Day 29 — Greedy Algorithms Revision: Activity Selection, Fractional Knapsack, Jump Game Variants (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Greedy algorithms make decisions that are **locally optimal** at each step, hoping to achieve a **globally optimal** solution.

They are used in:

- Scheduling  
- Resource allocation  
- Optimization  
- Graph algorithms (Prim, Kruskal, Dijkstra)  
- Jump game problems  
- Interval problems  
- Knapsack variants  

Today you will master:

- Core greedy strategy  
- Activity Selection (Interval Scheduling)  
- Fractional Knapsack  
- Jump Game I (Reachability)  
- Jump Game II (Minimum jumps)  
- When greedy works and when it fails  

This day is essential for building intuition for optimization problems.

---

# **2. Greedy Algorithm Fundamentals**

A greedy algorithm must satisfy:

### **2.1 Greedy Choice Property**  
A local optimal choice leads to a global optimal solution.

### **2.2 Optimal Substructure**  
Optimal solution contains optimal sub‑solutions.

Not all problems satisfy these — e.g., 0/1 Knapsack fails greedy.

---

# **3. Activity Selection Problem (Interval Scheduling)**

Given start and end times, select the maximum number of non‑overlapping activities.

### **Greedy Strategy**  
Always pick the activity that **finishes earliest**.

---

## **3.1 Sort by Finish Time**

```cpp
int activitySelection(vector<pair<int,int>>& a) {
    sort(a.begin(), a.end(), [](auto &x, auto &y){
        return x.second < y.second;
    });

    int count = 1;
    int lastEnd = a[0].second;

    for (int i = 1; i < a.size(); i++) {
        if (a[i].first >= lastEnd) {
            count++;
            lastEnd = a[i].second;
        }
    }
    return count;
}
```

Time: **O(n log n)**  
Space: **O(1)**

---

# **4. Fractional Knapsack**

You can take fractions of items.  
Goal: maximize value under weight capacity.

### **Greedy Strategy**  
Pick items with **highest value/weight ratio** first.

---

## **4.1 Implementation**

```cpp
double fractionalKnapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<pair<double,int>> ratio;

    for (int i = 0; i < n; i++)
        ratio.push_back({(double)val[i] / wt[i], i});

    sort(ratio.rbegin(), ratio.rend());

    double total = 0;

    for (auto &p : ratio) {
        int idx = p.second;

        if (wt[idx] <= W) {
            total += val[idx];
            W -= wt[idx];
        } else {
            total += p.first * W;
            break;
        }
    }
    return total;
}
```

Time: **O(n log n)**  
Space: **O(n)**

---

# **5. Jump Game Variants**

These are classic greedy problems.

---

# **5.1 Jump Game I — Can You Reach the End?**

Given array `nums`, each element is max jump length.  
Return true if you can reach last index.

### **Greedy Strategy**  
Track the **farthest reachable index**.

---

## **Implementation**

```cpp
bool canJump(vector<int>& a) {
    int reach = 0;

    for (int i = 0; i < a.size(); i++) {
        if (i > reach) return false;
        reach = max(reach, i + a[i]);
    }
    return true;
}
```

Time: **O(n)**  
Space: **O(1)**

---

# **5.2 Jump Game II — Minimum Number of Jumps**

Find minimum jumps to reach the end.

### **Greedy Strategy**  
Use a sliding window of reachable indices.

- `farthest` = farthest index reachable in current window  
- `end` = boundary of current jump  
- When `i == end`, increment jumps and update window  

---

## **Implementation**

```cpp
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
```

Time: **O(n)**  
Space: **O(1)**

---

# **6. When Greedy Works (and When It Fails)**

### **Works perfectly for:**

- Activity selection  
- Fractional knapsack  
- Jump game I & II  
- Scheduling  
- Interval problems  
- MST (Prim/Kruskal)  
- Dijkstra (non‑negative weights)

### **Fails for:**

- 0/1 Knapsack  
- Longest increasing subsequence  
- Edit distance  
- DP problems with overlapping subproblems  

Greedy is powerful but must be applied carefully.

---

# **7. Real‑World Examples**

### **Example 1 — Meeting Room Scheduling**  
Activity selection.

### **Example 2 — Resource Allocation**  
Fractional knapsack.

### **Example 3 — Game Level Reachability**  
Jump game.

### **Example 4 — Network Routing**  
Greedy shortest path (Dijkstra).

---

# **8. Interview‑Level Problems**

### **Problem 1 — Activity Selection**  
Sort by finish time.

### **Problem 2 — Fractional Knapsack**  
Sort by ratio.

### **Problem 3 — Jump Game I**  
Track farthest reach.

### **Problem 4 — Jump Game II**  
Greedy window expansion.

### **Problem 5 — Minimum Platforms**  
Greedy interval merging.

---

# **9. Exercises (Try First)**

### **Exercise 1**  
Solve Activity Selection for given intervals.

### **Exercise 2**  
Solve Fractional Knapsack.

### **Exercise 3**  
Check if you can reach the end (Jump Game I).

### **Exercise 4**  
Find minimum jumps (Jump Game II).

### **Exercise 5**  
Solve Minimum Platforms using greedy.

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Pick sorting stability based on requirement.
- For greedy, prove local choice with exchange argument.
- Know comparator rules and strict weak ordering.
- Validate counting/radix sort constraints on key range.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Broken custom comparator causing undefined behavior.
- Using greedy where DP is required.
- Forgetting integer overflow in counting indexes.
- Ignoring tie-breaks in activity-selection style problems.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: selection/insertion sort dry runs.
- Medium: interval merge, activity selection.
- Hard: jump game variants with formal greedy proof.

