---

# 🎓 **Day 01 — C++ STL Mastery (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## 📌 **1. Introduction**

The C++ Standard Template Library (STL) is **one of the most powerful** components of modern C++.  
It provides ready‑made, optimized, generic implementations of the most common data structures and algorithms.

**🎯 Single Truth:** Mastering STL is not optional — it is the **FOUNDATION** for writing clean, fast, and interview‑ready C++ code.

Today's goal is to build a **deep**, **intuitive**, and **practical** understanding of:

- 🟦 **STL Containers** (data structures)
- ➡️ **Iterators** (generalized pointers)
- ⚙️ **Algorithms** (sorting, searching, transforming)
- 🔧 **Function objects** (functors)
- ⚡ **Lambda expressions** (modern C++)
- 🏆 **Best practices** for competitive programming and interviews

---

## 🌟 **2. Why STL Matters (The 5 Game-Changers)**

STL gives you **critical advantages**:

| **Advantage** | **Impact** |
|---|---|
| ⚡ **Speed** | Highly optimized, often better than hand-written code |
| 🛡️ **Safety** | Fewer bugs, fewer memory errors |
| 🚀 **Productivity** | Solve problems 50% faster |
| 🎯 **Consistency** | Predictable behavior across platforms |
| 💼 **Interview** | Reduces implementation time drastically |

💡 **Pro Tip:** If you know STL well, you can solve **80% of DSA problems** faster and cleaner than anyone else.

---

## 📦 **3. STL Components Overview (The Holy Trinity + 1)**

STL has **4 major parts**:

### **3.1 🟦 Containers (Data Structures)**
Hold and manage your data efficiently

**Sequence Containers (Order Matters):**
- 🟦 `vector` ⭐ — Dynamic array, most used
- 🟩 `deque` — Double-ended queue
- 🟨 `list` — Doubly linked list
- 🟥 `forward_list` — Singly linked list

**Associative Containers (Sorted/Hash-based):**
- 🟪 `set` — Sorted unique values
- 🟧 `unordered_set` — Hash-based unique values
- 🟫 `map` — Sorted key-value pairs
- 🟬 `unordered_map` — Hash-based key-value pairs
- 🟩 `multiset` / `multimap` — Allow duplicates

### **3.2 ➞️ Iterators (Generalized Pointers)**
Navigate through containers seamlessly

**Iterator Types:**
- ➞️ **Input** — Read-only, one pass
- ⬅️ **Output** — Write-only, one pass
- ↔️ **Forward** — Read/write, one direction
- ↔️ **Bidirectional** — Read/write, both directions
- 🔀 **Random Access** — Full pointer capabilities  

---

### **3.3 ⚙️ Algorithms (Pre-built Functions)**
Perform operations without reinventing the wheel

**Searching & Sorting:**
- 🔍 `sort()`, `reverse()` — Reorder elements
- 🔎 `binary_search()`, `find()` — Locate elements
- `lower_bound()`, `upper_bound()` — Boundary searches

**Aggregation:**
- 🗣️ `sum()`, `accumulate()` — Sum values
- `max_element()`, `min_element()` — Find extremes
- `count()` — Count occurrences

---

### **3.4 Functors & Lambdas**
Custom logic passed into STL algorithms.

---

## **4. Deep Dive into Important Containers**

---

# **4.1 vector — The Most Important STL Container**

### **Key Features**
- Dynamic array  
- Random access  
- Amortized O(1) insertion at end  
- O(n) insertion in middle  
- Contiguous memory  

### **Common Operations**
```cpp
vector<int> v;
v.push_back(10);
v.push_back(20);
v.pop_back();
v.size();
v.empty();
v.clear();
```

### **Iterating**
```cpp
for (int x : v) cout << x << " ";
```

### **Example — Basic Usage**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4};

    v.push_back(5);

    for (int x : v)
        cout << x << " ";
}
```

---

# **4.2 pair and vector of pairs**

### **Example**
```cpp
pair<int, string> p = {1, "Alice"};
cout << p.first << " " << p.second;
```

### **Vector of pairs**
```cpp
vector<pair<int,int>> vp = {{1,2}, {3,4}};
```

---

# **4.3 set — Sorted Unique Elements**

- Balanced BST  
- O(log n) operations  
- Automatically sorted  
- No duplicates  

### **Example**
```cpp
set<int> s;
s.insert(5);
s.insert(1);
s.insert(5); // ignored
```

---

# **4.4 unordered_set — Fast Hash Set**

- Hash table  
- Average O(1) operations  
- No ordering  

---

# **4.5 map — Key‑Value (Sorted)**

```cpp
map<string, int> mp;
mp["apple"] = 3;
mp["banana"] = 5;
```

---

# **4.6 unordered_map — Fast Hash Map**

Most used in coding interviews.

---

# **4.7 priority_queue — Max/Min Heap**

### **Max heap**
```cpp
priority_queue<int> pq;
```

### **Min heap**
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

# **5. Iterators — The Heart of STL**

### **Basic iterator usage**
```cpp
vector<int> v = {10, 20, 30};

for (auto it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
```

### **Reverse iterators**
```cpp
for (auto it = v.rbegin(); it != v.rend(); it++)
    cout << *it << " ";
```

---

# **6. STL Algorithms — The Real Power**

---

## **6.1 sort()**

```cpp
sort(v.begin(), v.end());
```

### **Custom comparator**
```cpp
sort(v.begin(), v.end(), [](int a, int b){
    return a > b; // descending
});
```

---

## **6.2 binary_search()**

```cpp
bool found = binary_search(v.begin(), v.end(), key);
```

---

## **6.3 lower_bound() / upper_bound()**

```cpp
auto it = lower_bound(v.begin(), v.end(), x);
```

---

## **6.4 accumulate()**

```cpp
int sum = accumulate(v.begin(), v.end(), 0);
```

---

## **6.5 max_element() / min_element()**

```cpp
int mx = *max_element(v.begin(), v.end());
```

---

# **7. Lambdas — Modern C++ Power**

### **Syntax**
```cpp
[ capture ] (parameters) -> return_type { body }
```

### **Example**
```cpp
auto add = [](int a, int b) { return a + b; };
cout << add(3, 4);
```

---

# **8. Real‑World Examples**

---

## **Example 1 — Sort vector of pairs by second value**

```cpp
vector<pair<int,int>> v = {{1,3}, {2,1}, {4,2}};

sort(v.begin(), v.end(), [](auto &a, auto &b){
    return a.second < b.second;
});
```

---

## **Example 2 — Frequency map**

```cpp
unordered_map<int,int> freq;

for (int x : arr)
    freq[x]++;
```

---

## **Example 3 — Using priority_queue as min‑heap**

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## **Example 4 — Remove duplicates using set**

```cpp
set<int> s(arr.begin(), arr.end());
```

---

# **9. Exercises (Try First, Then See Solutions)**

---

### **Exercise 1**  
Given a vector of integers, remove all duplicates and print the sorted unique elements.

### **Exercise 2**  
Given N pairs, sort them by second value, and if equal, by first value.

### **Exercise 3**  
Count frequency of each element using unordered_map.

### **Exercise 4**  
Given a vector, print the k largest elements using a min‑heap.

---

# **10. Solutions**

---

## **Solution 1 — Remove duplicates**

```cpp
set<int> s(v.begin(), v.end());
for (int x : s) cout << x << " ";
```

---

## **Solution 2 — Sort pairs**

```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
});
```

---

## **Solution 3 — Frequency count**

```cpp
unordered_map<int,int> mp;
for (int x : v) mp[x]++;
```

---

## **Solution 4 — k largest elements**

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

for (int x : v) {
    pq.push(x);
    if (pq.size() > k)
        pq.pop();
}
```

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Choose container by operation profile, not habit.
- Know iterator invalidation rules for vector/deque/list.
- Use algorithms (`sort`, `lower_bound`, `accumulate`) idiomatically.
- Prefer `emplace` when constructing in-place.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Unexpected map insertion via `operator[]`.
- Using `erase` incorrectly while iterating.
- Copying heavy containers instead of references.
- Forgetting `reserve` for known vector sizes.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: vector + set basics.
- Medium: custom comparator with sort/priority_queue.
- Hard: combine STL containers in multi-step interview problems.

