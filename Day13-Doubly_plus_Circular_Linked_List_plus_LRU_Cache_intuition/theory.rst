.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>


# **Day 13 – 🔥 Stacks + Monotonic Stacks + NGE/NS Patterns (Colorful Memory Edition)**  
`theory.rst`

---

# **🌈 1. Why Stacks Matter**
Stacks are the backbone of:

- 🧮 Expression evaluation  
- 🧱 Parentheses validation  
- 📈 Next greater/smaller element  
- 📊 Histogram problems  
- 🔥 Monotonic stack optimizations  
- 🧨 Removing elements greedily  
- 🧠 State tracking  

Stacks convert **nested**, **reversible**, and **dependency‑based** problems into elegant solutions.

---

# **🌟 MEMORY ANCHOR: “L‑I‑F‑O”**
Stack = **Last In, First Out**

Think of a stack of plates:
- Last plate placed → first removed.

---

# **🌈 2. Basic Stack Operations**

- **push(x)**  
- **pop()**  
- **top()**  
- **empty()**  

### **🧠 MEMORY TIP:**  
Stack = **Undo machine**.

---

# **🌈 3. Classic Stack Problems**

---

## **💙 Pattern 1: Valid Parentheses**
Push opening brackets, pop when matching closing bracket appears.

### **🧠 MEMORY ANCHOR:**  
**Push opens → Pop closes**

---

## **💚 Pattern 2: Min Stack**
Maintain:
- main stack  
- min stack  

### **🧠 MEMORY TIP:**  
Push new min when it becomes smaller.

---

## **💛 Pattern 3: Reverse Polish Notation (RPN)**
Use stack to evaluate postfix expressions.

---

# **🌈 4. Monotonic Stacks (The Real Power)**

Monotonic stacks maintain elements in **sorted order** (increasing or decreasing) while scanning.

---

# **🌟 MEMORY ANCHOR: “M‑S‑S”**
Monotonic Stack solves:

- **M**ax/min range problems  
- **S**pans  
- **S**urrounding greater/smaller  

---

# **🌈 5. Next Greater / Smaller Element Patterns**

---

## **💙 Pattern: Next Greater Element (NGE)**
Find next element to the right that is greater.

### **🎯 Logic**
Traverse from right → left  
Maintain decreasing stack  
Pop smaller elements  
Top of stack = NGE  

### **🧠 MEMORY TIP:**  
**Right → Left + Decreasing Stack**

---

## **💚 Pattern: Next Smaller Element (NSE)**
Same as NGE but maintain **increasing** stack.

---

## **💛 Pattern: Previous Greater/Smaller**
Same logic but traverse left → right.

---

# **🌈 6. Stock Span Problem**

Span = number of consecutive days before today with price ≤ today.

### **🎯 Logic**
Use **monotonic decreasing stack** of indices.

### **🧠 MEMORY ANCHOR:**  
**Pop all smaller or equal → compute span**

---

# **🌈 7. Daily Temperatures**

For each day, find next warmer day.

### **🎯 Logic**
Same as NGE but store indices.

---

# **🌈 8. Largest Rectangle in Histogram (LRH)**  
One of the most important monotonic stack problems.

---

## **🎯 Goal**
Find largest rectangle in histogram bars.

---

## **🔥 Logic**
1. Compute **NSL** (next smaller left)  
2. Compute **NSR** (next smaller right)  
3. Width = `right[i] - left[i] - 1`  
4. Area = `height[i] * width`  

### **🧠 MEMORY ANCHOR:**  
**NSL + NSR = LRH**

---

# **🌈 9. Maximal Rectangle (Matrix Version)**

Convert each row into histogram heights → apply LRH.

### **🧠 MEMORY TIP:**  
**Matrix → Histogram → LRH**

---

# **🌈 10. Remove K Digits (Greedy + Monotonic Stack)**

Remove digits to form smallest number.

### **🎯 Logic**
Use **increasing stack**  
Pop while top > current digit and k > 0  

### **🧠 MEMORY ANCHOR:**  
**Pop big digits early**

---

# **🌈 11. Asteroid Collision**

Use stack to simulate collisions.

### **🎯 Logic**
- Positive moves right  
- Negative moves left  
- Collide when directions oppose  

### **🧠 MEMORY TIP:**  
**Stack stores right‑moving asteroids**

---

# **🌈 12. Expression Evaluation**

---

## **💙 Infix → Postfix**
Use operator precedence + stack.

## **💚 Evaluate Postfix**
Use value stack.

---

# **🌈 13. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to pop until stack is valid  
- 🚩 Using wrong monotonic direction  
- 🚩 Not handling equal elements correctly  
- 🚩 Off‑by‑one in LRH width  
- 🚩 Forgetting to append sentinel bars in LRH  
- 🚩 Using stack when queue is needed  
- 🚩 Not clearing stack between passes  

---

# **🌈 14. Problems You Can Now Solve**

- Valid parentheses  
- Min stack  
- Reverse Polish notation  
- Next greater element  
- Next smaller element  
- Stock span  
- Daily temperatures  
- Largest rectangle in histogram  
- Maximal rectangle  
- Remove K digits  
- Asteroid collision  
- Evaluate expressions  
- Previous greater/smaller  
- Sliding window maximum (monotonic deque)  

---

# **🌈 15. What You Must Master Today**

- Stack fundamentals  
- Monotonic increasing/decreasing stacks  
- NGE/NS patterns  
- Stock span  
- Daily temperatures  
- LRH + Maximal rectangle  
- Greedy + stack hybrids  
- Expression evaluation  
- Asteroid collision logic
