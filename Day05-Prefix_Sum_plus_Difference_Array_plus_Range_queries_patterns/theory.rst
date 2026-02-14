---

# **Day 05 – Prefix Sum + Difference Array + Range Query Patterns**  
`theory.rst`

---

## **1. Motivation: Why These Patterns Matter**
Prefix sums and difference arrays are among the most *powerful* array‑processing techniques in algorithmic interviews. They allow you to:

- Answer range queries in **O(1)** after **O(n)** preprocessing  
- Perform range updates in **O(1)** instead of **O(n)**  
- Convert expensive brute‑force loops into elegant mathematical transforms  
- Build foundations for advanced patterns like:
  - Sliding window
  - Hash‑based prefix sums
  - Subarray sum counting
  - Range add / range increment problems
  - Imos method (2D difference arrays)

These patterns appear in **FAANG**, **Top Product Companies**, and **Competitive Programming**.

---

## **2. Prefix Sum – The Core Idea**
Given an array \(A\), the prefix sum array \(P\) is defined as:

\[
P[i] = A[0] + A[1] + \dots + A[i]
\]

This allows computing any subarray sum in **O(1)**:

\[
\text{sum}(l, r) = P[r] - P[l-1]
\]

Special case:

- If \(l = 0\), then \(\text{sum}(0, r) = P[r]\)

---

## **3. Building Prefix Sum Array**
### **Example**
Array:  
`A = [2, 4, -1, 3, 5]`

Prefix sum:  
`P = [2, 6, 5, 8, 13]`

### **Visual**
```
Index:     0   1   2   3   4
A[i]:      2   4  -1   3   5
P[i]:      2   6   5   8  13
```

### **Range Query Example**
Sum of subarray from index 1 to 3:

\[
P[3] - P[0] = 8 - 2 = 6
\]

---

## **4. Common Prefix Sum Applications**
### **4.1 Range Sum Queries**
Classic problem:  
Given array + Q queries of form `(l, r)`, compute sum quickly.

### **4.2 Counting Subarrays with Given Sum**
Use prefix sums + hashmap.

### **4.3 Even/Odd prefix patterns**
Useful for:
- Counting even‑sum subarrays
- Counting divisible‑by‑k subarrays

### **4.4 Prefix Max / Prefix Min**
Not a sum, but same idea:
- Running maximum
- Running minimum

---

## **5. Difference Array – The Reverse of Prefix Sum**
Difference array allows **range updates in O(1)**.

Given array \(A\), difference array \(D\) is:

\[
D[0] = A[0]
\]
\[
D[i] = A[i] - A[i-1]
\]

To apply a range increment:

Increase all elements from `l` to `r` by `x`:

```
D[l] += x
D[r+1] -= x   (if r+1 < n)
```

After all updates, reconstruct final array using prefix sum on D.

---

## **6. Difference Array Example**
### **Initial Array**
`A = [5, 5, 5, 5, 5]`

### **Difference Array**
`D = [5, 0, 0, 0, 0]`

### **Apply updates**
1. Add +3 to range [1, 3]  
```
D[1] += 3
D[4] -= 3
```

2. Add +2 to range [2, 4]  
```
D[2] += 2
(no D[5] because out of bounds)
```

### **Final D**
`D = [5, 3, 2, 0, -3]`

### **Reconstruct A**
Prefix sum on D:

```
A = [5, 8, 10, 10, 7]
```

---

## **7. When to Use Prefix Sum vs Difference Array**

| Scenario | Use |
|---------|-----|
| Many range **queries**, few updates | Prefix Sum |
| Many range **updates**, few queries | Difference Array |
| Need to count subarrays with property | Prefix Sum + Hashing |
| Need to apply increments on ranges | Difference Array |
| Need to compute cumulative effect | Prefix Sum |

---

## **8. Range Query Patterns**
### **8.1 Range Sum Query**
Use prefix sum.

### **8.2 Range XOR Query**
Prefix XOR:
\[
PX[i] = A[0] \oplus A[1] \oplus \dots \oplus A[i]
\]

Range XOR:
\[
PX[r] \oplus PX[l-1]
\]

### **8.3 Range Minimum/Maximum**
Prefix min/max works only for:
- Queries starting at index 0  
- Or monotonic constraints

For arbitrary ranges → use Segment Tree (later days).

### **8.4 Range Frequency Queries**
Convert to prefix frequency table:
- For each value, maintain prefix count
- Useful for character frequency in strings

---

## **9. Advanced Prefix Sum Patterns**
### **9.1 Prefix Sum with Hashing (Subarray Sum = k)**
Maintain:
- prefix sum
- hashmap storing counts of prefix sums

### **9.2 Prefix Modulo Pattern**
Used for:
- Subarrays divisible by k
- Counting pairs with same prefix mod

### **9.3 2D Prefix Sum**
For matrices:
\[
P[i][j] = \text{sum of rectangle from (0,0) to (i,j)}
\]

Rectangle sum in O(1):
\[
P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1]
\]

---

## **10. Advanced Difference Array Patterns**
### **10.1 2D Difference Array (Imos Method)**
Used for:
- Range updates on grids
- Heatmaps
- Painting rectangles

### **10.2 Range Replace / Range Set**
Difference array cannot directly handle "set" operations  
→ requires lazy propagation (covered in segment trees).

---

## **11. Common Pitfalls**
- Forgetting to handle `l = 0` case in prefix sum queries  
- Forgetting boundary check for `D[r+1] -= x`  
- Using prefix sum for range min/max (incorrect)  
- Overflow in prefix sums (use long long)  
- Mixing 1‑based and 0‑based indexing

---

## **12. Interview‑Level Examples**
### **Example 1: Range Sum Queries**
Given array and Q queries, answer sum(l, r).

### **Example 2: Range Increment Updates**
Given N, Q updates of form `(l, r, x)`, output final array.

### **Example 3: Count Subarrays with Sum = K**
Use prefix sum + hashmap.

### **Example 4: Longest Subarray with Sum = K**
Use prefix sum + first occurrence map.

### **Example 5: Subarrays Divisible by K**
Use prefix modulo + hashmap.

---

## **13. Time & Space Complexity Summary**

| Technique | Preprocessing | Query | Update | Space |
|----------|---------------|--------|--------|--------|
| Prefix Sum | O(n) | O(1) | O(n) | O(n) |
| Difference Array | O(n) | O(n) | O(1) | O(n) |
| Prefix XOR | O(n) | O(1) | O(n) | O(n) |
| Prefix Hashing | O(n) | O(1) | O(n) | O(n) |

---

## **14. What You Should Master Today**
- Build prefix sum arrays confidently  
- Compute range sums in O(1)  
- Build and apply difference arrays  
- Perform range updates in O(1)  
- Solve subarray sum problems using prefix + hashmap  
- Understand when prefix sum fails (min/max queries)  
- Understand 2D prefix and 2D difference arrays  

---
