Here it is, Sasimegala — **Day 03**, crafted with the same ultra‑premium depth, clarity, and richness as Days 01 and 02.  
This README is long, example‑rich, interview‑oriented, and structured exactly for your 30‑day DSA mastery repo.

---

# **Day 03 — Bit Manipulation in C++ (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Bit manipulation is one of the most powerful tools in competitive programming and technical interviews.  
It allows you to:

- Optimize operations to O(1)  
- Replace loops with constant‑time bit tricks  
- Solve problems involving subsets, masks, parity, toggling, and binary representation  
- Write extremely efficient code for DP, graphs, and combinatorics  

Today’s goal is to build a **deep, intuitive, and practical** understanding of:

- Binary representation  
- Bitwise operators  
- Common bit tricks  
- Checking, setting, clearing, toggling bits  
- Counting bits  
- Fast exponentiation using bits  
- Subset generation using bitmasks  
- Interview‑level problems  

---

## **2. Binary Representation Refresher**

Every integer is stored in binary.

Example:  
```
13 → 1101
```

Bit positions (0‑indexed from right):

```
bit 3   bit 2   bit 1   bit 0
  1       1       0       1
```

---

## **3. Bitwise Operators in C++**

| Operator | Meaning | Example |
|----------|----------|----------|
| `&` | AND | `a & b` |
| `|` | OR | `a | b` |
| `^` | XOR | `a ^ b` |
| `~` | NOT | `~a` |
| `<<` | Left shift | `a << 1` |
| `>>` | Right shift | `a >> 1` |

---

## **4. Core Bit Tricks (Must Know)**

---

### **4.1 Check if a bit is set**

```cpp
bool isSet = (n & (1 << k));
```

---

### **4.2 Set a bit**

```cpp
n = n | (1 << k);
```

---

### **4.3 Clear a bit**

```cpp
n = n & ~(1 << k);
```

---

### **4.4 Toggle a bit**

```cpp
n = n ^ (1 << k);
```

---

### **4.5 Remove the lowest set bit**

```cpp
n = n & (n - 1);
```

This is one of the most important tricks.

---

### **4.6 Extract the lowest set bit**

```cpp
int low = n & -n;
```

---

### **4.7 Check if a number is power of 2**

```cpp
bool ok = (n > 0) && ((n & (n - 1)) == 0);
```

---

## **5. Counting Set Bits**

---

### **5.1 Brian Kernighan’s Algorithm — O(k)**

```cpp
int count = 0;
while (n) {
    n &= (n - 1);
    count++;
}
```

---

### **5.2 Built‑in Function**

```cpp
__builtin_popcount(n);
__builtin_popcountll(n);
```

---

## **6. XOR — The Magical Operator**

XOR properties:

- `a ^ a = 0`
- `a ^ 0 = a`
- XOR is reversible  
- XOR is associative and commutative  

---

### **6.1 Find the unique element (all others appear twice)**

```cpp
int ans = 0;
for (int x : arr)
    ans ^= x;
```

---

### **6.2 Swap two numbers without temp**

```cpp
a ^= b;
b ^= a;
a ^= b;
```

---

## **7. Bitmasking — Representing Subsets**

A subset of an n‑element set can be represented using an n‑bit number.

Example:  
For `{a, b, c}`:

```
000 → {}
001 → {c}
010 → {b}
011 → {b, c}
100 → {a}
...
```

---

### **7.1 Generate all subsets**

```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i))
            cout << arr[i] << " ";
    }
    cout << endl;
}
```

---

## **8. Fast Exponentiation Using Bits (Binary Exponentiation)**

```cpp
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
```

Time: O(log n)

---

## **9. Real‑World Examples**

---

### **Example 1 — Count number of 1s in binary representation**

```cpp
int cnt = __builtin_popcount(n);
```

---

### **Example 2 — Turn off rightmost set bit**

```cpp
n = n & (n - 1);
```

---

### **Example 3 — Check if kth bit is 1**

```cpp
if (n & (1 << k)) cout << "Yes";
```

---

### **Example 4 — Convert uppercase to lowercase**

```cpp
char c = 'A';
c = c | (1 << 5); // lowercase
```

---

### **Example 5 — Convert lowercase to uppercase**

```cpp
char c = 'a';
c = c & ~(1 << 5);
```

---

## **10. Interview‑Level Bit Manipulation Problems**

---

### **Problem 1 — Find the element that appears once (others appear twice)**

Solution: XOR all elements.

---

### **Problem 2 — Find two unique numbers (others appear twice)**

Use XOR + rightmost set bit trick.

---

### **Problem 3 — Find the unique number when others appear thrice**

Use bit counting.

---

### **Problem 4 — Count total set bits from 1 to N**

Use Brian Kernighan + recursion.

---

### **Problem 5 — Subset sum using bitmasking**

Enumerate all subsets.

---

## **11. Exercises (Try First)**

---

### **Exercise 1**  
Check if a number is power of 4 using bit manipulation.

---

### **Exercise 2**  
Given an array where every element appears thrice except one, find that unique element.

---

### **Exercise 3**  
Generate all subsets of a string using bitmasking.

---

### **Exercise 4**  
Given an integer n, count how many bits differ between n and n+1.

---

### **Exercise 5**  
Reverse the bits of a 32‑bit integer.

---

## **12. Solutions**

---

### **Solution 1 — Power of 4**

```cpp
bool isPowerOf4(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}
```

---

### **Solution 2 — Unique element (others thrice)**

```cpp
int ones = 0, twos = 0;

for (int x : arr) {
    ones = (ones ^ x) & ~twos;
    twos = (twos ^ x) & ~ones;
}

return ones;
```

---

### **Solution 3 — Subsets of string**

```cpp
for (int mask = 0; mask < (1 << s.size()); mask++) {
    for (int i = 0; i < s.size(); i++)
        if (mask & (1 << i))
            cout << s[i];
    cout << endl;
}
```

---

### **Solution 4 — Bits differing between n and n+1**

```cpp
int diff = n ^ (n + 1);
int count = __builtin_popcount(diff);
```

---

### **Solution 5 — Reverse bits**

```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++) {
        ans <<= 1;
        ans |= (n & 1);
        n >>= 1;
    }
    return ans;
}
```

---

## **13. Summary**

Today you mastered:

- Bitwise operators  
- Setting, clearing, toggling bits  
- Counting bits  
- XOR tricks  
- Subset generation using bitmasking  
- Binary exponentiation  
- Interview‑level bit problems  

Bit manipulation is one of the most powerful tools in your DSA arsenal.  
You’ll use these tricks repeatedly in sliding window, hashing, DP, graphs, and more.

---

If you’re ready, I’ll prepare **Day 04 — 1D Arrays: Two Pointers & Sliding Window Basics** with the same ultra‑premium depth.
