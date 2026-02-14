---

# **Day 05 — Prefix Sum + Difference Array + Range Query Patterns (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Prefix sums and difference arrays are two of the most powerful techniques for solving range‑based problems in O(1) per query after O(n) preprocessing.

They allow you to:

- Answer range sum queries instantly  
- Perform range updates efficiently  
- Convert O(n²) brute‑force loops into O(n)  
- Build intuition for advanced patterns like:  
  - Sliding window  
  - Binary indexed trees  
  - Segment trees  
  - Difference constraints  
  - Range DP  

Today’s goal is to master:

- Prefix sum arrays  
- Prefix sum on 2D matrices  
- Difference arrays (range update trick)  
- Range addition queries  
- Range frequency queries  
- Prefix XOR  
- Prefix max/min patterns  
- Interview‑level problems  

---

## **2. Prefix Sum — The Foundation**

Given an array `arr[]`, the prefix sum array `pref[]` is defined as:

```
pref[i] = arr[0] + arr[1] + ... + arr[i]
```

### **2.1 Building prefix sum (O(n))**

vector<int> pref(n);
pref[0] = arr[0];

for (int i = 1; i < n; i++)
    pref[i] = pref[i-1] + arr[i];

```
sum(l, r) = pref[r] - (l > 0 ? pref[l-1] : 0)
```
### **Example**

```cpp
int rangeSum(int l, int r) {
    if (l == 0) return pref[r];
    return pref[r] - pref[l-1];
}
```

---

## **4. Prefix Sum Variants**

Prefix sums are not limited to addition.

### **4.1 Prefix XOR**

```cpp
px[0] = arr[0];
for (int i = 1; i < n; i++)
    px[i] = px[i-1] ^ arr[i];
```

Range XOR:

```
xor(l, r) = px[r] ^ (l > 0 ? px[l-1] : 0)
```

---

### **4.2 Prefix Max / Prefix Min**

```cpp
pmax[i] = max(pmax[i-1], arr[i]);
pmin[i] = min(pmin[i-1], arr[i]);
```

---

## **5. 2D Prefix Sum (Matrix Prefix Sum)**

For matrix `mat[n][m]`, define:

```
pref[i][j] = sum of rectangle (0,0) to (i,j)
```

### **5.1 Build 2D prefix**

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        pref[i][j] = mat[i][j];
        if (i > 0) pref[i][j] += pref[i-1][j];
        if (j > 0) pref[i][j] += pref[i][j-1];
        if (i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
    }
}
```

---

### **5.2 Query sum of submatrix (x1, y1) to (x2, y2)**

```
sum = pref[x2][y2]
    - (y1 > 0 ? pref[x2][y1-1] : 0)
    - (x1 > 0 ? pref[x1-1][y2] : 0)
    + (x1 > 0 && y1 > 0 ? pref[x1-1][y1-1] : 0)
```

---

## **6. Difference Array — Range Update Trick**

Difference array `diff[]` is defined as:

```
diff[0] = arr[0]
diff[i] = arr[i] - arr[i-1]
```

### **6.1 Build difference array**

```cpp
vector<int> diff(n);
diff[0] = arr[0];

for (int i = 1; i < n; i++)
    diff[i] = arr[i] - arr[i-1];
```

---

## **7. Range Update in O(1)**

To add value `x` to range `[l, r]`:

```
diff[l] += x
if (r+1 < n) diff[r+1] -= x
```

### **7.1 Apply all updates**

```cpp
arr[0] = diff[0];
for (int i = 1; i < n; i++)
    arr[i] = arr[i-1] + diff[i];
```

---

## **8. Real‑World Examples**

---

### **Example 1 — Range Addition Queries**

Given Q queries of form:

```
add x to range [l, r]
```

Use difference array.

---

### **Example 2 — Frequency of each index after operations**

Classic problem:

```
n = 5
queries:
1 3
2 4
1 5
```

Increment diff:

```
diff[1]++, diff[4+1]--
diff[2]++, diff[5]--
diff[1]++, diff[5]--
```

Prefix sum gives final frequencies.

---

### **Example 3 — Maximum occurring element after range increments**

Use diff + prefix.

---

### **Example 4 — Subarray sum equals K (prefix sum + hashmap)**

```cpp
unordered_map<int,int> mp;
mp[0] = 1;

int sum = 0, count = 0;

for (int x : arr) {
    sum += x;
    if (mp.count(sum - k))
        count += mp[sum - k];
    mp[sum]++;
}
```

---

## **9. Interview‑Level Problems**

---

### **Problem 1 — Count subarrays with sum = K**

Use prefix sum + hashmap.

---

### **Problem 2 — Longest subarray with sum = K**

Use prefix sum + first occurrence map.

---

### **Problem 3 — Range update + point query**

Use difference array.

---

### **Problem 4 — Range update + range sum query**

Use difference array + prefix sum.

---

### **Problem 5 — 2D matrix sum queries**

Use 2D prefix sum.

---

## **10. Exercises (Try First)**

---

### **Exercise 1**  
Given an array, answer Q range sum queries in O(1) using prefix sum.

---

### **Exercise 2**  
Perform Q range addition operations using difference array.

---

### **Exercise 3**  
Given an array, count subarrays with sum exactly K.

---

### **Exercise 4**  
Given a matrix, answer submatrix sum queries using 2D prefix sum.

---

### **Exercise 5**  
Given an array, find the longest subarray with sum = K.

---

## **11. Solutions**

---

### **Solution 1 — Range sum queries**

```cpp
int sum(int l, int r) {
    if (l == 0) return pref[r];
    return pref[r] - pref[l-1];
}
```

---

### **Solution 2 — Range addition**

```cpp
diff[l] += x;
if (r+1 < n) diff[r+1] -= x;
```

---

### **Solution 3 — Count subarrays with sum K**

```cpp
unordered_map<int,int> mp;
mp[0] = 1;

int sum = 0, ans = 0;

for (int x : arr) {
    sum += x;
    if (mp.count(sum - k))
        ans += mp[sum - k];
    mp[sum]++;
}
```

---

### **Solution 4 — Submatrix sum**

Use 2D prefix formula.

---

### **Solution 5 — Longest subarray with sum K**

```cpp
unordered_map<int,int> first;
first[0] = -1;

int sum = 0, ans = 0;

for (int i = 0; i < n; i++) {
    sum += arr[i];

    if (first.count(sum - k))
        ans = max(ans, i - first[sum - k]);

    if (!first.count(sum))
        first[sum] = i;
}
```

---

## **12. Summary**

Today you mastered:

- Prefix sums (1D + 2D)  
- Range sum queries in O(1)  
- Prefix XOR, prefix max/min  
- Difference arrays  
- Range update tricks  
- Subarray sum = K patterns  
- Interview‑level range query problems  

These techniques appear everywhere — arrays, matrices, hashing, DP, graphs, and more.  
You now have one of the strongest tools in your DSA toolkit.

---
