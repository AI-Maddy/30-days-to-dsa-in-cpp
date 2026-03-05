.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>

Absolutely, Sasimegala — here is your **Day 2 – THEORY.rst**, crafted with the same ultra‑premium, colorful, icon‑rich, highly‑memorizable style as Day 1 and Day 30.

This is **Day 2: Time & Space Complexity + STL Algorithms**, designed to feel like a beautifully structured textbook chapter.

---

# **Day 2 – THEORY.rst**  
## **⏱️ Time & Space Complexity + ⚙️ STL Algorithms Mastery**

---

# **🌟 1. Overview**

Day 2 builds the mathematical backbone of your DSA journey:

- ⏱️ **Time Complexity**  
- 💾 **Space Complexity**  
- ⚙️ **STL Algorithms**  
- 📊 **Big‑O intuition**  
- 🧠 **How to analyze code efficiently**  

This chapter makes you fluent in understanding **how fast** and **how memory‑efficient** your programs are — a skill every top‑tier engineer must master.

---

# **📘 2. Big‑O Notation (The Language of Complexity)**

Big‑O describes **how performance scales** with input size `n`.

---

## **🟦 2.1 Common Time Complexities (Memorize This Table)**

| Complexity | Name | Example |
|-----------|------|---------|
| **O(1)** | Constant | Accessing array index |
| **O(log n)** | Logarithmic | Binary search |
| **O(n)** | Linear | Loop through array |
| **O(n log n)** | Log‑linear | Merge sort, sort() |
| **O(n²)** | Quadratic | Nested loops |
| **O(2ⁿ)** | Exponential | Subset generation |
| **O(n!)** | Factorial | Permutations |

---

## **🟩 2.2 Visual Intuition (Fast → Slow)**

```
O(1)  →  O(log n)  →  O(n)  →  O(n log n)  →  O(n²)  →  O(2ⁿ)  →  O(n!)
```

Think of it like **speed tiers**:

- 🚀 O(1), O(log n) → blazing fast  
- ⚡ O(n), O(n log n) → acceptable  
- 🐢 O(n²) → slow for large n  
- 🐌 O(2ⁿ), O(n!) → avoid unless n ≤ 20  

---

# **🧮 3. Time Complexity – Deep Dive**

---

## **🟦 3.1 O(1) – Constant Time**

Operations that don’t depend on input size:

- Accessing `arr[i]`  
- Pushing to `vector` (amortized)  
- Hash map insert/search (average)  

---

## **🟩 3.2 O(log n) – Logarithmic**

Divide‑and‑conquer operations:

- Binary search  
- Heap operations  
- Balanced BST operations  

---

## **🟨 3.3 O(n) – Linear**

Single loop:

```
for (int i = 0; i < n; i++)
```

---

## **🟧 3.4 O(n log n) – Log‑Linear**

Sorting algorithms:

- `sort()`  
- Merge sort  
- Heap sort  

---

## **🟥 3.5 O(n²) – Quadratic**

Nested loops:

```
for i:
  for j:
```

Used in:

- Matrix operations  
- Brute force pair checking  

---

## **🟪 3.6 O(2ⁿ) – Exponential**

Used in:

- Subsets  
- Recursion without memoization  

---

## **🟫 3.7 O(n!) – Factorial**

Used in:

- Permutations  
- Traveling Salesman brute force  

---

# **💾 4. Space Complexity**

Measures **extra memory** used.

---

## **🟦 4.1 O(1) – Constant Space**

- Two pointers  
- In‑place algorithms  

---

## **🟩 4.2 O(n) – Linear Space**

- Storing arrays  
- Recursion stack  
- Hash maps  

---

## **🟨 4.3 O(n²) – Quadratic Space**

- 2D matrices  
- DP tables  

---

# **⚙️ 5. STL Algorithms – The Powerhouse**

STL algorithms are **highly optimized** and should be your default choice.

---

## **🟦 5.1 Sorting Algorithms**

### **sort() – O(n log n)**  
Uses **Introsort** (QuickSort + HeapSort + MergeSort hybrid).

```
sort(v.begin(), v.end());
```

### **Custom comparator**
```
sort(v.begin(), v.end(), [](int a, int b){
    return a > b;
});
```

---

## **🟩 5.2 Searching Algorithms**

### **binary_search() – O(log n)**  
Checks if element exists.

### **lower_bound() – O(log n)**  
First element ≥ x.

### **upper_bound() – O(log n)**  
First element > x.

---

## **🟨 5.3 Useful STL Algorithms**

| Algorithm | Purpose |
|----------|----------|
| `reverse()` | Reverse container |
| `max_element()` | Largest element |
| `min_element()` | Smallest element |
| `accumulate()` | Sum of elements |
| `count()` | Count occurrences |
| `unique()` | Remove duplicates |
| `erase()` | Remove elements |

---

# **🧠 6. How to Analyze Code Quickly**

---

## **🟦 6.1 Rule 1 — Count Loops**

- One loop → O(n)  
- Nested loops → O(n²)  
- Loop inside binary search → O(n log n)  

---

## **🟩 6.2 Rule 2 — Look for Recursion**

- Recursion without memo → exponential  
- Recursion with memo → polynomial  

---

## **🟨 6.3 Rule 3 — Check STL Operations**

- `sort()` → O(n log n)  
- `push_back()` → O(1) amortized  
- `map` insert → O(log n)  
- `unordered_map` insert → O(1) average  

---

## **🟧 6.4 Rule 4 — Ignore Constants**

```
O(3n + 5) → O(n)
```

---

# **📚 7. Common Patterns (Must Memorize)**

---

## **🟦 Pattern 1 — Two Pointers**

Used in:

- Pair sum  
- Removing duplicates  
- Sliding window  

---

## **🟩 Pattern 2 — Binary Search on Sorted Data**

Used in:

- Searching  
- Optimization problems  

---

## **🟨 Pattern 3 — Hash Map for Frequency**

Used in:

- Anagrams  
- Subarray sum  
- Hashing problems  

---

## **🟧 Pattern 4 — Sorting + Greedy**

Used in:

- Activity selection  
- Interval scheduling  

---

# **🎯 8. Interview‑Level Insights**

- Always prefer STL algorithms over manual loops  
- Use `unordered_map` for O(1) average lookups  
- Use `vector` unless you specifically need linked list behavior  
- Understand time complexity of each STL container  
- Avoid nested loops unless necessary  

---

# **🏁 9. Conclusion**

Day 2 gives you the **mathematical intuition** behind algorithm performance and the **STL algorithm toolkit** to write efficient code.

You now understand:

- Time complexity  
- Space complexity  
- STL algorithms  
- How to analyze code  
- How to choose the right container  

This foundation will be used **every single day** going forward.

---

If you want, I can now generate:

- **Day 2 README.rst**  
- **Day 3 theory.rst**  
- **A combined complexity cheat sheet**  

Just tell me what you want next.
