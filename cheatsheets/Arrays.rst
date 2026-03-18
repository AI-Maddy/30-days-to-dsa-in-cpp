.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Two pointers: start both ends, move inward. Sliding window: expand right, shrink left. </span>
      <span style="color:#0f766e;">Prefix sum: precompute to answer range queries in O(1).</span>
   </div>

======================
📊 Arrays Cheatsheet
======================

----

👆 Two Pointers Pattern
========================

**Left-Right (opposite ends):**

.. code-block:: cpp

    // Two Sum in sorted array
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == target) { /* found */ break; }
        else if (sum < target) l++;
        else r--;
    }

    // Trapping Rain Water
    int l = 0, r = n-1, lMax = 0, rMax = 0, water = 0;
    while (l < r) {
        if (a[l] < a[r]) {
            lMax = max(lMax, a[l]);
            water += lMax - a[l]; l++;
        } else {
            rMax = max(rMax, a[r]);
            water += rMax - a[r]; r--;
        }
    }

**Same Direction:**

.. code-block:: cpp

    // Remove duplicates from sorted array (in-place)
    int slow = 0;
    for (int fast = 1; fast < n; fast++) {
        if (a[fast] != a[slow]) a[++slow] = a[fast];
    }
    // result has slow+1 elements

----

🪟 Sliding Window Pattern
==========================

**Fixed window of size k:**

.. code-block:: cpp

    int windowSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        windowSum += a[i];
        if (i >= k) windowSum -= a[i - k];
        if (i >= k - 1) maxSum = max(maxSum, windowSum);
    }

**Variable window (expand right, shrink left):**

.. code-block:: cpp

    // Longest substring with at most k distinct characters
    unordered_map<char,int> freq;
    int l = 0, maxLen = 0;
    for (int r = 0; r < n; r++) {
        freq[s[r]]++;
        while ((int)freq.size() > k) {
            freq[s[l]]--;
            if (freq[s[l]] == 0) freq.erase(s[l]);
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
    }

----

➕ Prefix Sum
==============

.. code-block:: cpp

    // Build prefix sum
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];

    // Range sum [l, r] in O(1)
    int rangeSum = pre[r+1] - pre[l];

    // 2D prefix sum
    vector<vector<int>> p(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            p[i][j] = a[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    // Rectangle [r1,c1] to [r2,c2]:
    int rect = p[r2+1][c2+1] - p[r1][c2+1] - p[r2+1][c1] + p[r1][c1];

----

📉 Difference Array (Range Updates)
=====================================

.. code-block:: cpp

    // Add val to range [l, r]
    vector<int> diff(n + 1, 0);
    // Update: add val to a[l..r]
    diff[l] += val;
    diff[r+1] -= val;
    // Reconstruct: prefix sum of diff
    for (int i = 1; i < n; i++) diff[i] += diff[i-1];

----

📈 Kadane's Algorithm (Max Subarray)
======================================

.. code-block:: cpp

    int maxSum = INT_MIN, curSum = 0;
    int start = 0, end = 0, tempStart = 0;
    for (int i = 0; i < n; i++) {
        curSum += a[i];
        if (curSum > maxSum) {
            maxSum = curSum;
            start = tempStart; end = i;
        }
        if (curSum < 0) {
            curSum = 0;
            tempStart = i + 1;
        }
    }

----

🔍 Binary Search on Arrays
============================

.. code-block:: cpp

    // Standard binary search
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // avoid overflow
        if (a[mid] == target) return mid;
        else if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;  // not found

    // STL equivalents
    lower_bound(v.begin(), v.end(), x);  // first >= x
    upper_bound(v.begin(), v.end(), x);  // first > x

----

🔄 Rotation Tricks
===================

.. code-block:: cpp

    // Left rotate array by k positions (3-reverse trick)
    void rotate(vector<int>& a, int k) {
        k %= a.size();
        reverse(a.begin(), a.begin() + k);
        reverse(a.begin() + k, a.end());
        reverse(a.begin(), a.end());
    }
