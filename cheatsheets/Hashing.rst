.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Hash maps turn O(n) lookups into O(1). Key patterns: frequency, complement lookup, prefix sum + map. </span>
      <span style="color:#0f766e;">When you need "have I seen X before?" → use hash map/set.</span>
   </div>

======================
#️⃣ Hashing Cheatsheet
======================

----

⚡ unordered_map vs map
========================

.. code-block:: cpp

    unordered_map<int,int> ump;    // O(1) avg, no ordering
    map<int,int> mp;               // O(log n), sorted keys

    ump[key]++;                    // insert or increment
    ump.count(key);                // 0 or 1 — existence check
    ump.find(key) != ump.end();    // iterator-based existence check
    ump.erase(key);
    for (auto& [k,v] : ump) { }

    // Avoid hash collision attacks in contest:
    struct custom_hash {
        size_t operator()(int x) const {
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            return (x >> 16) ^ x;
        }
    };
    unordered_map<int,int,custom_hash> safe_map;

----

🔢 Frequency Counting Pattern
==============================

.. code-block:: cpp

    // Build frequency map
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;

    // Find max frequency element
    int maxFreq = 0, maxElem = 0;
    for (auto& [val, cnt] : freq) {
        if (cnt > maxFreq) { maxFreq = cnt; maxElem = val; }
    }

    // Anagram check (same char frequencies)
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> cnt;
        for (char c : s) cnt[c]++;
        for (char c : t) {
            if (--cnt[c] < 0) return false;
        }
        return true;
    }

----

🎯 Two Sum Pattern
==================

.. code-block:: cpp

    // Two Sum — O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;  // value -> index
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement))
                return {seen[complement], i};
            seen[nums[i]] = i;
        }
        return {};
    }

----

🪟 Sliding Window + Hash Map
=============================

.. code-block:: cpp

    // Longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last;  // char -> last seen index
        int l = 0, maxLen = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            if (last.count(s[r]) && last[s[r]] >= l)
                l = last[s[r]] + 1;
            last[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }

----

➕ Prefix Sum + Hash Map
========================

.. code-block:: cpp

    // Count subarrays with sum == k
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1;   // empty prefix
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            count += prefixCount[sum - k];
            prefixCount[sum]++;
        }
        return count;
    }

    // Longest subarray with sum == k (using first occurrence)
    int longestSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> firstOccurrence;
        firstOccurrence[0] = -1;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            if (firstOccurrence.count(sum - k))
                maxLen = max(maxLen, i - firstOccurrence[sum - k]);
            if (!firstOccurrence.count(sum))
                firstOccurrence[sum] = i;
        }
        return maxLen;
    }

----

🔗 Longest Consecutive Sequence
================================

.. code-block:: cpp

    // O(n) using unordered_set
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen = 0;
        for (int x : s) {
            if (!s.count(x - 1)) {   // start of a sequence
                int cur = x, len = 1;
                while (s.count(cur + 1)) { cur++; len++; }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }

----

📦 Group Anagrams
==================

.. code-block:: cpp

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [k, v] : mp) res.push_back(v);
        return res;
    }
