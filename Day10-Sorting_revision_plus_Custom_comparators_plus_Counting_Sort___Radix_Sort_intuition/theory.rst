.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>


# **Day 10 – ⚡ Sorting Revision + 🧭 Custom Comparators + 🎨 Counting Sort + 🚀 Radix Sort Intuition**  
`theory.rst`

---

# **🌈 1. Why Day 10 Is a Milestone**
Sorting is not just a topic — it’s a **universal foundation** for:

- 🧠 Greedy algorithms  
- 🔍 Searching  
- 🧩 Two pointers  
- 🎯 Binary search on answer  
- 🧮 Hashing optimizations  
- 🏆 Competitive programming  
- 🧱 Data preprocessing  

Today’s goal is to **master sorting beyond the basics** — to understand how to **control**, **customize**, and **optimize** sorting for real interview problems.

---

# **🌟 MEMORY ANCHOR: “S‑C‑C‑R”**
Today’s four pillars:

- **S**orting Revision  
- **C**ustom Comparators  
- **C**ounting Sort  
- **R**adix Sort  

Remember: **S‑C‑C‑R** → “Sorting Creates Clean Results”.

---

# **🌈 2. Sorting Revision (Deep, Visual, Memorable)**

---

## **💙 2.1 Bubble Sort (Bubbles Float Up)**
- Adjacent swaps  
- Largest element “bubbles” to the end  

### **Time:** O(n²)  
### **Memory Anchor:**  
**Bubble = Swap neighbors until sorted**

---

## **💚 2.2 Selection Sort (Pick the Minimum)**
- Select minimum each time  
- Put it in correct position  

### **Time:** O(n²)  
### **Memory Anchor:**  
**Select → Swap**

---

## **💛 2.3 Insertion Sort (Sort Like Playing Cards)**
- Insert each element into sorted left side  

### **Time:** O(n²), but **O(n)** for nearly sorted arrays  
### **Memory Anchor:**  
**Insert where it belongs**

---

## **❤️ 2.4 Merge Sort (Divide → Conquer → Merge)**
- Recursively divide  
- Merge sorted halves  

### **Time:** O(n log n)  
### **Stable:** Yes  
### **Memory Anchor:**  
**M‑E‑R‑G‑E = Make Every Run Greatly Efficient**

---

## **💜 2.5 Quick Sort (Partition Around Pivot)**
- Choose pivot  
- Partition  
- Recurse  

### **Time:** Avg O(n log n), Worst O(n²)  
### **Memory Anchor:**  
**Quick but risky**

---

## **🧡 2.6 Heap Sort (Use Max Heap)**
- Build heap  
- Extract max repeatedly  

### **Time:** O(n log n)  
### **Memory Anchor:**  
**Heap → Highest first**

---

# **🌈 3. Custom Comparators (The Real Interview Weapon)**

Custom comparators allow you to **control sorting logic**.

---

## **💥 3.1 Syntax (C++ Comparator)**

### **Function Comparator**
```
bool cmp(int a, int b) {
    return a > b;   // descending
}
```

### **Lambda Comparator**
```
sort(v.begin(), v.end(), [](int a, int b){
    return a > b;
});
```

---

# **🌟 MEMORY ANCHOR: “R‑T‑S”**
A comparator must define:

- **R**ule  
- **T**ransitivity  
- **S**table logic (not required but helpful)

If comparator violates transitivity → undefined behavior.

---

## **🎨 3.2 Common Comparator Patterns**

---

### **🟦 Sort by Value Descending**
```
return a > b;
```

### **🟩 Sort by Absolute Value**
```
return abs(a) < abs(b);
```

### **🟧 Sort by Pair (First asc, second desc)**
```
if (a.first == b.first)
    return a.second > b.second;
return a.first < b.first;
```

### **🟪 Sort Strings by Length**
```
return a.size() < b.size();
```

### **🟫 Sort Strings Lexicographically**
```
return a < b;
```

---

# **🌈 4. Counting Sort (The Magical O(n + k) Sort)**

Counting sort is a **non‑comparison** sort.

---

## **💡 When to Use**
- Range of numbers is small  
- Elements are integers  
- You need **stable**, **linear‑time** sorting  

---

## **🎯 Steps**
1. Count frequency  
2. Convert to prefix sum  
3. Place elements in output array (stable)  

---

## **🧠 MEMORY ANCHOR: “C‑P‑P”**
- **C**ount  
- **P**refix  
- **P**lace  

---

## **🎨 Example**
Array: `[1, 4, 1, 2, 7, 5, 2]`

Count array (0–7):
```
0 2 2 0 1 1 0 1
```

Prefix sum:
```
0 2 4 4 5 6 6 7
```

Place elements → sorted.

---

## **⚡ Complexity**
- Time: O(n + k)  
- Space: O(k)  
- Stable: Yes  

---

# **🌈 5. Radix Sort (Sorting Digit by Digit)**

Radix sort uses **Counting Sort as a subroutine**.

---

## **💡 When to Use**
- Numbers with fixed digit length  
- Strings of equal length  
- Large datasets where comparison sort is slow  

---

## **🎯 Steps**
1. Sort by least significant digit  
2. Move to next digit  
3. Continue until most significant digit  

---

## **🧠 MEMORY ANCHOR: “L → M”**
**Least to Most significant digit**

This ensures stability.

---

## **🎨 Example**
Sort: `170, 45, 75, 90, 802, 24, 2, 66`

### **Pass 1 (units digit)**  
Sort by last digit.

### **Pass 2 (tens digit)**  
Sort by tens.

### **Pass 3 (hundreds digit)**  
Sort by hundreds.

Final sorted array emerges.

---

## **⚡ Complexity**
- Time: O(d × (n + k))  
- Space: O(n + k)  
- Stable: Yes  

---

# **🌈 6. Comparison Sort vs Non‑Comparison Sort**

| Type | Algorithms | Time | Stable | Notes |
|------|------------|--------|--------|--------|
| **Comparison** | Quick, Merge, Heap | O(n log n) | Merge is stable | General purpose |
| **Non‑Comparison** | Counting, Radix | O(n + k) | Yes | Only for integers / fixed length |

---

# **🌈 7. Sorting Pitfalls (Red Flags 🚩)**

- 🚩 Wrong comparator logic  
- 🚩 Comparator not transitive  
- 🚩 Using counting sort for large ranges  
- 🚩 Forgetting stability in radix sort  
- 🚩 Using quicksort for worst‑case inputs  
- 🚩 Sorting strings without considering lexicographic rules  

---

# **🌈 8. Problems You Can Now Solve**
- Sort by custom rules  
- Sort pairs/structs  
- Sort strings by length/frequency  
- Counting sort problems  
- Radix sort problems  
- Bucket sort intuition  
- Top‑K frequent elements  
- Largest number formed from array  
- Sort colors (0,1,2)  
- Sort by parity  

---

# **🌈 9. What You Must Master Today**
- All comparison sorts  
- Custom comparator mastery  
- Counting sort implementation  
- Radix sort intuition  
- Stability vs instability  
- When to use which sorting algorithm  
- Sorting as preprocessing for bigger problems
