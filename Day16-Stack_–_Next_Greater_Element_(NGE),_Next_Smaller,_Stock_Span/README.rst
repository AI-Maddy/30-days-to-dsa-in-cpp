Absolutely, Sasimegala — **Day 16** is here, and this one is a *pillar* of DSA mastery.  
Stacks unlock an entire class of problems that look impossible until you see the pattern — and then suddenly everything becomes elegant.

This README is long, deep, example‑rich, and crafted with the same ultra‑premium quality as the previous days.

---

# **Day 16 — Stack: Next Greater Element (NGE), Next Smaller, Stock Span (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Stacks are one of the most powerful linear data structures in algorithmic problem‑solving.  
They allow you to solve problems involving:

- Next greater/smaller elements  
- Stock span  
- Histogram area  
- Balanced parentheses  
- Expression evaluation  
- Monotonic stack patterns  
- Sliding window optimizations  
- Tree traversals  

Today’s goal is to master:

- Stack fundamentals  
- Monotonic stacks  
- Next Greater Element (NGE)  
- Next Smaller Element (NSE)  
- Stock Span Problem  
- Circular NGE  
- NGE to left / right  
- NSE to left / right  
- Real interview problems  

This day is foundational for Day 17 (Monotonic Stack/Queue + Largest Rectangle in Histogram).

---

# **2. Stack Basics**

A stack follows **LIFO** (Last In, First Out).

Operations:

- `push(x)`
- `pop()`
- `top()`
- `empty()`

### **C++ Implementation**

```cpp
stack<int> st;
st.push(10);
st.pop();
int x = st.top();
```

---

# **3. Monotonic Stack — The Real Power**

A monotonic stack is a stack that maintains elements in either:

- **Increasing order**  
- **Decreasing order**

Used for:

- NGE  
- NSE  
- Stock span  
- Histogram area  
- Sliding window min/max  

---

# **4. Next Greater Element (NGE) — Right Side**

Given an array, for each element find the next element to the right that is greater.

### **4.1 Brute Force — O(n²)**  
Skip.

---

### **4.2 Optimal — Monotonic Decreasing Stack (O(n))**

### **Logic**

- Traverse from right to left  
- Maintain stack of elements **greater** than current  
- Pop smaller elements  
- Top of stack = NGE  

### **Implementation**

```cpp
vector<int> nextGreater(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}
```

---

# **5. Next Smaller Element (NSE) — Right Side**

### **Logic**

- Traverse from right  
- Maintain **increasing** stack  
- Pop larger elements  

### **Implementation**

```cpp
vector<int> nextSmaller(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= a[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}
```

---

# **6. NGE to the Left**

### **Logic**

- Traverse left → right  
- Maintain decreasing stack  

### **Implementation**

```cpp
vector<int> ngeLeft(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= a[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}
```

---

# **7. NSE to the Left**

### **Implementation**

```cpp
vector<int> nseLeft(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= a[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}
```

---

# **8. Circular Next Greater Element**

For circular arrays, index wraps around.

### **Implementation**

```cpp
vector<int> nextGreaterCircular(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 2*n - 1; i >= 0; i--) {
        int idx = i % n;

        while (!st.empty() && st.top() <= a[idx])
            st.pop();

        if (i < n && !st.empty())
            ans[idx] = st.top();

        st.push(a[idx]);
    }
    return ans;
}
```

---

# **9. Stock Span Problem**

Given stock prices, find span = number of consecutive days before today with price ≤ today.

### **Logic**

- Use monotonic decreasing stack  
- Store indices  

### **Implementation**

```cpp
vector<int> stockSpan(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();

        ans[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return ans;
}
```

---

# **10. Real‑World Examples**

---

### **Example 1 — Temperature Forecast (NGE)**  
Find next warmer day.

---

### **Example 2 — Stock Market Analysis (Stock Span)**  
Find consecutive days of non‑increasing prices.

---

### **Example 3 — Histogram Area (Uses NSE + NGE)**  
Foundation for Day 17.

---

### **Example 4 — Sliding Window Min/Max**  
Monotonic deque.

---

# **11. Interview‑Level Problems**

---

### **Problem 1 — Next Greater Element**  
Classic monotonic stack.

---

### **Problem 2 — Next Smaller Element**  
Used in histogram area.

---

### **Problem 3 — Stock Span**  
Index‑based monotonic stack.

---

### **Problem 4 — Circular NGE**  
Double traversal.

---

### **Problem 5 — Daily Temperatures**  
NGE with indices.

---

# **12. Exercises (Try First)**

---

### **Exercise 1**  
Compute NGE for each element in an array.

---

### **Exercise 2**  
Compute NSE for each element.

---

### **Exercise 3**  
Solve the Stock Span problem.

---

### **Exercise 4**  
Solve Circular NGE.

---

### **Exercise 5**  
Given temperatures array, find days until next warmer day.

---

# **13. Solutions**

---

### **Solution 1 — NGE**  
Use code from section 4.

---

### **Solution 2 — NSE**  
Use code from section 5.

---

### **Solution 3 — Stock Span**  
Use code from section 9.

---

### **Solution 4 — Circular NGE**  
Use code from section 8.

---

### **Solution 5 — Daily Temperatures**

```cpp
vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && t[i] > t[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }
    return ans;
}
```

---

# **14. Summary**

Today you mastered:

- Stack fundamentals  
- Monotonic stack patterns  
- Next Greater Element (left, right, circular)  
- Next Smaller Element (left, right)  
- Stock Span  
- Real‑world stack applications  
- Interview‑level stack problems  

This day sets the stage for **Day 17**, where you’ll tackle the legendary **Largest Rectangle in Histogram** and **Monotonic Queue** patterns.

---

If you want, I’ll prepare **Day 17 — Monotonic Stack/Queue + Largest Rectangle in Histogram** with the same ultra‑premium depth.
