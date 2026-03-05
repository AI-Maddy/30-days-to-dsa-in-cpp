.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Read this topic with a 3-step loop: <strong>Concept → Pattern → Practice</strong>. </span>
      <span style="color:#0f766e;">Use icons in headings as visual anchors for faster recall.</span>
   </div>

Here comes your **ultra‑premium**, **color‑splashed**, **icon‑rich**, **memory‑optimized**  
`theory.rst` for **Day 06 – Hashing + HashMap Patterns**.

I’ve redesigned it to feel like a **visual textbook**, with **mnemonic icons**, **color‑coded sections**, and **pattern blocks** that stick in memory.

---

# **Day 06 – 🔥 Hashing + HashMap Patterns (The Ultimate Memory Edition)**  
`theory.rst`

---

## **🌈 1. Why Hashing Is a Superpower**
Hashing transforms problems that look like **O(n²)** into **O(n)** with one idea:

> **Store what you’ve seen → Answer instantly.**

Use hashing when you need:
- ⚡ Constant‑time lookup  
- 🔍 Fast membership testing  
- 🎯 Frequency counting  
- 🧩 Subarray sum tricks  
- 🪄 Sliding window with constraints  
- 🧱 Grouping (anagrams, patterns, signatures)

HashMaps are the **Swiss Army Knife** of FAANG interviews.

---

# **🌟 MEMORY ANCHOR: “H‑A‑S‑H”**
A simple mnemonic:

| Letter | Meaning | Helps You Remember |
|--------|----------|---------------------|
| **H** | **Hunt fast** | O(1) lookup |
| **A** | **Add counts** | Frequency maps |
| **S** | **Store states** | Prefix sums, windows |
| **H** | **Hash signatures** | Anagrams, patterns |

---

## **🔑 2. Hashing Basics (Color‑Coded for Memory)**

### **🧮 2.1 Hash Function**
Maps a key → bucket index.

Properties:
- 🎯 Deterministic  
- 🌍 Uniform  
- ⚡ Fast  
- 🛡️ Low collisions  

### **📦 2.2 Hash Table**
Stores key‑value pairs using:
- Buckets  
- Hash function  
- Collision handling  

### **🧰 2.3 HashMap in C++**
`unordered_map<Key, Value>`

- Insert → ⚡ O(1)  
- Find → ⚡ O(1)  
- Erase → ⚡ O(1)  

---

# **🌟 MEMORY ANCHOR: “F‑M‑G”**
HashMap is used for:

- **F**requency  
- **M**embership  
- **G**rouping  

If a problem fits F‑M‑G → HashMap is your weapon.

---

## **🎨 3. Core HashMap Use Cases (Color‑Tagged)**

### **🟦 Frequency Counting**
Count occurrences.

### **🟩 Membership Testing**
Check if something exists.

### **🟧 Mapping**
Value → index  
Useful for Two‑Sum, first/last occurrence.

### **🟪 Grouping**
Group by:
- Sorted string  
- Character frequency  
- Length  
- Hash signature  

---

# **🌈 4. HashMap Patterns (The Heart of Day 06)**

Each pattern includes:
- 🎯 When to use  
- 🧠 Core idea  
- 🧩 Mini‑example  
- ⚠️ Pitfalls  

---

## **💙 Pattern 1: Frequency Map Pattern**
🎯 Use for:
- Anagrams  
- Majority element  
- Character counting  
- Top‑K frequent  
- Unique elements  

🧠 Idea:
```
freq[x]++
```

🧩 Example: Check anagram  
- Count chars in s  
- Subtract chars in t  
- All zeros → anagram  

⚠️ Pitfall:  
- Don’t assume ASCII; sometimes Unicode matters.

---

## **💚 Pattern 2: HashSet Membership Pattern**
🎯 Use for:
- Duplicate detection  
- Missing numbers  
- Longest consecutive sequence  

🧠 Idea:
```
if (set.count(x)) duplicate
```

🧩 Example: Longest consecutive sequence  
- Insert all numbers  
- For each number that starts a chain (x‑1 not in set), count forward  

⚠️ Pitfall:  
- Don’t scan backward; always start from chain heads.

---

## **🧡 Pattern 3: Two‑Sum Pattern**
🎯 Use for:
- Pair problems  
- Complement‑based logic  

🧠 Idea:
```
if (mp[k - x] exists) pair found
else mp[x] = i
```

🧩 Example:  
Input: [2,7,11,15], target=9  
- 9‑2=7 → found  

⚠️ Pitfall:  
- Don’t store index after checking complement.

---

## **💜 Pattern 4: Prefix Sum + HashMap Pattern**
🎯 Use for:
- Subarray sum = k  
- Longest subarray with sum k  
- Subarrays divisible by k  
- Even/odd sum patterns  

🧠 Idea:
```
sum += arr[i]
count += mp[sum - k]
mp[sum]++
```

🧩 Example: Count subarrays with sum = k  
- Store counts of prefix sums  
- Look for (sum‑k)  

⚠️ Pitfall:  
- Initialize mp[0] = 1 (empty prefix).

---

## **💛 Pattern 5: Sliding Window + HashMap**
🎯 Use for:
- Longest substring without repeating  
- At most K distinct characters  
- Minimum window substring  

🧠 Idea:
- Expand right  
- Track frequencies  
- Shrink left when invalid  

🧩 Example: Longest substring without repeating  
- Map stores last index  
- Move left pointer accordingly  

⚠️ Pitfall:  
- Don’t shrink blindly; use last occurrence.

---

## **💗 Pattern 6: Hashing for Strings**
🎯 Use for:
- Anagrams  
- Palindromes  
- Grouping  
- Pattern matching  

🧠 Idea:
- Use frequency signature  
- Or sorted string  
- Or rolling hash (later days)

🧩 Example: Group anagrams  
Key = sorted string  
Value = list of words  

⚠️ Pitfall:  
- Sorting each string is O(n log n); frequency signature is O(26).

---

# **🌟 MEMORY ANCHOR: “6 Patterns = F‑S‑T‑P‑W‑S”**
| Pattern | Mnemonic |
|---------|-----------|
| Frequency Map | **F** |
| HashSet Membership | **S** |
| Two‑Sum | **T** |
| Prefix Sum + HashMap | **P** |
| Sliding Window | **W** |
| String Hashing | **S** |

Remember: **F‑S‑T‑P‑W‑S** → The 6 pillars of hashing.

---

# **⚠️ 7. Hashing Pitfalls (Red Flags 🚩)**

- 🚩 Using map instead of unordered_map (slower)  
- 🚩 Forgetting to check key existence  
- 🚩 Using floating‑point keys  
- 🚩 Not initializing mp[0] for prefix problems  
- 🚩 Using hashing for range min/max (wrong tool)  
- 🚩 Custom objects without custom hash  

---

# **📚 8. Interview Problems You Can Now Solve**
- Two Sum  
- Subarray Sum = K  
- Longest Consecutive Sequence  
- Group Anagrams  
- Longest Substring Without Repeating Characters  
- First Unique Character  
- Count Distinct Elements in Window  
- Subarrays Divisible by K  

---

# **⏱️ 9. Complexity Table**

| Operation | Avg | Worst | Notes |
|-----------|------|--------|--------|
| Insert | O(1) | O(n) | Rare worst case |
| Find | O(1) | O(n) | Collision chain |
| Erase | O(1) | O(n) | Same reason |
| Space | O(n) | O(n) | Stores keys |

---

# **🎯 10. What You Must Master Today**
- Build frequency maps  
- Use HashSet for membership  
- Apply Two‑Sum logic  
- Use prefix sum + HashMap for subarray problems  
- Use HashMap in sliding window  
- Understand collisions & load factor  
- Know when to use map vs unordered_map  

---

If you want, I can now create:

🌈 **Day 06 README (150+ lines, ultra‑premium)**  
🧠 **Day 06 cheat sheets**  
🧩 **C++ templates for all 6 patterns**  
🔥 **20 hashing interview problems with solutions**

Just tell me what you want next.
