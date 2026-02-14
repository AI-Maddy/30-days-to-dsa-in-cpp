---

# **Day 10 — Sorting Revision + Custom Comparators + Counting Sort / Radix Sort Intuition (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Sorting is one of the most fundamental operations in computer science.  
It is the backbone of:

- Searching  
- Greedy algorithms  
- Binary search on answer  
- Hashing optimizations  
- Interval problems  
- Graph algorithms  
- Priority queues  
- Scheduling problems  

Today’s goal is to master:

- Comparison‑based sorting  
- Custom comparators  
- Sorting complex structures  
- Stability in sorting  
- Counting sort intuition  
- Radix sort intuition  
- When to use which sorting technique  
- Interview‑level sorting problems  

This day strengthens your algorithmic intuition and prepares you for advanced topics.

---

# **2. Sorting Algorithms — Quick Revision**

### **2.1 Time Complexities**

| Algorithm | Best | Average | Worst | Stable | Notes |
|----------|------|---------|--------|--------|--------|
| Quick Sort | O(n log n) | O(n log n) | O(n²) | No | Fastest in practice |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | Yes | Used in stable sorts |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | No | Uses heap |
| Bubble Sort | O(n) | O(n²) | O(n²) | Yes | Educational only |
| Insertion Sort | O(n) | O(n²) | O(n²) | Yes | Good for small arrays |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | Yes | Non‑comparison |
| Radix Sort | O(d·(n + k)) | O(d·(n + k)) | O(d·(n + k)) | Yes | Works on digits |

---

# **3. C++ sort() — The Workhorse**

C++ uses **Introsort**:

- Quick Sort  
- Heap Sort  
- Merge Sort  

Time: **O(n log n)**  
Space: **O(log n)**  

---

## **3.1 Basic Usage**

```cpp
sort(arr.begin(), arr.end());
```

---

## **3.2 Sorting in Descending Order**

```cpp
sort(arr.begin(), arr.end(), greater<int>());
```

---

# **4. Custom Comparators — The Real Power**

Custom comparators allow you to sort complex structures.

---

## **4.1 Comparator for Sorting Pairs**

### **Sort by first ascending, then second descending**

```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b){
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
});
```

---

## **4.2 Sorting Strings by Length**

```cpp
sort(v.begin(), v.end(), [](string &a, string &b){
    return a.size() < b.size();
});
```

---

## **4.3 Sorting Custom Structs**

```cpp
struct Student {
    string name;
    int marks;
};

sort(students.begin(), students.end(), [](auto &a, auto &b){
    return a.marks > b.marks;
});
```

---

# **5. Stability in Sorting**

A stable sort preserves the relative order of equal elements.

### **Stable Sort in C++**

```cpp
stable_sort(v.begin(), v.end());
```

Use when:

- Sorting by multiple keys  
- Sorting objects with equal primary keys  

---

# **6. Counting Sort — Intuition & Implementation**

Counting sort is a **non‑comparison** sorting algorithm.

### **When to use:**

- Range of numbers is small (0 to k)  
- k is not too large (k ≤ 10⁶)  
- Input size is large  

### **6.1 Steps**

1. Count frequency  
2. Compute prefix sum  
3. Place elements in output array  

---

### **6.2 Implementation**

```cpp
vector<int> count(k+1, 0);

for (int x : arr)
    count[x]++;

int idx = 0;
for (int i = 0; i <= k; i++)
    while (count[i]--)
        arr[idx++] = i;
```

Time: **O(n + k)**  
Space: **O(k)**  

---

# **7. Radix Sort — Intuition**

Radix sort sorts numbers digit by digit.

### **When to use:**

- Numbers have fixed number of digits  
- Range is large  
- Counting sort is used as subroutine  

### **7.1 LSD Radix Sort (Least Significant Digit First)**

Sort by:

1. Units place  
2. Tens place  
3. Hundreds place  
4. …  

Each step uses **stable counting sort**.

---

### **7.2 Implementation Sketch**

```cpp
int maxVal = *max_element(arr.begin(), arr.end());

for (int exp = 1; maxVal / exp > 0; exp *= 10)
    countingSortByDigit(arr, exp);
```

---

# **8. Sorting Complex Structures**

---

### **8.1 Sort Intervals by Start Time**

```cpp
sort(intervals.begin(), intervals.end(),
     [](auto &a, auto &b){ return a.start < b.start; });
```

---

### **8.2 Sort by Ratio (Greedy Problems)**

```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b){
    return (double)a.first / a.second > (double)b.first / b.second;
});
```

---

### **8.3 Sort by Custom Priority**

Used in:

- Scheduling  
- Greedy  
- Activity selection  

---

# **9. Real‑World Examples**

---

### **Example 1 — Sort students by marks, then name**

```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b){
    if (a.marks == b.marks)
        return a.name < b.name;
    return a.marks > b.marks;
});
```

---

### **Example 2 — Sort jobs by profit/weight ratio**

Used in fractional knapsack.

---

### **Example 3 — Sort points by polar angle**

Used in convex hull.

---

### **Example 4 — Sort intervals for merging**

```cpp
sort(intervals.begin(), intervals.end());
```

---

# **10. Interview‑Level Problems**

---

### **Problem 1 — Merge Intervals**  
Sort by start time.

---

### **Problem 2 — Non‑overlapping Intervals**  
Sort by end time.

---

### **Problem 3 — Largest Number from Array**  
Sort strings using custom comparator.

---

### **Problem 4 — Sort Colors (Dutch National Flag)**  
O(n) without sort.

---

### **Problem 5 — Meeting Rooms**  
Sort by start time.

---

# **11. Exercises (Try First)**

---

### **Exercise 1**  
Sort an array of pairs by first ascending, second descending.

---

### **Exercise 2**  
Sort strings by length, then lexicographically.

---

### **Exercise 3**  
Implement counting sort for numbers 0 to 10⁵.

---

### **Exercise 4**  
Sort intervals and merge them.

---

### **Exercise 5**  
Given an array of numbers, arrange them to form the largest number.

---

# **12. Solutions**

---

### **Solution 1 — Sort pairs**

Use comparator from section 4.1.

---

### **Solution 2 — Sort strings**

```cpp
sort(v.begin(), v.end(), [](string &a, string &b){
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
});
```

---

### **Solution 3 — Counting sort**

Use implementation from section 6.2.

---

### **Solution 4 — Merge intervals**

```cpp
sort(intervals.begin(), intervals.end());

vector<vector<int>> ans;
ans.push_back(intervals[0]);

for (auto &in : intervals) {
    if (in[0] <= ans.back()[1])
        ans.back()[1] = max(ans.back()[1], in[1]);
    else
        ans.push_back(in);
}
```

---

### **Solution 5 — Largest number**

```cpp
sort(v.begin(), v.end(), [](string &a, string &b){
    return a + b > b + a;
});
```

---

# **13. Summary**

Today you mastered:

- Sorting fundamentals  
- Custom comparators  
- Sorting complex structures  
- Stable vs unstable sorting  
- Counting sort intuition  
- Radix sort intuition  
- Real interview patterns  
- Greedy + sorting combinations  

Sorting is the backbone of many advanced algorithms — this day strengthens your foundation for the rest of the roadmap.

---
