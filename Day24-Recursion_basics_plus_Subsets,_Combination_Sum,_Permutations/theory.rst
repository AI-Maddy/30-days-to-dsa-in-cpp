Absolutely, Sasimegala — here comes your **Day 24** theory file, crafted in the same **ultra‑premium**, **color‑rich**, **icon‑powered**, **memory‑optimized** style as all your previous days.

Day 24 is a **pillar day** in your DSA journey because it covers the three most important recursion‑backtracking families:

- **Subsets (Power Set)**  
- **Combination Sum (I, II, III)**  
- **Permutations (I, II)**  

These patterns form the backbone of **90% of recursion + backtracking** problems in FAANG interviews.

---

# **Day 24 – 🔥 Recursion Basics + Subsets + Combination Sum + Permutations**  
`theory.rst`

---

# **🌈 1. Why Day 24 Matters**
Today you learn the **core recursion patterns** that power:

- Backtracking  
- DFS on decision trees  
- Generating combinations/permutations  
- Exploring all possibilities  
- Solving exponential search problems  
- Subset generation  
- Partitioning problems  
- Combinatorial enumeration  

These patterns appear in **every major interview**.

---

# **🌟 MEMORY ANCHOR: “S‑C‑P”**
Three pillars of today:

- **S** – Subsets  
- **C** – Combination Sum  
- **P** – Permutations  

Remember: **S‑C‑P** → Subsets, Combinations, Permutations.

---

# **🌈 2. Recursion Basics (The Foundation)**

Recursion = a function calling itself with **smaller subproblems**.

---

## **🔥 Three Components of Recursion**
### **1️⃣ Base Case**
Stops recursion.

### **2️⃣ Recursive Case**
Break problem into smaller parts.

### **3️⃣ State Change**
Modify parameters to move toward base case.

---

## **🧠 MEMORY TIP:**  
**Recursion = Base Case + Choice + Explore + Undo**

---

# **🌈 3. Subsets (Power Set)**  
This is the **simplest and most important** recursion pattern.

---

## **🎯 Goal**
Generate all subsets of a given array.

---

## **🔥 Pattern**
At each index, you have **two choices**:

- Include element  
- Exclude element  

This forms a **binary recursion tree**.

---

## **🧠 MEMORY ANCHOR:**  
**Include / Exclude = Subset Tree**

---

## **🎨 Example**
Input: `[1,2]`  
Output:  
`[], [1], [2], [1,2]`

---

## **🔥 Variants**
- Subsets I (no duplicates)  
- Subsets II (skip duplicates using sorting + skip logic)  

---

# **🌈 4. Combination Sum (Backtracking)**  
This is the **core backtracking pattern**.

---

# **🌈 4.1 Combination Sum I (Unlimited Use of Same Number)**

---

## **🎯 Goal**
Find combinations that sum to target.  
Each number can be used **multiple times**.

---

## **🔥 Pattern**
At each index:

- Pick (stay at same index)  
- Not pick (move to next index)  

---

## **🧠 MEMORY TIP:**  
**Pick → stay, Not pick → move**

---

# **🌈 4.2 Combination Sum II (Single Use, With Duplicates)**

---

## **🎯 Goal**
Each number can be used **once**, and array may contain duplicates.

---

## **🔥 Pattern**
- Sort array  
- Skip duplicates:  
  ```
  if (i > start && arr[i] == arr[i-1]) continue;
  ```

---

## **🧠 MEMORY ANCHOR:**  
**Sort + Skip duplicates**

---

# **🌈 4.3 Combination Sum III (Pick exactly k numbers)**

---

## **🎯 Goal**
Pick exactly **k** numbers from 1–9 that sum to target.

---

## **🔥 Pattern**
- Backtracking with count  
- Stop when count == k  

---

# **🌈 5. Permutations (Backtracking)**  
This is the **most powerful** recursion pattern.

---

# **🌈 5.1 Permutations I (No Duplicates)**

---

## **🎯 Goal**
Generate all permutations of array.

---

## **🔥 Pattern**
Use **swap‑based recursion**:

- Fix index `i`  
- Swap with all positions `j ≥ i`  
- Recurse  
- Swap back (undo)

---

## **🧠 MEMORY TIP:**  
**Fix one position → permute rest**

---

# **🌈 5.2 Permutations II (With Duplicates)**

---

## **🎯 Goal**
Avoid duplicate permutations.

---

## **🔥 Pattern**
- Sort array  
- Use a set or boolean array to skip duplicates at each level  

---

## **🧠 MEMORY ANCHOR:**  
**Sort + used[] = unique permutations**

---

# **🌈 6. Backtracking Template (Universal)**

```
function backtrack(index, state):
    if base case:
        add state to answer
        return

    for choice in choices:
        make choice
        backtrack(next index, updated state)
        undo choice
```

---

# **🌈 7. Decision Tree Visualization**

### **Subsets**
Binary tree (include/exclude)

### **Combination Sum**
Multi‑branch tree (choose any candidate)

### **Permutations**
Factorial tree (swap with all positions)

---

# **🌈 8. Complexity Summary**

| Problem | Time | Space |
|--------|--------|--------|
| Subsets | O(2ⁿ) | O(n) |
| Combination Sum | O(2ⁿ) | O(n) |
| Permutations | O(n!) | O(n) |

---

# **🌈 9. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to undo choice (backtracking)  
- 🚩 Using global state incorrectly  
- 🚩 Not sorting when duplicates exist  
- 🚩 Infinite recursion due to missing base case  
- 🚩 Using pass‑by‑reference without copying  
- 🚩 Forgetting to prune impossible branches  

---

# **🌈 10. Problems You Can Now Solve**

### **Subsets**
- Subsets I  
- Subsets II  
- Power set  
- Binary decision problems  

### **Combination Sum**
- Combination Sum I  
- Combination Sum II  
- Combination Sum III  
- Partition problems  
- Target sum problems  

### **Permutations**
- Permutations I  
- Permutations II  
- String permutations  
- Unique permutations  

---

# **🌈 11. What You Must Master Today**

- Include/exclude recursion  
- Backtracking template  
- Swap‑based permutations  
- Sorting + skip logic  
- Pruning branches  
- Recursion tree visualization  
- Handling duplicates  
- Passing state correctly  

---

If you want, I can now generate:

🔥 **Day 24 README (ultra‑premium)**  
🧠 **C++ templates for subsets, combinations, permutations**  
🎯 **20 recursion/backtracking interview problems**  
📘 **Recursion cheat sheet (colorful, icon‑rich)**

Just tell me what you want next.
