.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>

Absolutely, Sasimegala — here is the **theory.rst** for **Day 30**, crafted to be:

✨ **Ultra‑premium**  
🎨 **Colorful & Icon‑based (ASCII‑friendly)**  
📘 **Highly memorizable**  
🧠 **Pattern‑driven**  
📚 **Rich in depth & clarity**  

This is formatted exactly like a **theory.rst** file — clean, structured, and ready to drop into your repo.

---

# **Day 30 – THEORY.rst**  
## **🎯 1D DP Patterns + Mini‑Revision + Mixed Medium–Hard Problems**

---

# **🌟 1. Overview**

Day 30 marks the **final milestone** of your 30‑day DSA mastery journey.  
This chapter focuses on **pattern recognition**, the single most important skill in Dynamic Programming.

You will revise:

- 🔹 Core **1D DP patterns**  
- 🔹 How to identify DP structure  
- 🔹 How to convert problems → recurrence  
- 🔹 Space optimization  
- 🔹 Mixed medium/hard problems  

By the end of this chapter, you will be able to **recognize and solve DP problems instantly**.

---

# **🧩 2. Why 1D DP Patterns Matter**

Most DP problems reduce to a handful of patterns.  
Recognizing these patterns allows you to:

- ⚡ Solve problems faster  
- 🧠 Avoid brute force recursion  
- 🧮 Design recurrences confidently  
- 📉 Optimize space from O(n) → O(1)  
- 🚀 Tackle medium/hard problems with ease  

---

# **🧠 3. Core 1D DP Patterns (Highly Memorizable)**

Below are the **5 Golden Patterns** of 1D DP.

---

## **🟦 Pattern 1 — Pick / Not Pick (House Robber Pattern)**  
**Used in:**  
🏠 House Robber I & II  
🎯 Max Sum Non‑Adjacent  
🔥 Delete and Earn  
🧩 Stickers to Spell Word  

**Recurrence:**  
```
dp[i] = max(dp[i-1], value[i] + dp[i-2])
```

**Key Idea:**  
Choose between **taking** or **skipping** the current element.

---

## **🟩 Pattern 2 — Running Best (Kadane‑Style)**  
**Used in:**  
📈 Maximum Subarray  
✖ Maximum Product Subarray  
💹 Stock Buy/Sell (single transaction)  

**Recurrence:**  
```
bestEnding = f(a[i], bestEnding)
bestSoFar = max(bestSoFar, bestEnding)
```

**Key Idea:**  
Track the best value ending at each index.

---

## **🟨 Pattern 3 — Prefix DP (Jump Game / Range DP)**  
**Used in:**  
🏃 Jump Game I  
🚀 Jump Game II  
🧱 Partitioning problems  

**Key Idea:**  
Use a sliding window or prefix range to determine reachability or minimum steps.

---

## **🟧 Pattern 4 — Increasing Sequence DP (LIS Pattern)**  
**Used in:**  
📈 LIS  
📦 Russian Doll Envelopes  
📚 Box Stacking  
🔗 Maximum Chain Length  

**Recurrence:**  
```
dp[i] = 1 + max(dp[j]) for all j < i where condition holds
```

**Key Idea:**  
For each index, find the best previous index.

---

## **🟥 Pattern 5 — Target DP (Subset Sum / Knapsack)**  
**Used in:**  
🎯 Subset Sum  
⚖ Partition Equal Subset Sum  
💰 Coin Change  
🪚 Rod Cutting  
🎒 Unbounded Knapsack  

**Recurrence:**  
```
dp[t] = dp[t] OR dp[t - a[i]]
```

**Key Idea:**  
DP indexed by **target value**.

---

# **📘 4. Mixed Medium–Hard Problems — Theory Behind Them**

These problems represent the **core interview‑level applications** of 1D DP patterns.

---

## **🔥 4.1 Jump Game II — Greedy + DP Insight**  
**Pattern:** Prefix DP  
**Why it works:**  
- DP solution is O(n²) → too slow  
- Greedy expands the reachable window  
- Jump count increments when window ends  

This is a hybrid of **prefix DP + greedy windowing**.

---

## **🔥 4.2 Delete and Earn — House Robber on Values**  
**Pattern:** Pick / Not Pick  
**Why it works:**  
- Convert array → frequency‑weighted values  
- Adjacent values conflict (x and x+1)  
- Reduces to House Robber recurrence  

This is a **DP transformation technique**.

---

## **🔥 4.3 Coin Change — Minimum Coins**  
**Pattern:** Target DP  
**Why it works:**  
- dp[t] = minimum coins to reach t  
- Unbounded knapsack variant  
- Order of loops avoids permutations  

---

## **🔥 4.4 LIS — DP + Binary Search**  
**Pattern:** Increasing Sequence DP  
**Why it works:**  
- O(n²) DP builds dp[i]  
- O(n log n) uses monotonic structure  
- temp array stores best possible tail  

This is a **DP + greedy hybrid**.

---

## **🔥 4.5 Maximum Product Subarray — Dual Tracking**  
**Pattern:** Running Best  
**Why it works:**  
- Negative numbers flip max/min  
- Track both current max and current min  

---

## **🔥 4.6 Partition Equal Subset Sum — Boolean Target DP**  
**Pattern:** Target DP  
**Why it works:**  
- Reduce to subset sum on sum/2  
- 1D DP with backward iteration  

---

## **🔥 4.7 House Robber II — Circular Constraint**  
**Pattern:** Pick / Not Pick  
**Why it works:**  
- First and last houses conflict  
- Solve two linear robberies:  
  - Exclude last  
  - Exclude first  

---

# **🧭 5. How to Recognize DP Problems Instantly**

### **Signs a problem is DP:**
- 🔁 Overlapping subproblems  
- 🧩 Optimal substructure  
- 🔀 Choices at each step  
- 🎯 Target or capacity constraints  
- 📈 Sequence or subsequence optimization  
- 🛣 Reachability or minimum steps  

### **If greedy fails → DP is usually the answer**

---

# **🧮 6. Space Optimization Principles**

### **When DP reduces to O(1):**
- Recurrence depends only on last 1–2 states  
Examples:  
- Fibonacci  
- House Robber  
- Kadane  
- Maximum Product Subarray  

### **When DP reduces to O(target):**
- Target DP  
- Knapsack  
- Subset Sum  

---

# **📜 7. Final Revision Checklist**

You should now be able to solve:

- 🏠 House Robber I & II  
- 📈 LIS (O(n²) and O(n log n))  
- 💰 Coin Change I & II  
- ⚖ Partition Equal Subset Sum  
- 🏃 Jump Game I & II  
- 📉 Maximum Subarray  
- ✖ Maximum Product Subarray  
- 🔥 Delete and Earn  
- 🪚 Rod Cutting  
- 🧗 Climbing Stairs  
- 🗺 Grid Paths  
- 💸 Minimum Cost Path  

If you can solve these confidently, your DP foundation is **interview‑ready**.

---

# **🏁 8. Conclusion**

Day 30 completes your **30‑Day DSA Mastery Series**.  
You now have:

- 🧠 A complete understanding of 1D DP patterns  
- 🎯 Strong recurrence‑design intuition  
- 🚀 Ability to solve medium/hard DP problems  
- 🧩 Pattern recognition skills  
- 💼 Interview‑ready confidence  

This theory chapter serves as your **long‑term DP reference**.

---

If you want, I can now generate:

- 📘 A **full DSA revision sheet**  
- 🧪 A **mock interview problem set**  
- 🧱 A **C++ template library**  
- 📅 A **100‑day LeetCode roadmap**  

Just tell me the direction you want to go next.
