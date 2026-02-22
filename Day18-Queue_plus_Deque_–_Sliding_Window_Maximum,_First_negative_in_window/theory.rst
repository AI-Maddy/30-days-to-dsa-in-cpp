---

# **Day 18 – 🚀 Queue + Deque Mastery: Sliding Window Maximum & First Negative in Window**  
`theory.rst`

---

# **🌈 1. Why Day 18 Matters**
Sliding window problems are everywhere in:

- Arrays  
- Streams  
- Real‑time analytics  
- Signal processing  
- Stock price analysis  
- Temperature tracking  
- Windowed queries  

Queues and deques allow you to solve these in **O(n)** instead of **O(n·k)**.

Today you master:

- 🔥 Monotonic Deque  
- 🔥 Sliding Window Maximum  
- 🔥 Sliding Window Minimum  
- 🔥 First Negative in Window  
- 🔥 Window processing patterns  

---

# **🌟 MEMORY ANCHOR: “W‑Q‑D”**
Three pillars of today:

- **W** – Window  
- **Q** – Queue  
- **D** – Deque  

Remember: **W‑Q‑D** → Window + Queue + Deque.

---

# **🌈 2. Queue Fundamentals (Quick Refresher)**

Queue = **FIFO**  
- First In → First Out  
- Perfect for tracking order  
- Used for:  
  - First negative  
  - First positive  
  - Window frequency  

### **🧠 MEMORY TIP:**  
Queue = **line of people**.

---

# **🌈 3. Deque Fundamentals (The Real Power)**

Deque = **Double‑Ended Queue**  
Supports:

- Push front  
- Push back  
- Pop front  
- Pop back  

This makes it perfect for **monotonic window structures**.

---

# **🌟 MEMORY ANCHOR: “Back pops, Front answers”**
- Back → maintain monotonicity  
- Front → holds the answer  

---

# **🌈 4. Sliding Window Maximum (Monotonic Deque)**  
This is one of the **top 10 most important DSA patterns**.

---

## **🎯 Goal**
For each window of size `k`, find the **maximum** element.

---

## **🔥 Core Idea**
Use a **monotonic decreasing deque** storing **indices**.

---

## **🔥 Steps (The Golden Template)**

### **1️⃣ Remove out‑of‑window elements**
If `dq.front() <= i - k` → pop front.

### **2️⃣ Maintain decreasing order**
While `arr[dq.back()] < arr[i]` → pop back.

### **3️⃣ Push current index**
Push `i`.

### **4️⃣ Window max = arr[dq.front()]**

---

## **🧠 MEMORY ANCHOR:**  
**Back pops smaller → Front holds max**

---

## **🎨 Example**
Array: `[1,3,-1,-3,5,3,6,7]`, k = 3  
Output: `[3,3,5,5,6,7]`

---

# **🌈 5. Why Monotonic Deque Works (Intuition)**

- Back pops ensure deque is **strictly decreasing**  
- Front always holds **max element**  
- Out‑of‑window elements are removed  
- Each element is pushed/popped **at most once** → O(n)

---

# **🌈 6. Sliding Window Minimum (Bonus)**

Same as maximum but maintain **monotonic increasing deque**.

### **🧠 MEMORY TIP:**  
**Back pops bigger → Front holds min**

---

# **🌈 7. First Negative Number in Every Window**  
This is the **classic queue‑based** window problem.

---

## **🎯 Goal**
For each window of size `k`, return the **first negative number**.

---

## **🔥 Core Idea**
Use a **simple queue** to store **indices of negative numbers**.

---

## **🔥 Steps**

### **1️⃣ Add negative numbers**
If `arr[i] < 0`, push index into queue.

### **2️⃣ Remove out‑of‑window negatives**
If `q.front() <= i - k`, pop front.

### **3️⃣ Window answer**
- If queue not empty → `arr[q.front()]`  
- Else → `0` or `None`  

---

## **🧠 MEMORY ANCHOR:**  
**Queue stores negatives → front is first negative**

---

## **🎨 Example**
Array: `[12, -1, -7, 8, -15, 30, 16, 28]`, k = 3  
Output: `[-1, -1, -7, -15, -15, 0]`

---

# **🌈 8. Pattern Extensions**

---

## **💙 First Positive in Window**
Same logic, track positives.

---


---

## **💛 Window Sum / Window Average**
Use sliding window sum.

---

## **❤️ Window Distinct Count**
Use HashMap + sliding window.

---

## **💜 Window Max/Min**
Use monotonic deque.

---

# **🌈 9. Monotonic Queue Template (Universal)**

```
while dq not empty and dq.back() < current:
    dq.pop_back()

dq.push_back(i)

if dq.front() <= i - k:
    dq.pop_front()

answer = arr[dq.front()]
```

### **🧠 MEMORY TIP:**  
**Pop back for monotonicity, pop front for window validity.**

---

# **🌈 10. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to remove out‑of‑window indices  
- 🚩 Storing values instead of indices  
- 🚩 Using queue instead of deque for max/min  
- 🚩 Not maintaining monotonic order  
- 🚩 Off‑by‑one errors in window boundaries  
- 🚩 Forgetting that each element is pushed/popped once  

---

# **🌈 11. Problems You Can Now Solve**

- Sliding Window Maximum  
- Sliding Window Minimum  
- First Negative in Window  
- First Positive in Window  
- Count negatives in window  
- Window sum / average  
- Window distinct count  
- Window frequency map  
- Window median (advanced)  
- Window Kth largest (heap)  

---

# **🌈 12. What You Must Master Today**

- Queue fundamentals  
- Deque operations  
- Monotonic decreasing deque  
- Sliding window maximum  
- Sliding window minimum  
- First negative in window  
- Index‑based window logic  
- O(n) window processing  

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

