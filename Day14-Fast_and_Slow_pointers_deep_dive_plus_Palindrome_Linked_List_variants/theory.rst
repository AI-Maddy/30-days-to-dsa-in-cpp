---

# **Day 14 – ⚡ Fast & Slow Pointers Deep Dive + 🔁 Palindrome Linked List Variants**  
`theory.rst`

---

# **🌈 1. Why Fast & Slow Pointers Matter**
The **fast & slow pointer technique** (also called **tortoise & hare**) is the most elegant way to solve linked list problems that involve:

- 🌀 Cycles  
- 🎯 Middle detection  
- 🔁 Palindromes  
- 🔗 Intersection  
- 🧩 Reordering  
- 🧮 Length parity  
- 🧵 Splitting lists  
- 🧠 Detecting structural patterns  

This technique reduces many problems from **O(n) space → O(1) space**.

---

# **🌟 MEMORY ANCHOR: “F‑S‑M‑C‑P”**
Fast & Slow pointers solve:

- **F**ind middle  
- **S**plit list  
- **M**easure parity  
- **C**ycle detection  
- **P**alindrome check  

Remember: **F‑S‑M‑C‑P** → the five pillars of fast & slow pointers.

---

# **🌈 2. Core Concept: Fast vs Slow Movement**

- **Slow pointer** → moves **1 step**  
- **Fast pointer** → moves **2 steps**  

### **🧠 MEMORY TIP:**  
Fast pointer “jumps”, slow pointer “walks”.

---

# **🌈 3. Pattern 1: Find Middle of Linked List**

---

## **🎯 Goal**
Return the middle node.

### **Logic**
- Move slow by 1  
- Move fast by 2  
- When fast reaches end → slow is at middle  

---

## **💡 Odd vs Even Length**
- Odd length → slow lands exactly on middle  
- Even length → slow lands on **second middle**  

### **🧠 MEMORY ANCHOR:**  
**Fast ends → Slow centers**

---

# **🌈 4. Pattern 2: Detect Cycle (Floyd’s Algorithm)**

---

## **🎯 Goal**
Detect if cycle exists.

### **Logic**
- Move slow = +1  
- Move fast = +2  
- If they ever meet → cycle exists  

### **🧠 MEMORY TIP:**  
**If fast catches slow → loop exists**

---

# **🌈 5. Pattern 3: Find Start of Cycle**

---

## **🎯 Steps**
1. Detect cycle (fast meets slow)  
2. Reset slow to head  
3. Move both slow & fast by 1  
4. Where they meet = cycle start  

### **🧠 MEMORY ANCHOR:**  
**Meet → Reset → Walk → Meet again**

---

# **🌈 6. Pattern 4: Check if Linked List is Palindrome**

This is one of the most important linked list interview problems.

---

## **🎯 Steps**
1. Find middle using fast & slow  
2. Reverse second half  
3. Compare first half & reversed second half  
4. (Optional) Restore list  

---

## **🧠 MEMORY ANCHOR: “M‑R‑C‑R”**
- **M**iddle  
- **R**everse  
- **C**ompare  
- **R**estore  

---

# **🌈 7. Palindrome Linked List Variants**

---

## **💙 Variant 1: Restore the List After Checking**
After comparing halves, reverse second half again.

### **Why?**
To preserve original structure.

---

## **💚 Variant 2: Palindrome with Odd Length**
Middle node is ignored.

### **🧠 MEMORY TIP:**  
Skip the middle element when comparing.

---

## **💛 Variant 3: Palindrome Without Modifying List**
Use recursion (but uses O(n) stack).

---

## **❤️ Variant 4: Palindrome Using Stack**
Push first half → compare with second half.

---

## **💜 Variant 5: Palindrome Using Array**
Copy values → check with two pointers.

---

# **🌈 8. Pattern 5: Remove Nth Node From End**

---

## **🎯 Logic**
Use two pointers:
- Move fast n steps  
- Move slow & fast together  
- When fast hits end → slow is before target  

### **🧠 MEMORY ANCHOR:**  
**Fast leads → Slow deletes**

---

# **🌈 9. Pattern 6: Intersection of Two Linked Lists**

---

## **🎯 Logic**
Use two pointers:
- Move A pointer through A then B  
- Move B pointer through B then A  
- They meet at intersection  

### **🧠 MEMORY TIP:**  
**Equalize path lengths by switching heads**

---

# **🌈 10. Pattern 7: Reorder List (L0 → Ln → L1 → Ln‑1 …)**

---

## **🎯 Steps**
1. Find middle  
2. Reverse second half  
3. Merge two halves  

### **🧠 MEMORY ANCHOR:**  
**M‑R‑M**  
Middle → Reverse → Merge

---

# **🌈 11. Pattern 8: Check If Length Is Odd or Even**

---

## **🎯 Logic**
- If fast ends at null → even  
- If fast ends at last node → odd  

### **🧠 MEMORY TIP:**  
**Fast pointer reveals parity**

---

# **🌈 12. Pattern 9: Split Linked List Into Two Halves**

---

## **🎯 Logic**
Use fast & slow to find middle → split.

---

# **🌈 13. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to check `fast && fast->next`  
- 🚩 Forgetting to skip middle node in palindrome odd case  
- 🚩 Not restoring list after palindrome check  
- 🚩 Infinite loops due to wrong pointer movement  
- 🚩 Reversing wrong half  
- 🚩 Using recursion for large lists (stack overflow)  
- 🚩 Forgetting to handle 1‑node or 2‑node lists  

---

# **🌈 14. Problems You Can Now Solve**

- Middle of linked list  
- Detect cycle  
- Find start of cycle  
- Palindrome linked list  
- Remove Nth node from end  
- Intersection of linked lists  
- Reorder list  
- Split list  
- Odd/even length detection  
- Check if list is circular  
- Reverse second half  
- Merge two halves  

---

# **🌈 15. What You Must Master Today**

- Fast & slow pointer fundamentals  
- Cycle detection + cycle start  
- Palindrome linked list (all variants)  
- Remove Nth node from end  
- Intersection logic  
- Reorder list  
- Splitting lists  
- Parity detection  
- Reversing linked list halves  

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Draw pointer transitions before coding.
- Know dummy-node pattern for head-sensitive operations.
- Apply fast-slow pointer for cycle, middle, palindrome.
- Track ownership/memory safety for node deletion.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Losing next pointer before rewiring.
- Not handling 0/1-node edge cases.
- Incorrect split before merge sort on lists.
- Cycle detection logic that dereferences null.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: reverse list, middle node.
- Medium: remove Nth from end, detect cycle.
- Hard: flatten multilevel list, merge k sorted lists.

