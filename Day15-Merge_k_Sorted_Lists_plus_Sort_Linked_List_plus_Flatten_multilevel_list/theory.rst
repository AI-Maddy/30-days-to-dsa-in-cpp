---

# **Day 15 – 🔥 Merge k Sorted Lists + Sort Linked List + Flatten Multilevel List**  
`theory.rst`

---

# **🌈 1. Why Day 15 Matters**
Today’s patterns unlock the **elite tier** of linked list problem‑solving:

- 🔗 Merging multiple sorted lists  
- 🧠 Sorting linked lists using merge sort  
- 🧩 Flattening multi‑level linked lists  
- 🔁 Recursion + merging + pointer rewiring  
- ⚙️ Priority queue + linked list hybrids  

These are **top‑tier FAANG interview problems**.

---

# **🌟 MEMORY ANCHOR: “M‑S‑F”**
Today’s 3 pillars:

- **M** – Merge k sorted lists  
- **S** – Sort linked list  
- **F** – Flatten multilevel list  

Remember: **M‑S‑F** → the 3 advanced transformations.

---

# **🌈 2. Pattern 1: Merge k Sorted Lists**

This is one of the most famous linked list problems.

---

## **🎯 Goal**
Merge **k** sorted linked lists into one sorted list.

---

## **🔥 Approach 1: Min‑Heap (Priority Queue)**  
Time: **O(N log k)**  
Space: **O(k)**

### **Steps**
1. Push head of each list into min‑heap  
2. Pop smallest node  
3. Append to result  
4. Push next node from popped list  
5. Repeat  

---

## **🧠 MEMORY ANCHOR:**  
**Heap picks smallest → append → push next**

---

## **🔥 Approach 2: Divide & Conquer**  
Time: **O(N log k)**  
Space: **O(1)** (besides recursion)

### **Steps**
1. Pair lists and merge  
2. Repeat until one list remains  

---

## **🧠 MEMORY TIP:**  
**Merge K = Merge 2 repeatedly**

---

## **🔥 Approach 3: Brute Force (Not recommended)**  
Concatenate all → sort → rebuild list  
Time: O(N log N)

---

# **🌈 3. Pattern 2: Sort Linked List (Merge Sort)**

Linked lists cannot use quicksort efficiently because:

- No random access  
- Partitioning is expensive  

Merge sort is perfect because:

- Splitting is easy (fast & slow pointers)  
- Merging is easy (two pointers)  

---

## **🎯 Goal**
Sort linked list in **O(n log n)** time and **O(1)** extra space.

---

## **🔥 Steps**
1. Find middle using fast & slow  
2. Split list into two halves  
3. Sort left half  
4. Sort right half  
5. Merge two sorted halves  

---

## **🧠 MEMORY ANCHOR:**  
**M‑S‑M**  
Middle → Sort → Merge

---

## **🎨 Example**
List: `4 → 2 → 1 → 3`

Split:  
`4 → 2` and `1 → 3`

Sort each:  
`2 → 4` and `1 → 3`

Merge:  
`1 → 2 → 3 → 4`

---

# **🌈 4. Pattern 3: Flatten Multilevel Linked List**

Nodes have:
- next  
- child  

This structure appears in:
- File systems  
- Nested lists  
- Multilevel menus  
- Interview problems  

---

## **🎯 Goal**
Flatten into a single‑level linked list.

---

## **🔥 Approach 1: DFS (Recursive)**  
Time: O(N)  
Space: O(depth)

### **Steps**
1. Traverse list  
2. When child exists:  
   - Flatten child  
   - Insert between node and next  
3. Continue traversal  

---

## **🧠 MEMORY TIP:**  
**Child → Flatten → Stitch**

---

## **🔥 Approach 2: Iterative (Stack)**  
Use stack to simulate DFS.

---

## **🔥 Approach 3: Merge‑Based Flattening**  
If child lists are sorted, use merge logic.

---

# **🌈 5. Pattern 4: Merge Two Sorted Lists (Foundation)**

This is the building block for:

- Merge k lists  
- Merge sort  
- Flattening sorted lists  

---

## **🎯 Logic**
Use two pointers:
- Pick smaller node  
- Move pointer  
- Append to result  

---

## **🧠 MEMORY ANCHOR:**  
**Smallest wins → move pointer**

---

# **🌈 6. Pattern 5: Multi‑Pointer Rewiring**

These problems require:

- prev  
- next  
- child  
- tail  
- recursion  
- merging  

### **🧠 MEMORY TIP:**  
**Always track: head, tail, next, child**

---

# **🌈 7. Pitfalls (Red Flags 🚩)**

- 🚩 Forgetting to update next pointers  
- 🚩 Losing child pointers during flattening  
- 🚩 Incorrect prev pointers in doubly linked lists  
- 🚩 Forgetting to break child links  
- 🚩 Infinite loops due to wrong rewiring  
- 🚩 Not handling empty lists  
- 🚩 Forgetting to check null before accessing next  

---

# **🌈 8. Problems You Can Now Solve**

- Merge k sorted lists  
- Merge two sorted lists  
- Sort linked list  
- Flatten multilevel linked list  
- Flatten multilevel doubly linked list  
- Merge sort on linked list  
- Deep structural rewiring  
- Multi‑pointer recursion problems  
- K‑way merging problems  

---

# **🌈 9. What You Must Master Today**

- Priority queue merging  
- Divide & conquer merging  
- Merge sort for linked lists  
- Flattening multi‑level lists  
- Pointer rewiring  
- Recursion + merging  
- Handling child pointers  
- Maintaining next/prev integrity  

---
