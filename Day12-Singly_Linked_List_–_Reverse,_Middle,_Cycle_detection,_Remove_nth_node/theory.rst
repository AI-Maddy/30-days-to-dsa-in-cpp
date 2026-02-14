---

# **Day 12 – 🔥 Two Pointers Mastery + Meet‑in‑the‑Middle + Prefix Tricks**  
`theory.rst`

---

# **🌈 1. Why Day 12 Matters**
Two pointers is one of the **most powerful** patterns in DSA because it turns:

- ❌ O(n²) brute force  
into  
- ✅ O(n) or O(n log n) elegant solutions.

Today you learn:

- 🔥 Two pointers on sorted arrays  
- 🔥 Two pointers on unsorted arrays (after sorting)  
- 🔥 Pair sum, triplet sum, 3‑sum, 4‑sum  
- 🔥 Meet‑in‑the‑middle (2ⁿ → 2ⁿ/²)  
- 🔥 Prefix tricks for optimization  
- 🔥 Merging, partitioning, deduplication  
- 🔥 Geometry + two pointers  
- 🔥 Strings + two pointers  

This is a **massive** upgrade to your problem‑solving toolkit.

---

# **🌟 MEMORY ANCHOR: “C‑M‑P‑G‑S”**
Two pointers solve problems involving:

- **C**ollision (meeting in middle)  
- **M**ovement (left/right motion)  
- **P**artitioning (split arrays)  
- **G**eometry (areas, distances)  
- **S**trings (palindromes, compression)  

Remember: **C‑M‑P‑G‑S** → the five worlds of two pointers.

---

# **🌈 2. Two Pointers on Sorted Arrays (The Classic)**

---

## **💙 Pattern 1: Pair Sum**
Given sorted array, find if pair sums to target.

### **🎯 Logic**
- left = 0  
- right = n‑1  
- If sum < target → left++  
- If sum > target → right--  
- Else found  

### **🧠 MEMORY TIP:**  
**Small sum → move left**  
**Big sum → move right**

---

## **💚 Pattern 2: Triplet Sum (3‑Sum)**
Sort array → fix one element → two pointers for the rest.

### **🧠 MEMORY ANCHOR:**  
**Fix + Pair Sum**

---

## **💛 Pattern 3: 3‑Sum Closest**
Same as 3‑sum but track closest difference.

---

## **❤️ Pattern 4: 4‑Sum**
Sort → fix two → two pointers for remaining.

### **🧠 MEMORY TIP:**  
**4‑Sum = 2‑Sum inside 2‑Sum**

---

# **🌈 3. Two Pointers on Unsorted Arrays (Sort First)**

Used for:
- Pair sum  
- Triplet sum  
- Remove duplicates  
- Partitioning  

### **🧠 MEMORY TIP:**  
If array is unsorted → **sort first** → then apply two pointers.

---

# **🌈 4. Two Pointers for Deduplication**

---

## **💙 Pattern: Remove Duplicates from Sorted Array**
Maintain:
- slow pointer → position to write  
- fast pointer → scanning  

### **🧠 MEMORY ANCHOR:**  
**Fast reads, slow writes**

---

# **🌈 5. Two Pointers for Partitioning**

---

## **💚 Pattern: Dutch National Flag (0,1,2 Sort)**
Three pointers:
- low  
- mid  
- high  

### **🧠 MEMORY TIP:**  
**0 → left**  
**2 → right**  
**1 → stay**

---

## **💛 Pattern: Partition Even/Odd**
Move left until odd  
Move right until even  
Swap  

---

# **🌈 6. Two Pointers in Strings**

---

## **💙 Pattern: Palindrome Check**
left++, right--

---

## **💚 Pattern: Reverse String**
Swap left/right

---

## **💛 Pattern: Compress String**
Two pointers:
- read pointer  
- write pointer  

---

## **❤️ Pattern: Remove Adjacent Duplicates**
Use two pointers or stack logic.

---

# **🌈 7. Geometry + Two Pointers**

---

## **💙 Pattern: Container With Most Water**
Two pointers at ends.

### **🧠 MEMORY ANCHOR:**  
Move the **shorter** line.

---

## **💚 Pattern: Max Area of Histogram (Two‑Pointer Variant)**
Not the stack version — but a two‑pointer intuition exists.

---

# **🌈 8. Meet‑in‑the‑Middle (MITM)**  
(Used in problems where 2ⁿ is too big)

---

## **💥 Why MITM Matters**
Instead of O(2ⁿ), split into two halves:

- Left half → all subset sums  
- Right half → all subset sums  
- Sort + two pointers or binary search  

### **🧠 MEMORY ANCHOR:**  
**Split → Solve → Merge**

---

## **🔥 Applications**
- Subset sum  
- K‑sum variants  
- Hard DP optimizations  
- Knapsack approximations  

---

# **🌈 9. Prefix Tricks + Two Pointers**

---

## **💙 Pattern: Subarray Sum ≤ K**
Use:
- Two pointers  
- Prefix sum  
- Sliding window  

---

## **💚 Pattern: Count Subarrays with Sum in Range**
Two pointers + prefix + binary search.

---

## **💛 Pattern: Longest Subarray with Limit**
Two pointers + monotonic deque.

---

# **🌈 10. Pitfalls (Red Flags 🚩)**

- 🚩 Using two pointers on unsorted arrays without sorting  
- 🚩 Forgetting to skip duplicates in 3‑sum/4‑sum  
- 🚩 Moving wrong pointer in pair sum  
- 🚩 Infinite loops due to incorrect pointer updates  
- 🚩 Using two pointers when array is not monotonic  
- 🚩 Forgetting overflow in sum calculations  
- 🚩 Using two pointers for problems requiring DP  

---

# **🌈 11. Problems You Can Now Solve**

- Pair sum  
- Triplet sum  
- 3‑sum  
- 4‑sum  
- Container with most water  
- Remove duplicates  
- Dutch national flag  
- Partition even/odd  
- Palindrome check  
- Reverse string  
- Compress string  
- Subset sum (MITM)  
- K‑sum variants  
- Longest subarray with limit  
- Count subarrays with sum ≤ K  

---

# **🌈 12. What You Must Master Today**

- Two pointers on sorted arrays  
- Two pointers on unsorted arrays (after sorting)  
- Deduplication patterns  
- Partitioning patterns  
- String two‑pointer patterns  
- Geometry two‑pointer patterns  
- Meet‑in‑the‑middle  
- Prefix + two pointer hybrid patterns  

---
