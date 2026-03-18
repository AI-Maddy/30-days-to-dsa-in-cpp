.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> AND clears, OR sets, XOR toggles. </span>
      <span style="color:#0f766e;">n &amp; (n-1) clears rightmost set bit — used for popcount and power-of-2 checks.</span>
   </div>

===========================
⚡ Bit Manipulation Cheatsheet
===========================

----

🔧 Bitwise Operators
=====================

+------+--------+------------------+--------+
| Op   | Symbol | 1010 op 1100     | Result |
+======+========+==================+========+
| AND  | &      | 1010 & 1100      | 1000   |
+------+--------+------------------+--------+
| OR   | \|     | 1010 \| 1100     | 1110   |
+------+--------+------------------+--------+
| XOR  | ^      | 1010 ^ 1100      | 0110   |
+------+--------+------------------+--------+
| NOT  | ~      | ~1010            | ...0101|
+------+--------+------------------+--------+
| SHL  | <<     | 1 << 3           | 8      |
+------+--------+------------------+--------+
| SHR  | >>     | 16 >> 2          | 4      |
+------+--------+------------------+--------+

1 << i = 2^i   |   n >> i = n / 2^i

----

🛠️ Core Bit Tricks
====================

.. code-block:: cpp

    // Check if bit i is set
    bool isSet = (n >> i) & 1;

    // Set bit i
    n |= (1 << i);

    // Clear bit i
    n &= ~(1 << i);

    // Toggle bit i
    n ^= (1 << i);

    // Rightmost set bit (isolated)
    int rsb = n & (-n);               // -n = ~n + 1

    // Clear rightmost set bit
    n &= (n - 1);

    // Check power of 2
    bool isPow2 = n > 0 && (n & (n-1)) == 0;

    // Swap without temp
    a ^= b;  b ^= a;  a ^= b;

    // Last k bits
    int last_k = n & ((1 << k) - 1);

    // Round up to next power of 2
    int p = 1;
    while (p < n) p <<= 1;

    // Opposite signs?
    bool diffSigns = (a ^ b) < 0;

----

📊 Count Set Bits
==================

.. code-block:: cpp

    // Brian Kernighan — O(set bits)
    int countBits(int n) {
        int count = 0;
        while (n) { n &= (n - 1); count++; }
        return count;
    }

    // Built-in (O(1) on modern CPUs)
    __builtin_popcount(n);       // int
    __builtin_popcountll(n);     // long long

    // Bit positions
    __builtin_ctz(n);            // trailing zeros (rightmost set bit pos)
    __builtin_clz(n);            // leading zeros  (32-bit)
    int highBit = 31 - __builtin_clz(n);  // highest set bit position

----

🧩 XOR Properties & Patterns
==============================

.. code-block:: text

    a ^ a = 0           (self-cancellation)
    a ^ 0 = a           (identity)
    a ^ b ^ a = b       (use to find unique element)
    Commutative: a ^ b = b ^ a
    Associative: (a ^ b) ^ c = a ^ (b ^ c)

.. code-block:: cpp

    // Find single non-duplicate (all others appear twice)
    int findSingle(vector<int>& a) {
        int res = 0;
        for (int x : a) res ^= x;
        return res;
    }

    // Find missing number in 1..n
    int findMissing(vector<int>& a, int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) res ^= i;
        for (int x : a) res ^= x;
        return res;
    }

    // Hamming distance between x and y
    int hammingDist(int x, int y) {
        return __builtin_popcount(x ^ y);
    }

----

🎭 Bitmask / Subset Enumeration
=================================

.. code-block:: cpp

    int n = 4;

    // All 2^n subsets
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { /* i in subset */ }
        }
    }

    // All subsets of mask (excluding empty)
    for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
        // process submask 'sub'
    }

----

🔁 Common Problems
==================

.. code-block:: cpp

    // Reverse 32 bits
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }

    // Count total set bits from 1 to n
    int totalBits(int n) {
        int count = 0, factor = 1;
        while (factor <= n) {
            int full = (n + 1) / (2 * factor);
            count += full * factor;
            int rem = (n + 1) % (2 * factor);
            count += max(0, rem - factor);
            factor <<= 1;
        }
        return count;
    }

    // Two numbers appearing once (rest appear twice) — partition by XOR bit
    pair<int,int> findTwo(vector<int>& nums) {
        int xorAll = 0;
        for (int x : nums) xorAll ^= x;
        int bit = xorAll & (-xorAll);    // rightmost differing bit
        int a = 0, b = 0;
        for (int x : nums) {
            if (x & bit) a ^= x;
            else b ^= x;
        }
        return {a, b};
    }
