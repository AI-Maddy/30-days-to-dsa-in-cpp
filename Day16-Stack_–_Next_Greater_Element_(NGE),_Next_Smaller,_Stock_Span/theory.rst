.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>


# **Day 16 – 🔥 Stack Mastery: NGE, NSE, Stock Span (Colorful Memory Edition)**  
`theory.rst`

---

# **🌈 1. Why Day 16 Matters**
Today’s patterns unlock the **core monotonic stack logic** used in dozens of FAANG problems.

You will master:

- 🔥 Next Greater Element (NGE)  
- 🔥 Next Smaller Element (NSE)  
- 🔥 Stock Span  
- 🔥 Previous Greater/Smaller variants  
- 🔥 Monotonic increasing/decreasing stacks  
- 🔥 Index‑based stack tricks  

These patterns convert **O(n²)** brute force into **O(n)** elegance.

---

# **🌟 MEMORY ANCHOR: “N‑N‑S”**
Today’s 3 pillars:

- **N** – Next Greater  
- **N** – Next Smaller  
- **S** – Stock Span  

Remember: **N‑N‑S** → the holy trinity of monotonic stacks.

---

# **🌈 2. Monotonic Stack Fundamentals**

A **monotonic stack** maintains elements in sorted order:

- **Monotonic Increasing Stack**  
  - Top is **smallest**  
  - Used for **Next Smaller**, **Previous Smaller**

- **Monotonic Decreasing Stack**  
  - Top is **largest**  
  - Used for **Next Greater**, **Previous Greater**

### **🧠 MEMORY TIP:**  
**Increasing stack → finds smaller**  
**Decreasing stack → finds greater**

---

# **🌈 3. Pattern 1: Next Greater Element (NGE)**  
Find the next element to the **right** that is **greater**.

---

## **🎯 Goal**
For each index `i`, find the first `j > i` such that:

```
arr[j] > arr[i]
```

---

## **🔥 Logic (Right → Left + Decreasing Stack)**

### **Steps**
1. Traverse from **right to left**  
2. Maintain a **monotonic decreasing stack**  
3. Pop all elements ≤ current  
4. Top of stack = NGE  
5. Push current element  

---

## **🧠 MEMORY ANCHOR:**  
**Right → Left + Pop smaller → Top is greater**

---

## **🎨 Example**
Array: `[2, 5, 3, 7, 1]`

NGE: `[5, 7, 7, -1, -1]`

---

# **🌈 4. Pattern 2: Next Smaller Element (NSE)**  
Find the next element to the **right** that is **smaller**.

---

## **🎯 Goal**
For each index `i`, find first `j > i` such that:

```
arr[j] < arr[i]
```

---

## **🔥 Logic (Right → Left + Increasing Stack)**

### **Steps**
1. Traverse from **right to left**  
2. Maintain **monotonic increasing stack**  
3. Pop all elements ≥ current  
4. Top of stack = NSE  
5. Push current  

---

## **🧠 MEMORY ANCHOR:**  
**Right → Left + Pop bigger → Top is smaller**

---

## **🎨 Example**
Array: `[4, 8, 5, 2, 25]`

NSE: `[2, 5, 2, -1, -1]`

---

# **🌈 5. Pattern 3: Previous Greater / Previous Smaller**

These are the **mirror** versions of NGE/NSE.

---

## **💙 Previous Greater Element (PGE)**
Traverse **left → right**, maintain **decreasing stack**.

## **💚 Previous Smaller Element (PSE)**
Traverse **left → right**, maintain **increasing stack**.

---

## **🧠 MEMORY TIP:**  
**Direction flips → stack type stays same**

---

# **🌈 6. Pattern 4: Stock Span Problem**

This is one of the most famous monotonic stack problems.

---

## **🎯 Goal**
For each day, find how many consecutive previous days had price ≤ today.

---

## **🔥 Logic**
1. Traverse left → right  
2. Maintain **monotonic decreasing stack** of indices  
3. Pop all prices ≤ current  
4. Span = current_index − top_index  
5. Push current index  

---

## **🧠 MEMORY ANCHOR:**  
**Pop all smaller → compute span**

---

## **🎨 Example**
Prices: `[100, 80, 60, 70, 60, 75, 85]`

Span: `[1, 1, 1, 2, 1, 4, 6]`

---

# **🌈 7. Pattern 5: Daily Temperatures (NGE Variant)**

For each day, find next warmer day.

### **Logic**
Same as NGE but store **indices**.

---

# **🌈 8. Pattern 6: Largest Rectangle in Histogram (LRH)**  
This is the **ultimate** monotonic stack problem.

---

## **🎯 Goal**
For each bar, find:
- Next Smaller Right (NSR)  
- Next Smaller Left (NSL)  

Width = `right[i] - left[i] - 1`  
Area = `height[i] * width`

---

## **🧠 MEMORY ANCHOR:**  
**NSL + NSR = LRH**

---

# **🌈 9. Pattern 7: Maximal Rectangle (Matrix Version)**

Convert each row into histogram heights → apply LRH.

---

# **🌈 10. Pattern 8: Remove K Digits (Greedy + Monotonic Stack)**

Use **increasing stack** to remove larger digits early.

---

# **🌈 11. Pattern 9: Asteroid Collision**

Use stack to simulate collisions.

---

# **🌈 12. Pitfalls (Red Flags 🚩)**

- 🚩 Using wrong stack type (increasing vs decreasing)  
- 🚩 Forgetting to pop until stack is valid  
- 🚩 Not handling equal elements correctly  
- 🚩 Off‑by‑one errors in Stock Span  
- 🚩 Forgetting to push indices instead of values  
- 🚩 Not clearing stack between passes  
- 🚩 Using stack when deque is needed (sliding window max)  

---

# **🌈 13. Problems You Can Now Solve**

- Next Greater Element  
- Next Smaller Element  
- Previous Greater/Smaller  
- Stock Span  
- Daily Temperatures  
- Largest Rectangle in Histogram  
- Maximal Rectangle  
- Remove K Digits  
- Asteroid Collision  
- Monotonic stack variants  
- Sliding Window Maximum (deque)  

---

# **🌈 14. What You Must Master Today**

- Monotonic increasing/decreasing stacks  
- NGE, NSE, PGE, PSE  
- Stock Span  
- Index‑based stack logic  
- LRH + Maximal Rectangle  
- Greedy + stack hybrids  
- Stack‑based simulation problems
