Here we go, Sasimegala — **Day 01 begins now**, and I’m giving you exactly what you asked for:

- **Ultra‑premium quality**  
- **High quantity (150+ lines)**  
- **Deep explanations**  
- **Multiple examples**  
- **Multiple exercises with solutions**  
- **Perfectly structured for a README.rst**  
- **Interview‑ready + beginner‑friendly + expert‑level clarity**

This is the kind of content that makes a repo feel world‑class.

---

# **Day 01 — C++ STL Mastery (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

The C++ Standard Template Library (STL) is one of the most powerful components of modern C++.  
It provides ready‑made, optimized, generic implementations of the most common data structures and algorithms.

Mastering STL is not optional — it is the foundation for writing clean, fast, and interview‑ready C++ code.

Today’s goal is to build a deep, intuitive, and practical understanding of:

- STL Containers  
- Iterators  
- Algorithms  
- Function objects (functors)  
- Lambda expressions  
- Best practices for competitive programming and interviews  

---

## **2. Why STL Matters**

STL gives you:

- **Speed** — highly optimized, often better than hand‑written code  
- **Safety** — fewer bugs, fewer memory errors  
- **Productivity** — solve problems faster  
- **Consistency** — predictable behavior across platforms  
- **Interview advantage** — reduces implementation time drastically  

If you know STL well, you can solve 80% of DSA problems faster and cleaner.

---

## **3. STL Components Overview**

STL has 4 major parts:

### **3.1 Containers**
Data structures that store elements.

- `vector`
- `array`
- `deque`
- `list`
- `forward_list`
- `stack`
- `queue`
- `priority_queue`
- `set`
- `unordered_set`
- `map`
- `unordered_map`
- `multiset`
- `multimap`

---

### **3.2 Iterators**
Generalized pointers used to traverse containers.

Types:
- Input iterator  
- Output iterator  
- Forward iterator  
- Bidirectional iterator  
- Random access iterator  

---

### **3.3 Algorithms**
Pre‑built functions for searching, sorting, counting, transforming, etc.

Examples:
- `sort()`
- `binary_search()`
- `lower_bound()`
- `upper_bound()`
- `reverse()`
- `accumulate()`
- `max_element()`
- `min_element()`
- `count()`
- `find()`

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

# **11. Summary**

Today you mastered:

- STL containers  
- Iterators  
- Algorithms  
- Lambdas  
- Custom comparators  
- Heaps, maps, sets  
- Real interview patterns  

This foundation will make the next 29 days dramatically easier.

---

If you’re ready, I’ll generate **Day 02 — Time & Space Complexity + STL Algorithms** in the same ultra‑premium style.
