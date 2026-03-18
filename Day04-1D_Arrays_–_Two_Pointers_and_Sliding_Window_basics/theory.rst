.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>


# **Day 4 – THEORY.rst**  
## **🧩 1D Arrays – Two Pointers & Sliding Window Basics**

---

# **🌟 1. Overview**

Day 4 introduces two of the most **powerful** and **widely used** patterns in array problems:

- 🎯 **Two Pointers**  
- 🚪 **Sliding Window**  

These patterns turn brute‑force O(n²) solutions into elegant **O(n)** solutions.

You’ll use these techniques in:

- Subarray problems  
- Searching & sorting  
- String processing  
- Window optimization  
- Frequency tracking  
- Greedy + DP hybrids  

Mastering these patterns is essential for cracking **medium/hard** interview problems.

---

# **📘 2. Two Pointers – The Foundation**

Two pointers use **two indices** to traverse an array efficiently.

```
i → start
j → end
```

---

# **🟦 2.1 When to Use Two Pointers**

Use it when:

- Array is **sorted**  
- You need to find **pairs** or **triplets**  
- You need to shrink/expand a range  
- You want to avoid nested loops  

---

# **🟩 2.2 Classic Two‑Pointer Patterns**

---

## **Pattern 1 — Opposite Ends (i = 0, j = n‑1)**  
Used in:

- Pair sum  
- 3Sum  
- Container With Most Water  

### **Example: Pair Sum**
```
while (i < j):
    if a[i] + a[j] == target → found
    else if sum < target → i++
    else → j--
```

---

## **Pattern 2 — Same Direction (i and j both move forward)**  
Used in:

- Removing duplicates  
- Merging arrays  
- Partitioning  

---

## **Pattern 3 — Fast & Slow Pointers**  
Used in:

- Cycle detection  
- Middle of linked list  
- Removing duplicates  

---

# **🧠 3. Two‑Pointer Tricks (Must Memorize)**

- Move the pointer that **reduces the gap**  
- For sorted arrays, two pointers beat binary search in pair problems  
- Avoid nested loops by adjusting pointers intelligently  
- Use two pointers to maintain **invariants** (sortedness, window validity)  

---

# **🚪 4. Sliding Window – The Real Powerhouse**

Sliding window is a **dynamic range** technique used for subarray problems.

Two types:

- 🟦 **Fixed Window** (size = k)  
- 🟩 **Variable Window** (expand/contract based on condition)  

---

# **🟦 4.1 Fixed Sliding Window**

Used when window size is **constant**.

### **Examples**
- Maximum sum of subarray of size k  
- First negative number in window  
- Sliding window average  

### **Template**
```
for (j = 0 to n-1):
    add a[j]
    if window size < k → continue
    process window
    remove a[i]
    i++
```

---

# **🟩 4.2 Variable Sliding Window**

Used when window size **changes dynamically**.

### **Examples**
- Longest substring without repeating characters  
- Longest subarray with sum ≤ k  
- Minimum window substring  
- Count subarrays with at most K distinct  

### **Template**
```
for (j = 0 to n-1):
    add a[j]
    while (window invalid):
        remove a[i]
        i++
    update answer
```

---

# **🧠 5. Sliding Window Key Concepts**

---

## **5.1 Window Expansion**
Add elements by moving `j++`.

---

## **5.2 Window Contraction**
Shrink window by moving `i++`.

---

## **5.3 Window Validity**
A window is valid when it satisfies:

- Sum constraint  
- Frequency constraint  
- Distinct count constraint  
- Character matching constraint  

---

## **5.4 Window Optimization**
Sliding window converts:

- O(n²) → O(n)  
- Brute force → optimal  

---

# **📊 6. Common Sliding Window Problems**

---

## **🟦 Fixed Window**
- Maximum sum subarray of size k  
- First negative in window  
- Count distinct elements in window  

---

## **🟩 Variable Window**
- Longest substring without repeating characters  
- Longest subarray with sum ≤ k  
- Minimum window substring  
- At most K distinct characters  

---

# **🧩 7. Two Pointers vs Sliding Window**

| Feature | Two Pointers | Sliding Window |
|--------|--------------|----------------|
| Window size | Not always a window | Always a window |
| Movement | Based on logic | Expand/contract |
| Use case | Sorted arrays, pair problems | Subarray/string problems |
| Complexity | O(n) | O(n) |

---

# **🧠 8. Interview‑Level Insights**

- Two pointers shine on **sorted arrays**  
- Sliding window shines on **strings/subarrays**  
- Always maintain **window invariants**  
- Use hash maps for frequency tracking  
- Use sets for uniqueness constraints  
- Most window problems reduce to **at most K** or **exactly K** patterns  

---

# **🔥 9. Must‑Know Patterns (Memorize These)**

---

## **Pattern A — Longest window with condition**
```
while (invalid):
    shrink
expand
update answer
```

---

## **Pattern B — Smallest window with condition**
```
expand until valid
shrink to minimize
```

---

## **Pattern C — At most K distinct**
```
while (freq.size() > K):
    shrink
```

---

## **Pattern D — Exactly K distinct**
```
exactlyK = atMost(K) - atMost(K-1)
```

---

# **🏁 10. Conclusion**

Day 4 gives you mastery over:

- Two pointers  
- Sliding window  
- Window expansion/contraction  
- Frequency maps  
- Subarray optimization  
- O(n) patterns  

These techniques will appear **everywhere** in upcoming topics:

- Prefix sums  
- Hashing  
- Strings  
- DP  
- Graphs  
- Greedy  

You now have the essential tools to solve **medium/hard** array and string problems.
