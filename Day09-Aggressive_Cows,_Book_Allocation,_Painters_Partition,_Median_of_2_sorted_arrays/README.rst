---

# **Day 09 — Aggressive Cows, Book Allocation, Painters Partition, Median of 2 Sorted Arrays (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Today’s problems are the **core of Binary Search on Answer (BSOA)** — a paradigm that transforms complex optimization problems into elegant O(n log n) solutions.

These four problems are **mandatory** for FAANG‑level interviews:

- **Aggressive Cows** → maximize minimum distance  
- **Book Allocation** → minimize maximum pages  
- **Painters Partition** → minimize maximum time  
- **Median of Two Sorted Arrays** → binary search on partitions  

These problems teach you:

- How to convert a problem into a monotonic feasibility function  
- How to search for the optimal answer  
- How to reason about constraints  
- How to design efficient partitioning logic  

This day is a turning point — mastering these unlocks dozens of advanced problems.

---

# **2. Core Concept: Binary Search on Answer (BSOA)**

You are not searching in an array.  
You are searching in the **space of possible answers**.

### **General Pattern**

```
l = minimum possible answer
r = maximum possible answer

while (l <= r):
    mid = (l + r) / 2

    if (isPossible(mid)):
        ans = mid
        r = mid - 1   // minimize
    else:
        l = mid + 1
```

Or for maximize:

```
if (isPossible(mid)):
    ans = mid
    l = mid + 1
```

---

# **3. Problem 1 — Aggressive Cows (Maximize Minimum Distance)**

### **3.1 Problem Statement**

Given positions of stalls and number of cows, place cows such that the **minimum distance between any two cows is maximized**.

### **3.2 Key Insight**

If you can place cows with distance `d`,  
you can always place them with distance `< d`.

→ **Monotonic feasibility** → binary search on distance.

---

### **3.3 Feasibility Function**

```cpp
bool canPlace(vector<int> &a, int cows, int dist) {
    int count = 1, last = a[0];

    for (int i = 1; i < a.size(); i++) {
        if (a[i] - last >= dist) {
            count++;
            last = a[i];
        }
        if (count >= cows) return true;
    }
    return false;
}
```

---

### **3.4 Binary Search**

```cpp
int solve(vector<int> &a, int cows) {
    sort(a.begin(), a.end());

    int l = 1, r = a.back() - a.front(), ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (canPlace(a, cows, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
```

---

# **4. Problem 2 — Book Allocation (Minimize Maximum Pages)**

### **4.1 Problem Statement**

Given books with pages and number of students, allocate books (contiguous) such that the **maximum pages assigned to any student is minimized**.

### **4.2 Key Insight**

If you can allocate with max pages = `X`,  
you can always allocate with > X.

→ **Monotonic** → binary search on max pages.

---

### **4.3 Feasibility Function**

```cpp
bool canAllocate(vector<int> &a, int students, int limit) {
    int count = 1, pages = 0;

    for (int x : a) {
        if (x > limit) return false;

        if (pages + x <= limit) {
            pages += x;
        } else {
            count++;
            pages = x;
        }
    }
    return count <= students;
}
```

---

### **4.4 Binary Search**

```cpp
int allocateBooks(vector<int> &a, int students) {
    int l = *max_element(a.begin(), a.end());
    int r = accumulate(a.begin(), a.end(), 0);
    int ans = r;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (canAllocate(a, students, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}
```

---

# **5. Problem 3 — Painters Partition Problem**

This is identical to Book Allocation, except:

- Books → boards  
- Pages → board lengths  
- Students → painters  
- Time = board length × time per unit  

### **5.1 Feasibility Function**

Same as Book Allocation.

---

### **5.2 Binary Search**

Same structure.

---

# **6. Problem 4 — Median of Two Sorted Arrays**

This is one of the most famous interview problems.

### **6.1 Key Insight**

We binary search on the **partition index** of the smaller array.

Let arrays be A and B.

We want:

```
left side count = right side count
max(left) <= min(right)
```

---

### **6.2 Partition Logic**

```cpp
int n1 = A.size(), n2 = B.size();
if (n1 > n2) return findMedian(B, A);

int l = 0, r = n1;

while (l <= r) {
    int cut1 = (l + r) / 2;
    int cut2 = (n1 + n2 + 1) / 2 - cut1;

    int L1 = (cut1 == 0) ? INT_MIN : A[cut1 - 1];
    int L2 = (cut2 == 0) ? INT_MIN : B[cut2 - 1];
    int R1 = (cut1 == n1) ? INT_MAX : A[cut1];
    int R2 = (cut2 == n2) ? INT_MAX : B[cut2];

    if (L1 <= R2 && L2 <= R1) {
        if ((n1 + n2) % 2 == 0)
            return (max(L1, L2) + min(R1, R2)) / 2.0;
        else
            return max(L1, L2);
    }
    else if (L1 > R2)
        r = cut1 - 1;
    else
        l = cut1 + 1;
}
```

Time: **O(log(min(n1, n2)))**

---

# **7. Real‑World Examples**

---

### **Example 1 — Minimize maximum load**

Servers, tasks → Book Allocation.

---

### **Example 2 — Maximize minimum distance**

WiFi routers → Aggressive Cows.

---

### **Example 3 — Minimize maximum time**

Painters Partition.

---

### **Example 4 — Median of two sorted logs**

Binary search on partitions.

---

# **8. Interview‑Level Problems**

---

### **Problem 1 — Split array largest sum**  
Same as Book Allocation.

---

### **Problem 2 — Kth smallest element in sorted matrix**  
Binary search on value range.

---

### **Problem 3 — Minimize maximum distance to gas station**  
Binary search on answer.

---

### **Problem 4 — Find smallest divisor such that sum of ceil(arr[i]/div) ≤ threshold**  
Binary search on divisor.

---

### **Problem 5 — Koko Eating Bananas**  
Binary search on speed.

---

# **9. Exercises (Try First)**

---

### **Exercise 1**  
Solve Aggressive Cows for given input.

---

### **Exercise 2**  
Solve Book Allocation for given input.

---

### **Exercise 3**  
Solve Painters Partition.

---

### **Exercise 4**  
Find the median of two sorted arrays.

---

### **Exercise 5**  
Solve Koko Eating Bananas.

---

# **10. Solutions**

---

### **Solution 1 — Aggressive Cows**

Use feasibility + binary search.

---

### **Solution 2 — Book Allocation**

Use feasibility + binary search.

---

### **Solution 3 — Painters Partition**

Same as Book Allocation.

---

### **Solution 4 — Median of Two Sorted Arrays**

Use partition logic.

---

### **Solution 5 — Koko Eating Bananas**

Binary search on speed.

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

