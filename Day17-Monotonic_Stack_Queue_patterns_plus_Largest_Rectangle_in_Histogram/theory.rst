---

# **Day 17 – 🔥 Monotonic Stack + Monotonic Queue Patterns + Largest Rectangle in Histogram**  
`theory.rst`

---

# **🌈 1. Why Day 17 Matters**
Monotonic stacks and queues are the **weapons of O(n)** solutions for problems that look like O(n²).

They help you solve:

- 📈 Range queries  
- 📉 Next greater/smaller  
- 🧱 Histogram area  
- 🧊 Sliding window maximum  
- 🌡️ Daily temperatures  
- 🧩 Structural array problems  
- 🧮 Window min/max in O(1)  

Mastering these patterns unlocks **dozens** of FAANG problems.

---

# **🌟 MEMORY ANCHOR: “S‑Q‑H”**
Today’s 3 pillars:

- **S** – Monotonic Stack  
- **Q** – Monotonic Queue  
- **H** – Histogram (LRH)

Remember: **S‑Q‑H** → Stack, Queue, Histogram.

---

# **🌈 2. Monotonic Stack Patterns (Deep Dive)**

A **monotonic stack** maintains elements in sorted order:

- **Increasing stack** → top is smallest  
- **Decreasing stack** → top is largest  

### **🧠 MEMORY TIP:**  
**Increasing stack finds smaller**  
**Decreasing stack finds greater**

---

# **🌈 3. Pattern 1: Next Greater Element (NGE)**

### **🎯 Goal**
For each index `i`, find first `j > i` with `arr[j] > arr[i]`.

### **🔥 Logic**
- Traverse **right → left**  
- Maintain **decreasing stack**  
- Pop smaller elements  
- Top = NGE  

### **🧠 MEMORY ANCHOR:**  
**Right → Left + Pop smaller → Top is greater**

---

# **🌈 4. Pattern 2: Next Smaller Element (NSE)**

### **🎯 Goal**
Find first `j > i` with `arr[j] < arr[i]`.

### **🔥 Logic**
- Traverse **right → left**  
- Maintain **increasing stack**  
- Pop bigger elements  
- Top = NSE  

### **🧠 MEMORY TIP:**  
**Right → Left + Pop bigger → Top is smaller**

---

# **🌈 5. Pattern 3: Previous Greater / Previous Smaller**

Mirror versions of NGE/NSE.

### **🔥 Logic**
- Traverse **left → right**  
- Use same stack type as NGE/NSE  

### **🧠 MEMORY TIP:**  
Direction flips → stack type stays same.

---

# **🌈 6. Pattern 4: Stock Span Problem**

### **🎯 Goal**
For each day, count consecutive previous days with price ≤ today.

### **🔥 Logic**
- Traverse left → right  
- Maintain **decreasing stack** of indices  
- Pop all ≤ current  
- Span = i − top  

### **🧠 MEMORY ANCHOR:**  
**Pop smaller → compute span**

---

# **🌈 7. Pattern 5: Daily Temperatures (NGE Variant)**

### **🎯 Goal**
For each day, find next warmer day.

### **🔥 Logic**
Same as NGE but store **indices**.

---

# **🌈 8. Pattern 6: Largest Rectangle in Histogram (LRH)**  
This is the **ultimate monotonic stack problem**.

---

## **🎯 Goal**
Find the largest rectangle area in histogram bars.

---

## **🔥 Core Idea**
For each bar, find:

- **NSL** → Next Smaller to Left  
- **NSR** → Next Smaller to Right  

Then:

```
width = NSR[i] - NSL[i] - 1
area = height[i] * width
```

---

## **🧠 MEMORY ANCHOR:**  
**NSL + NSR = LRH**

---

## **🔥 Steps**
### **1. Compute NSL**
- Traverse left → right  
- Use **increasing stack**  
- Pop ≥ current  

### **2. Compute NSR**
- Traverse right → left  
- Use **increasing stack**  
- Pop ≥ current  

### **3. Compute area for each bar**

---

## **🎨 Example**
Heights: `[2, 1, 5, 6, 2, 3]`

Largest area = **10** (bars 5 & 6)

---

# **🌈 9. Pattern 7: Maximal Rectangle (Matrix Version)**

### **🎯 Idea**
Convert each row into histogram heights → apply LRH.

### **🧠 MEMORY TIP:**  
**Matrix → Histogram → LRH**

---

# **🌈 10. Monotonic Queue Patterns (Deep Dive)**

A **monotonic queue** maintains elements in sorted order while supporting:

- Push  
- Pop  
- Get max/min  

All in **O(1)** amortized time.

---

# **🌈 11. Pattern 8: Sliding Window Maximum**

### **🎯 Goal**
For each window of size k, find max.

---

## **🔥 Logic**
Use **monotonic decreasing deque**:

- Pop from back while smaller  
- Push new element  
- Pop from front if out of window  
- Front = max  

---

## **🧠 MEMORY ANCHOR:**  
**Back pops smaller → front holds max**

---

# **🌈 12. Pattern 9: Sliding Window Minimum**

Same as above but use **increasing deque**.

---

# **🌈 13. Pattern 10: Shortest Subarray With Sum ≥ K (Hard)**

Uses **monotonic deque** on prefix sums.

---

# **🌈 14. Pattern 11: Trapping Rain Water (Stack Variant)**

Use stack to find boundaries.

---

# **🌈 15. Pitfalls (Red Flags 🚩)**

- 🚩 Using wrong stack type (increasing vs decreasing)  
- 🚩 Forgetting to pop until stack is valid  
- 🚩 Not storing indices when needed  
- 🚩 Off‑by‑one in LRH width  
- 🚩 Forgetting to clear stack between passes  
- 🚩 Using stack instead of deque for sliding window  
- 🚩 Not handling equal elements correctly  

---

# **🌈 16. Problems You Can Now Solve**

- Next Greater Element  
- Next Smaller Element  
- Previous Greater/Smaller  
- Stock Span  
- Daily Temperatures  
- Largest Rectangle in Histogram  
- Maximal Rectangle  
- Sliding Window Maximum  
- Sliding Window Minimum  
- Trapping Rain Water  
- Shortest subarray with sum ≥ K  
- All monotonic stack/queue variants  

---

# **🌈 17. What You Must Master Today**

- Monotonic increasing/decreasing stacks  
- Monotonic queues (deque)  
- NGE/NSE/PGE/PSE  
- Stock Span  
- LRH (Largest Rectangle in Histogram)  
- Maximal Rectangle  
- Sliding window max/min  
- Stack vs deque decision making  

---
