---

## ⏳ **1. Introduction**

Time and space complexity form the mathematical backbone of algorithm analysis.  
Understanding them deeply allows you to:

- 🔮 Predict performance  
- 🛠️ Optimize solutions  
- 🏗️ Choose the right data structure  
- 🗣️ Impress interviewers with clarity and precision  
- 🚫 Avoid brute‑force traps  

Today, you will master:

- 🏁 Big‑O notation  
- 📊 Best / average / worst‑case analysis  
- 🧮 Space complexity patterns  
- 🔁 Recurrence relations (intro)  
- ⚙️ STL algorithm complexities  
- 🏎️ Practical performance comparisons  
- 💼 Real interview examples  

This day sets the tone for the rest of the 30‑day journey.

---

## **2. Big‑O Notation — The Language of Performance**

Big‑O describes the **upper bound** of an algorithm’s growth rate.

### 🚦 **Common Complexities (From Fastest to Slowest)**

| Complexity | Example |
|-----------|---------|
| 🟢 O(1) | Accessing array index |
| 🟡 O(log n) | Binary search |
| 🟠 O(n) | Linear scan |
| 🔵 O(n log n) | Merge sort, quicksort avg |
| 🟣 O(n²) | Nested loops |
| 🟤 O(n³) | Triple nested loops |
| 🔴 O(2ⁿ) | Subset generation |
| ⚫ O(n!) | Permutations |

---

## **3. Visual Intuition**

Growth comparison:

```
n:     1   2   4    8    16    32
logn:  0   1   2    3     4     5
n:     1   2   4    8    16    32
nlogn: 0   2   8   24    64   160
n^2:   1   4  16   64   256   1024
```

Notice how **n log n** grows much slower than **n²**.

---

## **4. Time Complexity Patterns**

### **4.1 Single Loop → O(n)**

```cpp
for (int i = 0; i < n; i++) { }
```

---

### **4.2 Nested Loops → O(n²)**

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) { }
```

---

### **4.3 Logarithmic Loop → O(log n)**

```cpp
while (n > 1) n /= 2;
```

---

### **4.4 Two Pointers → O(n)**

```cpp
int i = 0, j = n - 1;
while (i < j) {
    i++;
    j--;
}
```

---

### **4.5 Binary Search → O(log n)**

```cpp
int l = 0, r = n - 1;
while (l <= r) {
    int mid = (l + r) / 2;
}
```

---

### **4.6 Recursion (Intro)**

Example:  
```
T(n) = T(n/2) + 1 → O(log n)
T(n) = 2T(n/2) + n → O(n log n)
```

---

## **5. Space Complexity**

Space complexity measures **extra memory** used.

### **Common Patterns**

| Pattern | Space |
|---------|--------|
| Variables | O(1) |
| Array of size n | O(n) |
| Recursion depth | O(n) worst |
| 2D matrix | O(n²) |

---

## **6. STL Algorithms — Complexity & Usage**

This is where Day 02 becomes extremely practical.

---

# **6.1 sort() — O(n log n)**

```cpp
sort(v.begin(), v.end());
```

### **Custom comparator**
```cpp
sort(v.begin(), v.end(), [](int a, int b){
    return a > b;
});
```

---

# **6.2 binary_search() — O(log n)**

```cpp
bool found = binary_search(v.begin(), v.end(), key);
```

---

# **6.3 lower_bound() / upper_bound() — O(log n)**

```cpp
auto it = lower_bound(v.begin(), v.end(), x);
```

---

# **6.4 reverse() — O(n)**

```cpp
reverse(v.begin(), v.end());
```

---

# **6.5 accumulate() — O(n)**

```cpp
int sum = accumulate(v.begin(), v.end(), 0);
```

---

# **6.6 count() — O(n)**

```cpp
int c = count(v.begin(), v.end(), 5);
```

---

# **6.7 find() — O(n)**

```cpp
auto it = find(v.begin(), v.end(), 10);
```

---

# **6.8 max_element() / min_element() — O(n)**

```cpp
int mx = *max_element(v.begin(), v.end());
```

---

# **6.9 next_permutation() — O(n)**

```cpp
next_permutation(v.begin(), v.end());
```

---

## **7. Real‑World Examples**

---

### **Example 1 — Count frequency using STL**

```cpp
unordered_map<int,int> freq;

for (int x : v)
    freq[x]++;
```

Time: O(n)  
Space: O(n)

---

### **Example 2 — Find first element greater than X**

```cpp
auto it = upper_bound(v.begin(), v.end(), x);
```

Time: O(log n)

---

### **Example 3 — Sort strings by length**

```cpp
sort(v.begin(), v.end(), [](string &a, string &b){
    return a.size() < b.size();
});
```

---

### **Example 4 — Check if array is sorted**

```cpp
bool sorted = is_sorted(v.begin(), v.end());
```

---

## **8. Interview‑Level Complexity Questions**

---

### **Q1: What is the complexity of inserting into a vector?**

- Amortized O(1) at end  
- O(n) at middle  

---

### **Q2: Complexity of unordered_map operations?**

- Average: O(1)  
- Worst: O(n) (rare)

---

### **Q3: Why is binary search O(log n)?**

Because each step halves the search space.

---

### **Q4: Why is merge sort O(n log n)?**

Because:

- log n levels  
- n work per level  

---

## **9. Exercises (Try First)**

---

### **Exercise 1**  
Given a vector of size n, count how many elements are strictly greater than the average.

---

### **Exercise 2**  
Given a sorted vector, find the first and last occurrence of a number using STL.

---

### **Exercise 3**  
Given an array, compute prefix sums using accumulate.

---

### **Exercise 4**  
Given a vector of pairs, sort by second value descending, and if equal, by first ascending.

---

### **Exercise 5**  
Analyze the time complexity of the following:

```cpp
for (int i = 1; i < n; i *= 2)
    for (int j = 0; j < i; j++)
        cout << "*";
```

---

## **10. Solutions**

---

### **Solution 1 — Count > average**

```cpp
double avg = accumulate(v.begin(), v.end(), 0.0) / v.size();
int cnt = count_if(v.begin(), v.end(), [&](int x){ return x > avg; });
```

---

### **Solution 2 — First & last occurrence**

```cpp
auto first = lower_bound(v.begin(), v.end(), x);
auto last  = upper_bound(v.begin(), v.end(), x) - 1;
```

---

### **Solution 3 — Prefix sum**

```cpp
vector<int> pref(n);
partial_sum(v.begin(), v.end(), pref.begin());
```

---

### **Solution 4 — Sort pairs**

```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
});
```

---

### **Solution 5 — Complexity**

Outer loop: log n  
Inner loop: 1 + 2 + 4 + … + n = O(n)  
Total: **O(n)**

---

## **11. Summary**

Today you mastered:

- Big‑O notation  
- Time complexity patterns  
- Space complexity fundamentals  
- STL algorithm complexities  
- Practical performance intuition  
- Interview‑level reasoning  
- Real‑world STL usage  

This is one of the most important days in the entire 30‑day plan.

---
