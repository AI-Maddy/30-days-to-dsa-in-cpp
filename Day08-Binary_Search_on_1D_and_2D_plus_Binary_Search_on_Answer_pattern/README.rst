---

# **Day 08 — Binary Search on 1D & 2D + Binary Search on Answer Pattern (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Binary Search is far more than just searching in a sorted array.  
It is a **paradigm** that powers some of the most important DSA problems:

- Searching in sorted arrays  
- Searching in sorted 2D matrices  
- Searching on monotonic functions  
- Searching on the answer (min/max feasible value)  
- Optimization problems (minimize max, maximize min)  
- Allocation problems (books, painters, cows)  
- Median of two sorted arrays  

Today’s goal is to master:

- Classic binary search  
- Binary search on 2D matrices  
- Binary search on monotonic predicates  
- Binary search on answer  
- Feasibility functions  
- Real interview problems  

This is one of the most important days in the entire 30‑day plan.

---

## **2. Classic Binary Search (1D Array)**

Binary search works on **sorted** arrays.

### **2.1 Iterative Implementation**

```cpp
int binarySearch(vector<int> &arr, int target) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```

---

### **2.2 Recursive Implementation**

```cpp
int bs(vector<int> &arr, int l, int r, int target) {
    if (l > r) return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return bs(arr, mid + 1, r, target);
    return bs(arr, l, mid - 1, target);
}
```

---

## **3. Lower Bound & Upper Bound**

### **3.1 lower_bound()**
Returns first index where `arr[i] >= x`.

### **3.2 upper_bound()**
Returns first index where `arr[i] > x`.

### **Example**

```cpp
auto it = lower_bound(arr.begin(), arr.end(), x);
int idx = it - arr.begin();
```

---

## **4. Binary Search on 2D Matrix**

---

### **4.1 Case 1 — Each row sorted, each column sorted (Staircase Search)**

Start at top‑right:

```cpp
int i = 0, j = m - 1;

while (i < n && j >= 0) {
    if (mat[i][j] == target) return true;
    else if (mat[i][j] > target) j--;
    else i++;
}
```

Time: O(n + m)

---

### **4.2 Case 2 — Fully sorted matrix (Binary Search)**

Matrix property:

- Each row sorted  
- First element of each row > last element of previous row  

Treat matrix as 1D:

```cpp
int l = 0, r = n*m - 1;

while (l <= r) {
    int mid = (l + r) / 2;
    int val = mat[mid / m][mid % m];

    if (val == target) return true;
    else if (val < target) l = mid + 1;
    else r = mid - 1;
}
```

Time: O(log(n*m))

---

## **5. Binary Search on Answer — The Real Power**

This is the most important concept of the day.

Used when:

- Search space is monotonic  
- Answer lies in a range  
- You can check feasibility in O(n)  

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

---

## **6. Classic Binary Search on Answer Problems**

---

### **6.1 Find the smallest number whose square ≥ X**

```cpp
long long l = 0, r = 1e9, ans = -1;

while (l <= r) {
    long long mid = (l + r) / 2;

    if (mid * mid >= x) {
        ans = mid;
        r = mid - 1;
    } else {
        l = mid + 1;
    }
}
```

---

### **6.2 Minimum capacity to ship packages within D days**

Feasibility:  
Check if capacity `mid` can ship all packages in ≤ D days.

---

### **6.3 Allocate books (Minimize max pages)**

Feasibility:  
Check if `mid` pages per student is possible.

---

### **6.4 Aggressive Cows (Maximize minimum distance)**

Feasibility:  
Check if cows can be placed with at least `mid` distance.

---

### **6.5 Painters Partition Problem**

Feasibility:  
Check if painters can paint within `mid` time.

---

## **7. Real‑World Examples**

---

### **Example 1 — Find first bad version**

```cpp
while (l < r) {
    int mid = l + (r - l) / 2;

    if (isBad(mid)) r = mid;
    else l = mid + 1;
}
```

---

### **Example 2 — Koko Eating Bananas**

Check if Koko can eat all bananas at speed `mid`.

---

### **Example 3 — Find smallest divisor such that sum of ceil(arr[i]/div) ≤ threshold**

Feasibility:  
Compute sum and compare.

---

## **8. Interview‑Level Problems**

---

### **Problem 1 — Search in rotated sorted array**  
Binary search with pivot logic.

---

### **Problem 2 — Median of two sorted arrays**  
Binary search on partition.

---

### **Problem 3 — Find peak element**  
Binary search on slope.

---

### **Problem 4 — Find minimum in rotated sorted array**  
Binary search on monotonic segments.

---

### **Problem 5 — Kth smallest element in sorted matrix**  
Binary search on value range.

---

## **9. Exercises (Try First)**

---

### **Exercise 1**  
Search for a target in a fully sorted matrix.

---

### **Exercise 2**  
Find the first and last occurrence of a number using binary search.

---

### **Exercise 3**  
Solve “Aggressive Cows” using binary search on answer.

---

### **Exercise 4**  
Solve “Book Allocation Problem”.

---

### **Exercise 5**  
Find the peak element in an array.

---

## **10. Solutions**

---

### **Solution 1 — Search in sorted matrix**

Use 1D binary search on matrix.

---

### **Solution 2 — First & last occurrence**

```cpp
int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
int last  = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
```

---

### **Solution 3 — Aggressive Cows**

Feasibility:

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

Binary search on distance.

---

### **Solution 4 — Book Allocation**

Feasibility:  
Check if pages ≤ mid per student.

---

### **Solution 5 — Peak element**

```cpp
int l = 0, r = n - 1;

while (l < r) {
    int mid = (l + r) / 2;

    if (arr[mid] < arr[mid + 1])
        l = mid + 1;
    else
        r = mid;
}
return l;
```

---

## **11. Summary**

Today you mastered:

- Classic binary search  
- Binary search on 2D matrices  
- lower_bound / upper_bound  
- Binary search on monotonic functions  
- Binary search on answer  
- Feasibility functions  
- Allocation and optimization problems  
- Real interview patterns  

This is one of the most powerful problem‑solving paradigms in DSA.

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- State loop invariant before writing code.
- Choose inclusive/exclusive boundaries consistently.
- Write first-true / last-true templates from memory.
- Explain monotonic predicate in binary-search-on-answer.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Mid overflow in `mid = (l + r)/2` with large bounds.
- Infinite loop from wrong boundary updates.
- Returning `mid` directly without post-processing.
- Applying BS on non-monotonic condition.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: lower_bound / upper_bound exercises.
- Medium: rotated array search and first/last occurrence.
- Hard: allocate pages, aggressive cows, minimize maximum patterns.

