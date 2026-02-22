---

# **Day 06 — Hashing & HashMap Problems (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Hashing is one of the most powerful ideas in computer science.  
It allows you to store, retrieve, and update data in **O(1) average time**, making it essential for:

- Frequency counting  
- Duplicate detection  
- Prefix‑based problems  
- Sliding window optimizations  
- Subarray sum problems  
- Graph adjacency maps  
- Caching (LRU, LFU)  
- Set membership queries  

Today’s goal is to master:

- Hash functions  
- Collision handling  
- unordered_map and unordered_set  
- Frequency maps  
- Hash‑based sliding window  
- Prefix sum + hashing  
- Classic interview problems  

This is one of the most important days in your DSA journey.

---

## **2. What is Hashing?**

Hashing maps a key → index using a hash function.

```
index = hash(key)
```

A good hash function ensures:

- Uniform distribution  
- Low collisions  
- Fast computation  

---

## **3. Hash Tables in C++**

C++ provides two main hash‑based containers:

### **3.1 unordered_map**
Key‑value storage with average O(1) operations.

```cpp
unordered_map<int, int> mp;
mp[5] = 10;
mp[7] = 20;
```

---

### **3.2 unordered_set**
Stores unique keys.

```cpp
unordered_set<int> st;
st.insert(10);
st.insert(20);
```

---

## **4. Time Complexity**

| Operation | unordered_map | unordered_set |
|----------|----------------|----------------|
| Insert | O(1) avg | O(1) avg |
| Search | O(1) avg | O(1) avg |
| Delete | O(1) avg | O(1) avg |
| Worst case | O(n) | O(n) |

Worst case happens when many keys collide — rare with good hash functions.

---

## **5. Frequency Counting — The Most Common Use Case**

### **5.1 Count frequency of elements**

```cpp
unordered_map<int,int> freq;

for (int x : arr)
    freq[x]++;
```

---

### **5.2 Count characters in a string**

```cpp
unordered_map<char,int> mp;

for (char c : s)
    mp[c]++;
```

---

## **6. Detecting Duplicates**

### **6.1 Using unordered_set**

```cpp
unordered_set<int> st;

for (int x : arr) {
    if (st.count(x)) {
        cout << "Duplicate found";
        break;
    }
    st.insert(x);
}
```

---

## **7. Hashing + Prefix Sum — A Powerful Combo**

### **7.1 Count subarrays with sum = K**

```cpp
unordered_map<int,int> mp;
mp[0] = 1;

int sum = 0, ans = 0;

for (int x : arr) {
    sum += x;
    if (mp.count(sum - k))
        ans += mp[sum - k];
    mp[sum]++;
}
```

This is one of the most important patterns in DSA.

---

## **8. Hashing in Sliding Window Problems**

### **8.1 Longest substring without repeating characters**

```cpp
unordered_map<char,int> mp;
int i = 0, ans = 0;

for (int j = 0; j < s.size(); j++) {
    mp[s[j]]++;

    while (mp[s[j]] > 1) {
        mp[s[i]]--;
        i++;
    }

    ans = max(ans, j - i + 1);
}
```

---

### **8.2 Longest substring with at most K distinct characters**

```cpp
unordered_map<char,int> mp;
int i = 0, ans = 0;

for (int j = 0; j < s.size(); j++) {
    mp[s[j]]++;

    while (mp.size() > k) {
        mp[s[i]]--;
        if (mp[s[i]] == 0) mp.erase(s[i]);
        i++;
    }

    ans = max(ans, j - i + 1);
}
```

---

## **9. Hashing Patterns You Must Know**

---

### **9.1 Two‑Sum Problem (Hashing Version)**

```cpp
unordered_map<int,int> mp;

for (int i = 0; i < n; i++) {
    int need = target - arr[i];
    if (mp.count(need)) {
        // found pair
    }
    mp[arr[i]] = i;
}
```

Time: O(n)

---

### **9.2 Longest Consecutive Sequence**

```cpp
unordered_set<int> st(arr.begin(), arr.end());
int ans = 0;

for (int x : arr) {
    if (!st.count(x - 1)) {
        int len = 1;
        int curr = x;

        while (st.count(curr + 1)) {
            curr++;
            len++;
        }

        ans = max(ans, len);
    }
}
```

Time: O(n)

---

### **9.3 Group Anagrams**

```cpp
unordered_map<string, vector<string>> mp;

for (string s : words) {
    string t = s;
    sort(t.begin(), t.end());
    mp[t].push_back(s);
}
```

---

### **9.4 Subarray with Zero Sum**

```cpp
unordered_set<int> st;
int sum = 0;

for (int x : arr) {
    sum += x;
    if (sum == 0 || st.count(sum))
        return true;
    st.insert(sum);
}
```

---

## **10. Real‑World Examples**

---

### **Example 1 — First non‑repeating character**

```cpp
unordered_map<char,int> mp;

for (char c : s) mp[c]++;

for (char c : s)
    if (mp[c] == 1)
        return c;
```

---

### **Example 2 — Check if two strings are anagrams**

```cpp
unordered_map<char,int> mp;

for (char c : s1) mp[c]++;
for (char c : s2) mp[c]--;

for (auto &p : mp)
    if (p.second != 0) return false;
```

---

### **Example 3 — Find frequency of each word**

```cpp
unordered_map<string,int> mp;

for (string w : words)
    mp[w]++;
```

---

## **11. Interview‑Level Problems**

---

### **Problem 1 — Count subarrays with sum = K**  
Prefix sum + hashmap.

---

### **Problem 2 — Longest substring without repeating characters**  
Hashmap + sliding window.

---

### **Problem 3 — Longest consecutive sequence**  
Hashset + expansion.

---

### **Problem 4 — Two‑sum**  
Hashmap lookup.

---

### **Problem 5 — Check if array contains duplicates within K distance**  
Hashset sliding window.

---

## **12. Exercises (Try First)**

---

### **Exercise 1**  
Given an array, count the number of subarrays with sum = K.

---

### **Exercise 2**  
Given a string, find the longest substring with at most K distinct characters.

---

### **Exercise 3**  
Given an array, check if any duplicate exists within distance K.

---

### **Exercise 4**  
Group anagrams together.

---

### **Exercise 5**  
Find the length of the longest consecutive sequence.

---

## **13. Solutions**

---

### **Solution 1 — Subarrays with sum K**

```cpp
unordered_map<int,int> mp;
mp[0] = 1;

int sum = 0, ans = 0;

for (int x : arr) {
    sum += x;
    if (mp.count(sum - k))
        ans += mp[sum - k];
    mp[sum]++;
}
```

---

### **Solution 2 — Longest substring with at most K distinct**

```cpp
unordered_map<char,int> mp;
int i = 0, ans = 0;

for (int j = 0; j < s.size(); j++) {
    mp[s[j]]++;

    while (mp.size() > k) {
        mp[s[i]]--;
        if (mp[s[i]] == 0) mp.erase(s[i]);
        i++;
    }

    ans = max(ans, j - i + 1);
}
```

---

### **Solution 3 — Duplicate within K distance**

```cpp
unordered_set<int> st;

for (int i = 0; i < n; i++) {
    if (st.count(arr[i])) return true;

    st.insert(arr[i]);
    if (st.size() > k)
        st.erase(arr[i - k]);
}
```

---

### **Solution 4 — Group anagrams**

```cpp
unordered_map<string, vector<string>> mp;

for (string s : words) {
    string t = s;
    sort(t.begin(), t.end());
    mp[t].push_back(s);
}
```

---

### **Solution 5 — Longest consecutive sequence**

```cpp
unordered_set<int> st(arr.begin(), arr.end());
int ans = 0;

for (int x : arr) {
    if (!st.count(x - 1)) {
        int len = 1;
        int curr = x;

        while (st.count(curr + 1)) {
            curr++;
            len++;
        }

        ans = max(ans, len);
    }
}
```

---

## **14. Summary**

Today you mastered:

- Hash tables  
- unordered_map and unordered_set  
- Frequency maps  
- Hashing + sliding window  
- Hashing + prefix sum  
- Duplicate detection  
- Longest consecutive sequence  
- Anagram grouping  
- Classic interview problems  

Hashing is one of the most important tools in DSA — you will use it in arrays, strings, DP, graphs, and more.

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Map frequency-count and prefix-hash patterns to common problems.
- Explain when unordered_map may degrade and how to mitigate.
- Distinguish set vs map usage in dedup problems.
- Use hashing to convert O(n^2) pair checks to O(n).

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Forgetting to seed/update prefix count before loop.
- Assuming insertion order in unordered containers.
- Ignoring collision worst-case discussion in interviews.
- Overusing map where vector frequency table is enough.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: two sum, valid anagram.
- Medium: longest consecutive sequence.
- Hard: subarray count with target constraints and negatives.

