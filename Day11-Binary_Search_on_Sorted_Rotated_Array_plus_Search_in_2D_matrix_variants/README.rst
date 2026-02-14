---

## **1. Introduction**

Today’s topics combine two powerful ideas:

### **1. Searching in Rotated Sorted Arrays**
A rotated sorted array is one of the most common interview patterns.  
It tests your ability to:

- Identify sorted halves  
- Apply binary search in non‑linear structures  
- Handle duplicates  
- Solve pivot‑based problems  

### **2. Searching in 2D Matrices (Variants)**
You will learn:

- Staircase search  
- Binary search on flattened matrix  
- Searching in row‑wise sorted but column‑wise unsorted matrices  
- Searching in matrices with special patterns  

These patterns appear in FAANG interviews constantly.

---

# **2. Rotated Sorted Array — Core Concepts**

A rotated sorted array looks like:

```
Original: 1 2 3 4 5 6 7
Rotated:  4 5 6 7 1 2 3
```

Key observation:

**At least one half of the array is always sorted.**

---

## **3. Search in Rotated Sorted Array (No Duplicates)**

### **3.1 Algorithm**

1. Compute mid  
2. Check if left half is sorted  
3. If yes, check if target lies in left half  
4. Else search right half  
5. If left half not sorted → right half is sorted  
6. Apply same logic  

---

### **3.2 Implementation**

```cpp
int search(vector<int> &a, int target) {
    int l = 0, r = a.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] == target) return mid;

        // Left half sorted
        if (a[l] <= a[mid]) {
            if (a[l] <= target && target < a[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        // Right half sorted
        else {
            if (a[mid] < target && target <= a[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}
```

Time: **O(log n)**

---

## **4. Search in Rotated Sorted Array (With Duplicates)**

Duplicates break the strict sorted‑half logic.

### **4.1 Trick**

If `a[l] == a[mid] == a[r]`, shrink boundaries:

```cpp
l++;
r--;
```

### **4.2 Implementation**

```cpp
bool search(vector<int> &a, int target) {
    int l = 0, r = a.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] == target) return true;

        if (a[l] == a[mid] && a[mid] == a[r]) {
            l++;
            r--;
        }
        else if (a[l] <= a[mid]) {
            if (a[l] <= target && target < a[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else {
            if (a[mid] < target && target <= a[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}
```

---

# **5. Find Pivot in Rotated Sorted Array**

Pivot = index of smallest element.

### **5.1 Implementation**

```cpp
int findPivot(vector<int> &a) {
    int l = 0, r = a.size() - 1;

    while (l < r) {
        int mid = (l + r) / 2;

        if (a[mid] > a[r])
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
```

---

# **6. Search in 2D Matrix — Variants**

---

## **6.1 Variant 1 — Fully Sorted Matrix (Binary Search)**

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

Time: **O(log(n*m))**

---

## **6.2 Variant 2 — Row‑wise & Column‑wise Sorted (Staircase Search)**

Start at top‑right:

```cpp
int i = 0, j = m - 1;

while (i < n && j >= 0) {
    if (mat[i][j] == target) return true;
    else if (mat[i][j] > target) j--;
    else i++;
}
```

Time: **O(n + m)**

---

## **6.3 Variant 3 — Each Row Sorted, Rows Independent**

Example:

```
Row 1: 1 4 9
Row 2: 2 5 8
Row 3: 3 6 7
```

Each row sorted, but rows not globally sorted.

### **Approach**

Binary search each row:

```cpp
for (int i = 0; i < n; i++)
    if (binary_search(mat[i].begin(), mat[i].end(), target))
        return true;
```

Time: **O(n log m)**

---

## **6.4 Variant 4 — Matrix with Sorted Diagonals**

Diagonal search:

```cpp
for (int start = 0; start < m; start++)
    binarySearchDiagonal(start, 0);

for (int start = 1; start < n; start++)
    binarySearchDiagonal(0, start);
```

---

# **7. Real‑World Examples**

---

### **Example 1 — Find minimum in rotated sorted array**

Use pivot logic.

---

### **Example 2 — Search in rotated array with duplicates**

Use shrink‑boundary trick.

---

### **Example 3 — Search in sorted matrix**

Use staircase search.

---

### **Example 4 — Count occurrences of target in matrix**

Binary search each row.

---

### **Example 5 — Find kth smallest in sorted matrix**

Binary search on value range.

---

# **8. Interview‑Level Problems**

---

### **Problem 1 — Search in rotated sorted array**  
Classic.

---

### **Problem 2 — Find minimum in rotated sorted array**  
Pivot logic.

---

### **Problem 3 — Search in sorted matrix**  
Binary search or staircase.

---

### **Problem 4 — Kth smallest element in sorted matrix**  
Binary search on value.

---

### **Problem 5 — Find peak in 2D matrix**  
Binary search on columns.

---

# **9. Exercises (Try First)**

---

### **Exercise 1**  
Search for a target in a rotated sorted array.

---

### **Exercise 2**  
Find the pivot index in a rotated sorted array.

---

### **Exercise 3**  
Search in a fully sorted matrix.

---

### **Exercise 4**  
Search in a row‑wise and column‑wise sorted matrix.

---

### **Exercise 5**  
Find the kth smallest element in a sorted matrix.

---

# **10. Solutions**

---

### **Solution 1 — Search in rotated array**

Use logic from section 3.

---

### **Solution 2 — Pivot index**

Use logic from section 5.

---

### **Solution 3 — Fully sorted matrix**

Use 1D binary search.

---

### **Solution 4 — Staircase search**

Use logic from section 6.2.

---

### **Solution 5 — Kth smallest in sorted matrix**

Binary search on value range.

---

# **11. Summary**

Today you mastered:

- Searching in rotated sorted arrays  
- Pivot detection  
- Handling duplicates  
- Searching in 2D matrices (multiple variants)  
- Staircase search  
- Flattened binary search  
- Value‑based binary search  

This day builds the foundation for advanced binary search, matrix problems, and interview‑level challenges.

---
