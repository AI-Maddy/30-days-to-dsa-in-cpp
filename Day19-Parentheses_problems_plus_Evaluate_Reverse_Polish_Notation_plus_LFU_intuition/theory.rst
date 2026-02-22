---

# **Day 19 – 🔥 Parentheses Problems + 🧮 Reverse Polish Notation + 🧠 LFU Cache Intuition**  
`theory.rst`

---

# **🌈 1. Why Day 19 Matters**
Today’s patterns unlock:

- 🧱 Stack‑based parsing  
- 🧩 Expression evaluation  
- 🔁 Balanced parentheses logic  
- 🧠 LFU cache design intuition  
- 🧮 Operator precedence  
- 🧊 Frequency‑based eviction  

These are **core FAANG interview topics** across Amazon, Google, Meta, and Microsoft.

---

# **🌟 MEMORY ANCHOR: “P‑R‑L”**
Today’s 3 pillars:

- **P** – Parentheses  
- **R** – Reverse Polish Notation  
- **L** – LFU Cache  

Remember: **P‑R‑L** → Parse, Reverse Polish, Least Frequently Used.

---

# **🌈 2. Parentheses Problems (Stack Mastery)**

Parentheses problems are **stack classics**.  
They test your ability to:

- Track opening/closing  
- Validate structure  
- Compute depth  
- Remove invalid parentheses  
- Generate valid parentheses  

---

# **🌈 2.1 Valid Parentheses (Classic)**

### **🎯 Goal**
Check if parentheses string is valid.

### **🔥 Logic**
- Push opening brackets  
- Pop when matching closing bracket appears  
- If mismatch → invalid  

### **🧠 MEMORY TIP:**  
**Push opens → Pop closes**

---

# **🌈 2.2 Minimum Add to Make Parentheses Valid**

### **🎯 Goal**
Count how many parentheses must be added to make string valid.

### **🔥 Logic**
- Use counter or stack  
- Track unmatched opens and closes  

---

# **🌈 2.3 Longest Valid Parentheses (Hard)**

### **🎯 Goal**
Find longest valid parentheses substring.

### **🔥 Approaches**
- Stack of indices  
- DP  
- Two‑pointer left‑right scan  

### **🧠 MEMORY ANCHOR:**  
**Stack stores boundaries**

---

# **🌈 2.4 Remove Invalid Parentheses (Backtracking)**

### **🎯 Goal**
Remove minimum invalid parentheses to make string valid.

### **🔥 Logic**
- Count invalid opens/closes  
- Backtrack removing them  
- Validate each candidate  

---

# **🌈 2.5 Generate Parentheses (Backtracking)**

### **🎯 Goal**
Generate all valid parentheses combinations.

### **🔥 Logic**
- Use recursion  
- Track open and close count  

### **🧠 MEMORY TIP:**  
**Open ≤ n, Close ≤ Open**

---

# **🌈 3. Evaluate Reverse Polish Notation (RPN)**  
This is a **stack‑based expression evaluation** problem.

---

# **🌈 3.1 What is RPN?**

RPN (postfix notation) means:

```
3 4 +   = 7
5 1 2 + 4 * + 3 - = 14
```

Operators come **after** operands.

---

# **🌈 3.2 Why RPN is Powerful**
- No parentheses needed  
- No operator precedence issues  
- Stack evaluation is straightforward  

---

# **🌈 3.3 RPN Evaluation Logic**

### **🔥 Steps**
1. Traverse tokens  
2. If number → push  
3. If operator → pop two numbers  
4. Apply operator  
5. Push result  

---

## **🧠 MEMORY ANCHOR:**  
**Push numbers → Pop for operators**

---

# **🌈 3.4 Supported Operators**
- `+`  
- `-`  
- `*`  
- `/` (truncate toward zero)  

---

# **🌈 3.5 Example**
Input:
```
["2","1","+","3","*"]
```

Steps:
- 2 → push  
- 1 → push  
- + → pop 2,1 → push 3  
- 3 → push  
- * → pop 3,3 → push 9  

Output: **9**

---

# **🌈 4. LFU Cache Intuition (Design + HashMap + LinkedList)**  
This is a **system design + DSA hybrid** problem.

---

# **🌈 4.1 What is LFU?**

LFU = **Least Frequently Used** cache.

When cache is full:
- Evict the key with **lowest frequency**  
- If tie → evict **least recently used** among them  

---

# **🌈 4.2 Why LFU is Hard**
You must support:

- **get(key)** → O(1)  
- **put(key, value)** → O(1)  
- Frequency updates  
- Recency tracking  
- Eviction logic  

---

# **🌈 4.3 Data Structures Needed**

### **1️⃣ Key → Node Map**
Stores:
- key  
- value  
- frequency  

### **2️⃣ Frequency → Doubly Linked List**
Each frequency has its own list of nodes.

### **3️⃣ Min‑frequency tracker**
Tracks lowest frequency in cache.

---

# **🌈 4.4 LFU Operations**

---

## **🔥 get(key)**  
1. If key not found → return -1  
2. Increase frequency  
3. Move node to next frequency list  
4. Update min‑frequency if needed  

---

## **🔥 put(key, value)**  
1. If key exists → update + increase frequency  
2. If cache full → evict LFU node  
3. Insert new node with freq = 1  
4. Update min‑frequency  

---

# **🌈 4.5 Why LFU Uses DLL + HashMap**

- DLL → O(1) insert/delete  
- HashMap → O(1) lookup  
- Frequency map → O(1) frequency updates  

---

# **🌈 4.6 MEMORY ANCHOR: “F‑L‑M”**
LFU = **F**requency + **L**ist + **M**ap.

---

# **🌈 5. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to update frequency on get  
- 🚩 Not removing empty frequency lists  
- 🚩 Using queue instead of DLL  
- 🚩 Mishandling division in RPN  
- 🚩 Not checking stack underflow  
- 🚩 Forgetting to validate parentheses  
- 🚩 Mishandling negative numbers in RPN  

---

# **🌈 6. Problems You Can Now Solve**

### **Parentheses**
- Valid parentheses  
- Longest valid parentheses  
- Remove invalid parentheses  
- Generate parentheses  
- Minimum add to make valid  

### **RPN**
- Evaluate RPN  
- Infix → postfix  
- Postfix → infix  

### **LFU**
- LFU cache  
- LRU cache  
- MRU cache  
- Frequency‑based eviction problems  

---

# **🌈 7. What You Must Master Today**

- Stack‑based parentheses logic  
- RPN evaluation  
- Operator precedence  
- LFU cache architecture  
- Frequency + recency tracking  
- HashMap + DLL hybrid structures  

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Identify monotonic stack direction from query type.
- Map nearest-greater/smaller variants quickly.
- Use deque invariants for sliding window maximum.
- Explain amortized O(1) pop/push behavior.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Pushing indices vs values inconsistently.
- Forgetting to evict out-of-window indices.
- Wrong tie-handling (`>` vs `>=`) in monotonic logic.
- Mismatched push/pop causing invalid parenthesis checks to fail.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: valid parentheses, stack using queues.
- Medium: daily temperatures, stock span.
- Hard: largest rectangle + maximal rectangle variations.

