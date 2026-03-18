.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>


# **Day 1 – THEORY.rst**  
## **🚀 C++ STL Mastery – Containers, Iterators, Algorithms, Patterns**

---

# **🌟 1. Overview**

Day 1 launches your 30‑day DSA journey with one of the most powerful tools in modern C++:

# **🧰 The Standard Template Library (STL)**

STL gives you:

- ⚡ Fast, optimized data structures  
- 🧠 Ready‑made algorithms  
- 🔄 Iterators for seamless traversal  
- 🧱 Reusable components  
- 🚀 Competitive‑programming‑level speed  

Mastering STL is like unlocking **superpowers** in C++.

---

# **📦 2. STL Components (The Holy Trinity)**

STL is built on **three pillars**:

---

## **1️⃣ Containers (Data Structures)**  
Hold data.

Examples:  
- 🟦 `vector`  
- 🟩 `deque`  
- 🟨 `list`  
- 🟥 `stack`  
- 🟪 `queue`  
- 🟧 `priority_queue`  
- 🟫 `set`, `unordered_set`  
- 🟩 `map`, `unordered_map`  

---

## **2️⃣ Iterators (Pointers on Steroids)**  
Traverse containers.

Types:  
- ➡ Forward  
- ↔ Bidirectional  
- 🔁 Random access  

---

## **3️⃣ Algorithms (Pre‑built Logic)**  
Perform operations like:

- 🔍 Searching  
- 🔄 Sorting  
- 🧹 Removing  
- 🧮 Counting  
- 🧩 Transforming  

Examples:  
`sort`, `reverse`, `count`, `accumulate`, `lower_bound`, `upper_bound`, `binary_search`

---

# **🧱 3. Containers – Deep Dive**

---

## **🟦 3.1 vector – The Workhorse**

### **Why it’s amazing**
- Dynamic resizing  
- Random access  
- Cache‑friendly  
- Fast for push_back  

### **Key operations**
- `push_back()`  
- `pop_back()`  
- `size()`  
- `capacity()`  
- `reserve()`  
- `shrink_to_fit()`  

### **Time complexities**
- Access: **O(1)**  
- Insert at end: **Amortized O(1)**  
- Insert in middle: **O(n)**  

---

## **🟩 3.2 deque – Double‑Ended Vector**

### **Why it’s useful**
- Fast push/pop at **both ends**  
- Used in sliding window problems  

### **Time complexities**
- push_front: **O(1)**  
- push_back: **O(1)**  
- random access: **O(1)**  

---

## **🟨 3.3 list – Doubly Linked List**

### **Why it’s useful**
- Fast insert/delete anywhere  
- Stable iterators  

### **Time complexities**
- Insert/delete: **O(1)**  
- Access: **O(n)**  

---

## **🟥 3.4 stack – LIFO**

Built on vector/deque/list.

Used in:  
- Parentheses problems  
- DFS  
- Expression evaluation  

---

## **🟪 3.5 queue – FIFO**

Used in:  
- BFS  
- Level order traversal  
- Scheduling  

---

## **🟧 3.6 priority_queue – Max Heap**

### **Why it’s powerful**
- Always gives largest element  
- Used in Dijkstra, heaps, scheduling  

### **Min‑heap trick**
```
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## **🟫 3.7 set / unordered_set**

### **set**
- Balanced BST  
- Sorted  
- O(log n) operations  

### **unordered_set**
- Hash table  
- O(1) average  
- Not sorted  

---

## **🟩 3.8 map / unordered_map**

### **map**
- Sorted keys  
- O(log n)  

### **unordered_map**
- Hash table  
- O(1) average  
- Most used in coding interviews  

---

# **🧭 4. Iterators – The Glue of STL**

Iterators behave like pointers.

### **Types**
- `begin()`  
- `end()`  
- `rbegin()`  
- `rend()`  
- `cbegin()`  
- `cend()`  

### **Common patterns**
```
for (auto it = v.begin(); it != v.end(); it++)
```

---

# **⚙️ 5. STL Algorithms – The Real Power**

---

## **🟦 5.1 Sorting**

```
sort(v.begin(), v.end());
```

### **Custom comparator**
```
sort(v.begin(), v.end(), [](int a, int b){
    return a > b;
});
```

---

## **🟩 5.2 Searching**

### **Binary search**
```
binary_search(v.begin(), v.end(), x);
```

### **lower_bound**
First element >= x

### **upper_bound**
First element > x

---

## **🟨 5.3 Useful algorithms**

- `reverse()`  
- `max_element()`  
- `min_element()`  
- `accumulate()`  
- `count()`  
- `unique()`  
- `erase()`  

---

# **🧠 6. STL Patterns You Must Memorize**

---

## **Pattern 1 — Frequency Map**
```
unordered_map<int,int> mp;
for (int x : a) mp[x]++;
```

---

## **Pattern 2 — Sorting Pairs**
```
vector<pair<int,int>> v;
sort(v.begin(), v.end());
```

---

## **Pattern 3 — Using priority_queue for k largest**
```
priority_queue<int> pq;
```

---

## **Pattern 4 — Using set for unique sorted values**
```
set<int> s(a.begin(), a.end());
```

---

## **Pattern 5 — Two‑pointer with vector**
```
int i = 0, j = n-1;
while (i < j) { ... }
```

---

# **📘 7. Time & Space Complexity of STL Containers**

| Container | Access | Insert | Delete | Search |
|----------|--------|--------|--------|--------|
| vector | O(1) | O(n) | O(n) | O(n) |
| deque | O(1) | O(1) | O(1) | O(n) |
| list | O(n) | O(1) | O(1) | O(n) |
| set | O(log n) | O(log n) | O(log n) | O(log n) |
| unordered_set | O(1) avg | O(1) avg | O(1) avg | O(1) avg |
| map | O(log n) | O(log n) | O(log n) | O(log n) |
| unordered_map | O(1) avg | O(1) avg | O(1) avg | O(1) avg |

---

# **🎯 8. Interview‑Level Insights**

- STL is optimized in C++ and faster than custom implementations  
- Prefer `unordered_map` over `map` unless ordering matters  
- Prefer `vector` over `list` unless frequent middle insertions  
- Use `priority_queue` for top‑k problems  
- Use `set` for sorted unique values  
- Use `lower_bound` for binary search patterns  

---

# **🏁 9. Conclusion**

Day 1 gives you the **foundation** for the entire 30‑day journey.

You now understand:

- STL containers  
- Iterators  
- Algorithms  
- Patterns  
- Time complexities  

This knowledge will be used **every single day** in the upcoming topics.
