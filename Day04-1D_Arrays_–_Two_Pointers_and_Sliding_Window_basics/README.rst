Here it is, Sasimegala — **Day 04**, crafted with the same ultra‑premium depth, clarity, and richness as the previous days.  
This README is long, structured, interview‑oriented, and perfect for your 30‑day DSA mastery repo.

---

# **Day 04 — 1D Arrays: Two Pointers & Sliding Window Basics (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Two‑pointers and sliding‑window techniques are among the most powerful tools for solving array problems efficiently.  
They allow you to:

- Reduce O(n²) brute‑force solutions to O(n)  
- Solve subarray problems without extra memory  
- Handle sorted arrays elegantly  
- Process continuous ranges with minimal overhead  
- Build intuition for more advanced patterns (prefix sums, binary search on answer, DP)

Today’s goal is to master:

- Two‑pointer fundamentals  
- Opposite‑direction pointers  
- Same‑direction pointers  
- Sliding window (fixed + variable)  
- Window expansion and contraction  
- Classic interview problems  

This is one of the most important days in the entire 30‑day plan.

---

## **2. Two‑Pointers Technique**

Two pointers are simply two indices that move through an array in a coordinated way.

There are two major types:

### **2.1 Opposite‑Direction Two Pointers**
Used when the array is **sorted** or when you want to shrink a search space from both ends.

Examples:
- Pair sum in sorted array  
- Reverse array  
- Check palindrome  
- Remove duplicates (sorted array)  

---

### **2.2 Same‑Direction Two Pointers**
Used when you want to maintain a window or process elements sequentially.

Examples:
- Remove duplicates (unsorted)  
- Move zeros to end  
- Partitioning  

---

## **3. Sliding Window Technique**

Sliding window is a specialized form of same‑direction two pointers.

Used for problems involving **subarrays**:

- Longest subarray with sum ≤ K  
- Count subarrays with at most K distinct elements  
- Maximum sum subarray of size K  
- First negative number in every window  
- Longest substring without repeating characters  

Two types:

### **3.1 Fixed‑Size Window**
Window size = constant (e.g., K)

### **3.2 Variable‑Size Window**
Window expands and contracts based on conditions.

---

## **4. Two‑Pointers: Core Patterns**

---

### **4.1 Reverse an Array (Opposite Pointers)**

```cpp
int i = 0, j = n - 1;
while (i < j) {
    swap(arr[i], arr[j]);
    i++;
    j--;
}
```

Time: O(n)

---

### **4.2 Pair Sum in Sorted Array**

```cpp
int i = 0, j = n - 1;

while (i < j) {
    int sum = arr[i] + arr[j];
    if (sum == target) return true;
    else if (sum < target) i++;
    else j--;
}
```

Time: O(n)

---

### **4.3 Remove Duplicates from Sorted Array**

```cpp
int k = 1;
for (int i = 1; i < n; i++)
    if (arr[i] != arr[i-1])
        arr[k++] = arr[i];
```

---

## **5. Sliding Window: Core Patterns**

---

### **5.1 Fixed‑Size Window — Maximum Sum Subarray of Size K**

```cpp
int sum = 0;
for (int i = 0; i < k; i++)
    sum += arr[i];

int maxSum = sum;

for (int i = k; i < n; i++) {
    sum += arr[i] - arr[i-k];
    maxSum = max(maxSum, sum);
}
```

Time: O(n)

---

### **5.2 Variable‑Size Window — Longest Subarray with Sum ≤ K**

```cpp
int i = 0, sum = 0, ans = 0;

for (int j = 0; j < n; j++) {
    sum += arr[j];

    while (sum > k) {
        sum -= arr[i];
        i++;
    }

    ans = max(ans, j - i + 1);
}
```

---

### **5.3 Longest Substring Without Repeating Characters**

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

## **6. Real‑World Examples**

---

### **Example 1 — Move Zeros to End (Same Direction)**

```cpp
int j = 0;
for (int i = 0; i < n; i++)
    if (arr[i] != 0)
        swap(arr[i], arr[j++]);
```

---

### **Example 2 — Find Triplets with Sum = Target (Two Pointers)**

```cpp
sort(arr.begin(), arr.end());

for (int i = 0; i < n; i++) {
    int l = i + 1, r = n - 1;

    while (l < r) {
        int sum = arr[i] + arr[l] + arr[r];

        if (sum == target) { /* found */ }
        else if (sum < target) l++;
        else r--;
    }
}
```

---

### **Example 3 — Minimum Window with Sum ≥ K**

```cpp
int i = 0, sum = 0, ans = INT_MAX;

for (int j = 0; j < n; j++) {
    sum += arr[j];

    while (sum >= k) {
        ans = min(ans, j - i + 1);
        sum -= arr[i];
        i++;
    }
}
```

---

## **7. Interview‑Level Problems**

---

### **Problem 1 — Longest subarray with sum exactly K**

Use variable window + shrink when sum > K.

---

### **Problem 2 — Count subarrays with at most K distinct elements**

Use sliding window + frequency map.

---

### **Problem 3 — Find all pairs with difference K**

Sort + two pointers.

---

### **Problem 4 — Minimum swaps to group all 1s together**

Sliding window on count of 1s.

---

### **Problem 5 — Container With Most Water**

Opposite‑direction two pointers.

---

## **8. Exercises (Try First)**

---

### **Exercise 1**  
Given an array, find the longest subarray with sum ≤ K.

---

### **Exercise 2**  
Given a sorted array, find all pairs with sum = target.

---

### **Exercise 3**  
Given an array, find the maximum sum of any subarray of size K.

---

### **Exercise 4**  
Given a string, find the longest substring with at most K distinct characters.

---

### **Exercise 5**  
Given an array of 0s and 1s, find the minimum number of swaps to group all 1s together.

---

## **9. Solutions**

---

### **Solution 1 — Longest subarray with sum ≤ K**

```cpp
int i = 0, sum = 0, ans = 0;

for (int j = 0; j < n; j++) {
    sum += arr[j];

    while (sum > k) {
        sum -= arr[i];
        i++;
    }

    ans = max(ans, j - i + 1);
}
```

---

### **Solution 2 — Pair sum in sorted array**

```cpp
int i = 0, j = n - 1;

while (i < j) {
    int sum = arr[i] + arr[j];
    if (sum == target) { /* print pair */ i++; j--; }
    else if (sum < target) i++;
    else j--;
}
```

---

### **Solution 3 — Max sum subarray of size K**

```cpp
int sum = 0;
for (int i = 0; i < k; i++) sum += arr[i];

int ans = sum;

for (int i = k; i < n; i++) {
    sum += arr[i] - arr[i-k];
    ans = max(ans, sum);
}
```

---

### **Solution 4 — Longest substring with at most K distinct**

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

### **Solution 5 — Minimum swaps to group 1s**

```cpp
int ones = count(arr.begin(), arr.end(), 1);
int curr = 0;

for (int i = 0; i < ones; i++)
    if (arr[i] == 1) curr++;

int maxOnes = curr;

for (int i = ones; i < n; i++) {
    if (arr[i] == 1) curr++;
    if (arr[i - ones] == 1) curr--;
    maxOnes = max(maxOnes, curr);
}

int minSwaps = ones - maxOnes;
```

---

## **10. Summary**

Today you mastered:

- Two‑pointer fundamentals  
- Opposite‑direction and same‑direction pointers  
- Sliding window (fixed + variable)  
- Window expansion and contraction  
- Classic interview patterns  
- Real‑world problems and optimizations  

This is one of the most important days in your DSA journey — these techniques appear everywhere: arrays, strings, hashing, DP, graphs, and more.

---

If you’re ready, I’ll prepare **Day 05 — Prefix Sum + Difference Array + Range Query Patterns** with the same ultra‑premium depth.
