---

# **Day 18 — Queue + Deque: Sliding Window Maximum, First Negative in Window (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Queues and deques are fundamental linear data structures used in:

- Sliding window problems  
- BFS in graphs  
- Real‑time streaming  
- Scheduling systems  
- Rate limiting  
- Task processing  
- Monotonic queue optimizations  

Today’s goal is to master:

- Queue fundamentals  
- Deque fundamentals  
- Sliding window maximum (O(n))  
- First negative number in every window  
- Sliding window minimum  
- Fixed vs variable window patterns  
- Real interview problems  

This day builds directly on Day 16 and Day 17.

---

# **2. Queue Basics**

A queue follows **FIFO** (First In, First Out).

### **Operations**

- `push(x)`
- `pop()`
- `front()`
- `empty()`

### **C++ Implementation**

```cpp
queue<int> q;
q.push(10);
q.pop();
int x = q.front();
```

---

# **3. Deque Basics**

A deque (double‑ended queue) allows insertion and deletion from both ends.

### **Operations**

- `push_front(x)`
- `push_back(x)`
- `pop_front()`
- `pop_back()`
- `front()`
- `back()`

### **C++ Implementation**

```cpp
deque<int> dq;
dq.push_back(10);
dq.push_front(5);
dq.pop_back();
```

---

# **4. Sliding Window Maximum (Monotonic Deque)**

This is one of the most important sliding‑window problems.

---

## **4.1 Problem Statement**

Given an array and window size `k`, find the maximum in every window.

Example:

```
a = [1,3,-1,-3,5,3,6,7], k = 3
Output = [3,3,5,5,6,7]
```

---

## **4.2 Brute Force — O(nk)**  
Skip.

---

## **4.3 Optimal — Monotonic Deque (O(n))**

### **Logic**

- Maintain a deque of **indices**  
- Keep deque **decreasing** (front = max)  
- Remove:
  - Elements outside window  
  - Elements smaller than current  

### **Implementation**

```cpp
vector<int> maxSlidingWindow(vector<int>& a, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < a.size(); i++) {

        // Remove out-of-window elements
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Maintain decreasing order
        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);

        // Window formed
        if (i >= k - 1)
            ans.push_back(a[dq.front()]);
    }
    return ans;
}
```

Time: **O(n)**  
Space: **O(k)**

---

# **5. Sliding Window Minimum (Monotonic Increasing Deque)**

Just reverse the comparison.

### **Implementation**

```cpp
vector<int> minSlidingWindow(vector<int>& a, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < a.size(); i++) {

        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(a[dq.front()]);
    }
    return ans;
}
```

---

# **6. First Negative Number in Every Window**

This is a classic queue problem.

---

## **6.1 Logic**

- Use a queue to store indices of negative numbers  
- For each window:
  - Remove negatives that fall out  
  - First element in queue = first negative  

---

## **6.2 Implementation**

```cpp
vector<int> firstNegative(vector<int>& a, int k) {
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < a.size(); i++) {

        if (a[i] < 0)
            q.push(i);

        if (i >= k - 1) {
            while (!q.empty() && q.front() <= i - k)
                q.pop();

            ans.push_back(q.empty() ? 0 : a[q.front()]);
        }
    }
    return ans;
}
```

---

# **7. Count of Distinct Elements in Every Window**

Use a frequency map + sliding window.

### **Implementation**

```cpp
vector<int> distinctInWindow(vector<int>& a, int k) {
    unordered_map<int,int> freq;
    vector<int> ans;

    for (int i = 0; i < a.size(); i++) {
        freq[a[i]]++;

        if (i >= k) {
            freq[a[i-k]]--;
            if (freq[a[i-k]] == 0)
                freq.erase(a[i-k]);
        }

        if (i >= k - 1)
            ans.push_back(freq.size());
    }
    return ans;
}
```

---

# **8. Fixed vs Variable Sliding Window**

### **Fixed Window**
- Window size = constant  
- Use indices  
- Examples:
  - Sliding window max  
  - First negative  
  - Distinct elements  

### **Variable Window**
- Window expands and shrinks based on condition  
- Use two pointers  
- Examples:
  - Longest substring without repeating characters  
  - Longest subarray with sum ≤ K  
  - At most K distinct characters  

---

# **9. Real‑World Examples**

---

### **Example 1 — Real‑time sensor data**  
Sliding window max/min.

---

### **Example 2 — Network packet analysis**  
First negative / anomaly detection.

---

### **Example 3 — Stock market analytics**  
Sliding window max.

---

### **Example 4 — Rate limiting**  
Queue‑based windowing.

---

# **10. Interview‑Level Problems**

---

### **Problem 1 — Sliding Window Maximum**  
Monotonic deque.

---

### **Problem 2 — First Negative in Window**  
Queue of indices.

---

### **Problem 3 — Distinct Elements in Window**  
Hashmap + sliding window.

---

### **Problem 4 — Sliding Window Minimum**  
Monotonic deque.

---

### **Problem 5 — Longest substring with at most K distinct characters**  
Variable window.

---

# **11. Exercises (Try First)**

---

### **Exercise 1**  
Compute sliding window maximum.

---

### **Exercise 2**  
Compute sliding window minimum.

---

### **Exercise 3**  
Find first negative number in every window.

---

### **Exercise 4**  
Count distinct elements in every window.

---

### **Exercise 5**  
Given a string, find longest substring with at most K distinct characters.

---

# **12. Solutions**

---

### **Solution 1 — Sliding window max**  
Use code from section 4.

---

### **Solution 2 — Sliding window min**  
Use code from section 5.

---

### **Solution 3 — First negative**  
Use queue logic.

---

### **Solution 4 — Distinct elements**  
Use hashmap.

---

### **Solution 5 — K distinct substring**

```cpp
int longestKDistinct(string s, int k) {
    unordered_map<char,int> mp;
    int i = 0, ans = 0;

    for (int j = 0; j < s.size(); j++) {
        mp[s[j]]++;

        while (mp.size() > k) {
            mp[s[i]]--;
            if (mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }

        ans = max(ans, j - i + 1);
    }
    return ans;
}
```

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Differentiate when to use two pointers vs sliding window.
- Re-derive prefix sum query formula in O(1).
- Explain difference array update and final reconstruction.
- List edge cases: empty input, single element, all duplicates.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Off-by-one in subarray boundaries.
- Mutating array while iterating without index discipline.
- Using O(n^2) when prefix/hash can reduce to O(n).
- Ignoring overflow when summing large ranges.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: move zeroes, remove duplicates.
- Medium: longest subarray with given sum/k constraints.
- Hard: 2D prefix sum + range update mix.

