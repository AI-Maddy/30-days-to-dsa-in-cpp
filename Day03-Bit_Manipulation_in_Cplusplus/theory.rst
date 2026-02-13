Absolutely, Sasimegala — here is your **Day 3 – THEORY.rst**, crafted with the same ultra‑premium, colorful, icon‑rich, highly‑memorizable style as Day 1 and Day 2.

This is **Day 3: Bit Manipulation in C++**, designed to be crystal‑clear, deep, and unforgettable.

---

# **Day 3 – THEORY.rst**  
## **⚡ Bit Manipulation in C++ – Mastering Bits, Masks, Tricks & Patterns**

---

# **🌟 1. Overview**

Bit manipulation is one of the most **powerful**, **beautiful**, and **high‑performance** techniques in programming.

It gives you:

- ⚡ Constant‑time operations  
- 🧠 Elegant mathematical tricks  
- 🎯 Perfect solutions for XOR, subsets, masks  
- 🚀 Competitive‑programming‑level speed  

Mastering bits makes you a **10× better problem solver**.

---

# **🔢 2. Binary Representation Refresher**

Every integer is stored in **binary**:

```
13 → 1101
7  → 0111
```

Each bit represents a power of 2:

```
bit0 = 1
bit1 = 2
bit2 = 4
bit3 = 8
...
```

---

# **🧰 3. Bitwise Operators (The Core Tools)**

| Operator | Symbol | Meaning |
|----------|--------|---------|
| AND | `&` | bitwise AND |
| OR | `\|` | bitwise OR |
| XOR | `^` | bitwise XOR |
| NOT | `~` | bitwise NOT |
| Left Shift | `<<` | multiply by 2 |
| Right Shift | `>>` | divide by 2 |

---

## **🟦 3.1 AND `&`**

```
1 & 1 = 1
1 & 0 = 0
```

Used for:

- Checking if a bit is set  
- Masking  

---

## **🟩 3.2 OR `|`**

```
1 | 0 = 1
```

Used for:

- Setting a bit  

---

## **🟨 3.3 XOR `^`**

```
1 ^ 1 = 0
1 ^ 0 = 1
```

Properties:

- `x ^ x = 0`  
- `x ^ 0 = x`  
- XOR is reversible  

Used in:

- Single number problems  
- Swapping without temp  

---

## **🟧 3.4 NOT `~`**

Flips all bits.

---

## **🟥 3.5 Left Shift `<<`**

```
x << 1 = x * 2
```

---

## **🟪 3.6 Right Shift `>>`**

```
x >> 1 = x / 2
```

---

# **🎯 4. Bit Masks (The Heart of Bit Manipulation)**

A **bit mask** is a number used to manipulate specific bits.

---

## **🟦 4.1 Check if a bit is set**

```
if (n & (1 << k))
```

---

## **🟩 4.2 Set a bit**

```
n | (1 << k)
```

---

## **🟨 4.3 Clear a bit**

```
n & ~(1 << k)
```

---

## **🟧 4.4 Toggle a bit**

```
n ^ (1 << k)
```

---

## **🟥 4.5 Extract last set bit**

```
n & -n
```

Used in:

- Fenwick Tree  
- Subset generation  

---

# **🧠 5. Important Bit Tricks (Must Memorize)**

---

## **🔥 Trick 1 — Check if number is power of 2**

```
n & (n - 1) == 0
```

---

## **🔥 Trick 2 — Count set bits (Brian Kernighan)**

```
while (n) {
    n &= (n - 1);
    count++;
}
```

---

## **🔥 Trick 3 — Swap without temp**

```
a ^= b;
b ^= a;
a ^= b;
```

---

## **🔥 Trick 4 — Turn off rightmost set bit**

```
n & (n - 1)
```

---

## **🔥 Trick 5 — Get rightmost set bit**

```
n & -n
```

---

# **🧩 6. XOR Patterns (Extremely Important)**

---

## **🟦 6.1 Find unique element (all others appear twice)**

```
ans = 0
for x in array:
    ans ^= x
```

---

## **🟩 6.2 Find two unique elements**

Use XOR + rightmost set bit trick.

---

## **🟨 6.3 XOR prefix trick**

Used in:

- Subarray XOR  
- Range XOR queries  

---

# **🧮 7. Bit Manipulation in C++**

---

## **🟦 7.1 Built‑in functions**

### **Count set bits**

```
__builtin_popcount(x)
__builtin_popcountll(x)
```

### **Count leading zeros**

```
__builtin_clz(x)
```

### **Count trailing zeros**

```
__builtin_ctz(x)
```

---

# **🧱 8. Subset Generation Using Bits**

For array of size `n`, subsets = `2^n`.

```
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i))
            include element i
    }
}
```

Used in:

- Backtracking  
- DP on subsets  
- Combinatorics  

---

# **📘 9. Bit Manipulation Patterns in Interviews**

---

## **Pattern 1 — XOR for uniqueness**

Used in:

- Single number  
- Missing number  
- Duplicate detection  

---

## **Pattern 2 — Bitmask DP**

Used in:

- Traveling Salesman  
- Subset DP  
- Word masks  

---

## **Pattern 3 — Using bits for state compression**

Used in:

- Graph problems  
- DP optimization  

---

## **Pattern 4 — Using shifts for fast multiplication/division**

---

# **🎯 10. Interview‑Level Insights**

- Bit manipulation is **constant time**  
- XOR is your best friend  
- Masks simplify complex logic  
- Built‑ins make code faster  
- Subset generation is easiest with bits  

---

# **🏁 11. Conclusion**

Day 3 gives you mastery over:

- Bitwise operators  
- Masks  
- XOR tricks  
- Built‑ins  
- Subset generation  
- Interview patterns  

This knowledge becomes essential for:

- DP  
- Graphs  
- Backtracking  
- Optimization problems  

You now have the **bit‑level superpowers** needed for advanced DSA.

---

If you want, I can now generate:

- **Day 3 README.rst**  
- **Day 4 theory.rst**  
- **A complete Bit Manipulation cheat sheet**  

Just tell me what you want next.
