.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Binary search works on any monotonic condition, not just sorted arrays. </span>
      <span style="color:#0f766e;">Template: lo=min, hi=max, check feasibility(mid), shrink range.</span>
   </div>

===========================
🔍 Binary Search Cheatsheet
===========================

----

📌 Standard Template
=====================

.. code-block:: cpp

    // Find exact target in sorted array — O(log n)
    int binarySearch(vector<int>& a, int target) {
        int lo = 0, hi = (int)a.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;   // avoid overflow
            if (a[mid] == target) return mid;
            else if (a[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

----

🎯 Lower / Upper Bound
=======================

.. code-block:: cpp

    // First position >= target  (lower_bound)
    int lowerBound(vector<int>& a, int target) {
        int lo = 0, hi = (int)a.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;  // index of first element >= target
    }

    // First position > target  (upper_bound)
    int upperBound(vector<int>& a, int target) {
        int lo = 0, hi = (int)a.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return lo;  // index of first element > target
    }

    // Count of target in sorted array
    int count = upperBound(a, target) - lowerBound(a, target);

    // STL equivalents
    lower_bound(a.begin(), a.end(), x);   // first >= x
    upper_bound(a.begin(), a.end(), x);   // first > x

----

📈 Binary Search on Answer Pattern
====================================

Use when: answer is monotonic and you can check feasibility.

.. code-block:: cpp

    // Template: minimize the maximum / maximize the minimum
    bool feasible(vector<int>& a, int mid, int k) {
        // return true if 'mid' is a valid answer given k
        int parts = 1, curSum = 0;
        for (int x : a) {
            if (curSum + x > mid) { parts++; curSum = 0; }
            curSum += x;
        }
        return parts <= k;
    }

    int binarySearchOnAnswer(vector<int>& a, int k) {
        int lo = *max_element(a.begin(), a.end());  // min possible
        int hi = accumulate(a.begin(), a.end(), 0); // max possible
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(a, mid, k)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

----

🌀 Search in Rotated Sorted Array
===================================

.. code-block:: cpp

    int searchRotated(vector<int>& a, int target) {
        int lo = 0, hi = (int)a.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] == target) return mid;
            // Left half is sorted
            if (a[lo] <= a[mid]) {
                if (a[lo] <= target && target < a[mid]) hi = mid - 1;
                else lo = mid + 1;
            } else {  // Right half is sorted
                if (a[mid] < target && target <= a[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }

----

⛰️ Peak Element
================

.. code-block:: cpp

    // Find any peak (a[i] > a[i-1] and a[i] > a[i+1])
    int findPeak(vector<int>& a) {
        int lo = 0, hi = (int)a.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] < a[mid + 1]) lo = mid + 1;  // peak is to the right
            else hi = mid;                            // peak is at mid or left
        }
        return lo;
    }

----

📋 Search in 2D Matrix
=======================

.. code-block:: cpp

    // Matrix is row-sorted and each row's first > prev row's last
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int lo = 0, hi = n * m - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = mat[mid / m][mid % m];
            if (val == target) return true;
            else if (val < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }

    // Row-sorted and column-sorted matrix: start top-right
    bool searchSortedMatrix(vector<vector<int>>& mat, int target) {
        int r = 0, c = (int)mat[0].size() - 1;
        while (r < (int)mat.size() && c >= 0) {
            if (mat[r][c] == target) return true;
            else if (mat[r][c] > target) c--;
            else r++;
        }
        return false;
    }

----

🐄 Aggressive Cows (Classic Binary Search on Answer)
======================================================

.. code-block:: cpp

    bool canPlace(vector<int>& stalls, int minDist, int k) {
        int count = 1, last = stalls[0];
        for (int i = 1; i < (int)stalls.size(); i++) {
            if (stalls[i] - last >= minDist) { count++; last = stalls[i]; }
            if (count >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int lo = 1, hi = stalls.back() - stalls.front(), ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlace(stalls, mid, k)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
