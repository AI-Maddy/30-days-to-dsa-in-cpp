---

# **Day 11 – 🎯 Advanced Binary Search Patterns (Colorful Memory Edition)**  
`theory.rst`

---

# **🌈 1. Why Day 11 Matters**
Binary search is not just a technique — it’s a **framework**.

Today you learn:

- 🔥 Binary Search on **Index**  
- 🔥 Binary Search on **Value**  
- 🔥 Binary Search on **Answer** (BSOA) — deeper than Day 09  
- 🔥 Binary Search on **Real Numbers**  
- 🔥 Binary Search on **Rotated Arrays**  
- 🔥 Binary Search on **Monotonic Functions**  
- 🔥 Binary Search on **Bitonic Arrays**  
- 🔥 Binary Search on **First/Last occurrence patterns**

This is the day where binary search becomes **a weapon**, not a tool.

---

# **🌟 MEMORY ANCHOR: “I‑V‑A‑R‑M‑B”**
The 6 binary search universes:

- **I** – Index search  
- **V** – Value search  
- **A** – Answer search  
- **R** – Real number search  
- **M** – Monotonic function search  
- **B** – Bitonic array search  

Remember: **I‑V‑A‑R‑M‑B** → “I Value Answers in Real Monotonic Bitonics”.

---

# **🌈 2. Binary Search on Index (Classic)**

---

## **💙 Pattern 1: First Occurrence**
Find first index where `arr[i] == target`.

### **🧠 MEMORY TIP:**  
When you find target → **go left**.

---

## **💚 Pattern 2: Last Occurrence**
Find last index where `arr[i] == target`.

### **🧠 MEMORY TIP:**  
When you find target → **go right**.

---

## **💛 Pattern 3: Lower Bound**
First index where `arr[i] >= target`.

---

## **❤️ Pattern 4: Upper Bound**
First index where `arr[i] > target`.

---

# **🌈 3. Binary Search on Value (Search in Sorted Space)**

Used when:

- Array is sorted  
- You search for a **value**, not an index  
- You need to check feasibility  

Examples:
- Search in sorted matrix  
- Search in rotated array  
- Search in bitonic array  

---

# **🌈 4. Binary Search on Rotated Sorted Array**

---

## **💥 Pattern 1: Search Target in Rotated Array**
Key idea:
- One half is always sorted  
- Check which half target lies in  

### **🧠 MEMORY ANCHOR:**  
**S‑U‑R**  
Sorted → Unsorted → Rotate logic

---

## **💥 Pattern 2: Find Minimum in Rotated Array**
Find pivot.

### **🧠 MEMORY TIP:**  
Minimum lies in the **unsorted** half.

---

# **🌈 5. Binary Search on Bitonic Array**

A bitonic array:
- Strictly increasing  
- Then strictly decreasing  

---

## **🎯 Steps**
1. Find peak using binary search  
2. Binary search on left (ascending)  
3. Binary search on right (descending)  

### **🧠 MEMORY ANCHOR:**  
**Peak → Left → Right**

---

# **🌈 6. Binary Search on Monotonic Functions**

Used when:
- Function is monotonic  
- You need to find smallest/largest x satisfying condition  

Examples:
- Square root  
- Nth root  
- Koko eating bananas  
- Minimum speed to arrive on time  
- Allocate tasks with constraints  

---

## **🎯 Steps**
1. Define function `f(x)`  
2. Check monotonicity  
3. Binary search on x  

### **🧠 MEMORY TIP:**  
If `f(mid)` is valid → move left or right depending on goal.

---

# **🌈 7. Binary Search on Real Numbers (Floating Point Search)**

Used for:
- Square root  
- Nth root  
- Binary search on probability  
- Binary search on time  
- Geometry problems  

---

## **🎯 Steps**
1. low = 0  
2. high = max possible  
3. Repeat 60–100 iterations  
4. Check feasibility  

### **🧠 MEMORY ANCHOR:**  
**Binary search until precision achieved.**

---

# **🌈 8. Binary Search on Answer (BSOA) — Deep Reinforcement**

You learned this in Day 09, but today we expand:

Used for:
- Aggressive cows  
- Book allocation  
- Painters partition  
- Split array largest sum  
- Koko eating bananas  
- Min speed to arrive on time  
- Min days to make bouquets  
- Magnetic force between balls  
- Ship packages within D days  

---

## **🎯 Steps**
1. Define search space  
2. Write feasibility function  
3. Use monotonicity  
4. Return best feasible answer  

### **🧠 MEMORY ANCHOR:**  
**S‑C‑D‑R**  
Search → Check → Decide → Return

---

# **🌈 9. Binary Search Pitfalls (Red Flags 🚩)**

- 🚩 Infinite loops due to wrong mid update  
- 🚩 Using `mid = (l + r) / 2` (overflow)  
- 🚩 Wrong feasibility logic  
- 🚩 Wrong monotonicity assumption  
- 🚩 Using binary search on unsorted data  
- 🚩 Forgetting to shrink search space  
- 🚩 Off‑by‑one errors in first/last occurrence  

---

# **🌈 10. Problems You Can Now Solve**

- First/last occurrence  
- Lower/upper bound  
- Search in rotated array  
- Find minimum in rotated array  
- Find peak in bitonic array  
- Search in bitonic array  
- Square root (integer + real)  
- Nth root  
- Koko eating bananas  
- Min speed to arrive on time  
- Split array largest sum  
- Min days to make bouquets  
- Ship packages within D days  
- Magnetic force between balls  

---

# **🌈 11. What You Must Master Today**

- All binary search patterns  
- Rotated array logic  
- Bitonic array logic  
- Monotonic function search  
- Real number binary search  
- BSOA (Binary Search on Answer)  
- Feasibility function writing  
- Avoiding binary search pitfalls  

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

