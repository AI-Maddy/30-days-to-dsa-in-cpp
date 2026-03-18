.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> For interviews: know merge sort and quick sort inside out. Use std::sort in practice. </span>
      <span style="color:#0f766e;">Stability matters when sorting by one key while preserving another.</span>
   </div>

======================
📊 Sorting Cheatsheet
======================

----

⏱️ Complexity Summary
======================

+-------------------+-------------+-------------+---------+-----------+
| Algorithm         | Best        | Average     | Worst   | Space     |
+===================+=============+=============+=========+===========+
| Bubble Sort       | O(n)        | O(n²)       | O(n²)   | O(1)      |
+-------------------+-------------+-------------+---------+-----------+
| Selection Sort    | O(n²)       | O(n²)       | O(n²)   | O(1)      |
+-------------------+-------------+-------------+---------+-----------+
| Insertion Sort    | O(n)        | O(n²)       | O(n²)   | O(1)      |
+-------------------+-------------+-------------+---------+-----------+
| Merge Sort        | O(n log n)  | O(n log n)  | O(n log n)| O(n)   |
+-------------------+-------------+-------------+---------+-----------+
| Quick Sort        | O(n log n)  | O(n log n)  | O(n²)   | O(log n)  |
+-------------------+-------------+-------------+---------+-----------+
| Heap Sort         | O(n log n)  | O(n log n)  | O(n log n)| O(1)   |
+-------------------+-------------+-------------+---------+-----------+
| Counting Sort     | O(n+k)      | O(n+k)      | O(n+k)  | O(k)      |
+-------------------+-------------+-------------+---------+-----------+
| Radix Sort        | O(d(n+k))   | O(d(n+k))   | O(d(n+k))| O(n+k) |
+-------------------+-------------+-------------+---------+-----------+

Stable sorts: Merge, Insertion, Bubble, Counting  
Unstable: Quick, Selection, Heap

----

🔄 Merge Sort
==============

.. code-block:: cpp

    void merge(vector<int>& a, int l, int m, int r) {
        vector<int> left(a.begin()+l, a.begin()+m+1);
        vector<int> right(a.begin()+m+1, a.begin()+r+1);
        int i = 0, j = 0, k = l;
        while (i < (int)left.size() && j < (int)right.size())
            a[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
        while (i < (int)left.size())  a[k++] = left[i++];
        while (j < (int)right.size()) a[k++] = right[j++];
    }

    void mergeSort(vector<int>& a, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }

----

⚡ Quick Sort
=============

.. code-block:: cpp

    int partition(vector<int>& a, int l, int r) {
        int pivot = a[r], i = l - 1;
        for (int j = l; j < r; j++) {
            if (a[j] <= pivot) swap(a[++i], a[j]);
        }
        swap(a[++i], a[r]);
        return i;
    }

    void quickSort(vector<int>& a, int l, int r) {
        if (l >= r) return;
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }

----

🪣 Counting Sort
================

.. code-block:: cpp

    // Works for integers in range [0, max_val]
    void countingSort(vector<int>& a) {
        int maxVal = *max_element(a.begin(), a.end());
        vector<int> count(maxVal + 1, 0);
        for (int x : a) count[x]++;
        int idx = 0;
        for (int v = 0; v <= maxVal; v++)
            while (count[v]-- > 0) a[idx++] = v;
    }

----

🔧 Dutch National Flag (0s, 1s, 2s)
=====================================

.. code-block:: cpp

    void sortColors(vector<int>& a) {
        int lo = 0, mid = 0, hi = (int)a.size() - 1;
        while (mid <= hi) {
            if (a[mid] == 0) swap(a[lo++], a[mid++]);
            else if (a[mid] == 1) mid++;
            else swap(a[mid], a[hi--]);
        }
    }

----

🎛️ Custom Comparators
=======================

.. code-block:: cpp

    // Sort descending
    sort(v.begin(), v.end(), greater<int>());

    // Sort pairs by second element ascending
    sort(v.begin(), v.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });

    // Sort strings by length, ties alphabetically
    sort(v.begin(), v.end(), [](const string& a, const string& b){
        return a.size() != b.size() ? a.size() < b.size() : a < b;
    });

    // Sort by frequency descending
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    sort(nums.begin(), nums.end(), [&](int a, int b){
        return freq[a] != freq[b] ? freq[a] > freq[b] : a < b;
    });

    // Stable sort preserves relative order of equal elements
    stable_sort(v.begin(), v.end(), cmp);

----

🔢 STL Sort Usage
==================

.. code-block:: cpp

    vector<int> v = {3,1,4,1,5,9};
    sort(v.begin(), v.end());              // ascending
    sort(v.begin(), v.end(), greater<>{}); // descending

    // Partial sort: first k elements sorted
    partial_sort(v.begin(), v.begin()+k, v.end());

    // nth_element: O(n) average, puts correct element at position k
    nth_element(v.begin(), v.begin()+k, v.end());
    // v[k] is now the kth smallest element
