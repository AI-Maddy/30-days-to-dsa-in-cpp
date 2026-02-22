---

# **Day 17 — Monotonic Stack/Queue Patterns + Largest Rectangle in Histogram (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Monotonic stacks and queues are among the most elegant and powerful tools in algorithm design.  
They allow you to solve problems that seem impossible with brute force:

- Largest Rectangle in Histogram  
- Sliding Window Maximum  
- Next Greater/Smaller Element (advanced variants)  
- Trapping Rain Water  
- Sum of Subarray Minimums  
- Sum of Subarray Maximums  
- Removing K digits  
- Asteroid collision  
- Daily temperatures  

Today’s goal is to master:

- Monotonic stack patterns  
- Monotonic queue patterns  
- Largest Rectangle in Histogram (O(n))  
- Sliding Window Maximum (O(n))  
- Advanced NSE/NGE usage  
- Real interview problems  

This day is a major milestone — these patterns appear in DP, greedy, arrays, and even graph problems.

---

# **2. Monotonic Stack — Deep Dive**

A monotonic stack maintains elements in sorted order:

- **Increasing stack** → top is smallest  
- **Decreasing stack** → top is largest  

Used for:

- Next smaller element  
- Next greater element  
- Histogram area  
- Subarray min/max contributions  

---

## **2.1 Increasing Stack**

Top is smallest.

Used for:

- Next smaller element  
- Histogram area  
- Sum of subarray minimums  

---

## **2.2 Decreasing Stack**

Top is largest.

Used for:

- Next greater element  
- Sliding window maximum  
- Daily temperatures  

---

# **3. Largest Rectangle in Histogram (O(n))**

This is one of the most important stack problems in all of DSA.

---

## **3.1 Problem Statement**

Given heights of bars in a histogram, find the largest rectangular area.

Example:

```
[2, 1, 5, 6, 2, 3]
```

Answer: **10** (bars 5 and 6)

---

## **3.2 Brute Force — O(n²)**  
Skip.

---

## **3.3 Optimal — Monotonic Increasing Stack (O(n))**

### **Intuition**

For each bar, find:

- First smaller element to the left  
- First smaller element to the right  

These define the width where the bar is the minimum height.

### **Implementation**

```cpp
int largestRectangleArea(vector<int>& h) {
    int n = h.size();
    stack<int> st;
    int maxA = 0;

    for (int i = 0; i <= n; i++) {
        int curr = (i == n ? 0 : h[i]);

        while (!st.empty() && curr < h[st.top()]) {
            int height = h[st.top()];
            st.pop();

            int right = i;
            int left = st.empty() ? -1 : st.top();

            int width = right - left - 1;
            maxA = max(maxA, height * width);
        }
        st.push(i);
    }
    return maxA;
}
```

Time: **O(n)**  
Space: **O(n)**

---

# **4. Trapping Rain Water (Monotonic Stack Variant)**

### **Logic**

- Use stack to find boundaries  
- Water trapped = min(left, right) − height  

### **Implementation**

```cpp
int trap(vector<int>& h) {
    int n = h.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[i] > h[st.top()]) {
            int mid = st.top();
            st.pop();
            if (st.empty()) break;

            int left = st.top();
            int height = min(h[left], h[i]) - h[mid];
            int width = i - left - 1;

            ans += height * width;
        }
        st.push(i);
    }
    return ans;
}
```

---

# **5. Sum of Subarray Minimums (Advanced Monotonic Stack)**

Each element contributes as the minimum of certain subarrays.

### **Logic**

- Find previous smaller element  
- Find next smaller element  
- Contribution = value × left × right  

---

# **6. Monotonic Queue — Sliding Window Maximum (O(n))**

A monotonic queue maintains elements in decreasing order.

### **6.1 Logic**

- Remove elements smaller than current  
- Remove elements outside window  
- Front of deque = maximum  

### **Implementation**

```cpp
vector<int> maxSlidingWindow(vector<int>& a, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < a.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(a[dq.front()]);
    }
    return ans;
}
```

Time: **O(n)**  
Space: **O(k)**

---

# **7. Real‑World Examples**

---

### **Example 1 — Histogram Area**  
Used in:

- Image processing  
- Skyline problems  
- Largest rectangle in binary matrix  

---

### **Example 2 — Sliding Window Maximum**  
Used in:

- Stock market  
- Sensor data  
- Real‑time analytics  

---

### **Example 3 — Rain Water Trapping**  
Used in:

- Terrain modeling  
- Water flow simulations  

---

### **Example 4 — Subarray Minimums**  
Used in:

- DP optimization  
- Range queries  

---

# **8. Interview‑Level Problems**

---

### **Problem 1 — Largest Rectangle in Histogram**  
Monotonic increasing stack.

---

### **Problem 2 — Sliding Window Maximum**  
Monotonic deque.

---

### **Problem 3 — Trapping Rain Water**  
Stack or two‑pointer.

---

### **Problem 4 — Sum of Subarray Minimums**  
Contribution technique.

---

### **Problem 5 — Remove K Digits**  
Monotonic increasing stack.

---

# **9. Exercises (Try First)**

---

### **Exercise 1**  
Compute largest rectangle in histogram.

---

### **Exercise 2**  
Compute sliding window maximum.

---

### **Exercise 3**  
Compute trapped rain water.

---

### **Exercise 4**  
Compute sum of subarray minimums.

---

### **Exercise 5**  
Remove K digits to form smallest number.

---

# **10. Solutions**

---

### **Solution 1 — Histogram area**  
Use code from section 3.

---

### **Solution 2 — Sliding window max**  
Use monotonic deque.

---

### **Solution 3 — Rain water**  
Use stack logic.

---

### **Solution 4 — Subarray minimums**  
Use contribution technique.

---

### **Solution 5 — Remove K digits**

```cpp
string removeKdigits(string s, int k) {
    stack<char> st;

    for (char c : s) {
        while (!st.empty() && k > 0 && st.top() > c) {
            st.pop();
            k--;
        }
        st.push(c);
    }

    while (k-- > 0 && !st.empty())
        st.pop();

    string ans = "";
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    int i = 0;
    while (i < ans.size() && ans[i] == '0') i++;

    ans = ans.substr(i);
    return ans.empty() ? "0" : ans;
}
```

---

# **11. Summary**

Today you mastered:

- Monotonic stacks  
- Monotonic queues  
- Largest Rectangle in Histogram  
- Sliding Window Maximum  
- Trapping Rain Water  
- Subarray minimum/maximum contributions  
- Advanced stack patterns  

This day is a major milestone — these patterns appear in DP, greedy, arrays, and even graph problems.

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Identify monotonic stack direction from query type.
- Map nearest-greater/smaller variants quickly.
- Use deque invariants for sliding window maximum.
- Explain amortized O(1) pop/push behavior.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Pushing indices vs values inconsistently.
- Forgetting to evict out-of-window indices.
- Wrong tie-handling (`>` vs `>=`) in monotonic logic.
- Mismatched push/pop causing invalid parenthesis checks to fail.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: valid parentheses, stack using queues.
- Medium: daily temperatures, stock span.
- Hard: largest rectangle + maximal rectangle variations.

