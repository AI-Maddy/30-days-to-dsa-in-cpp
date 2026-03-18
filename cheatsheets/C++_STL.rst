.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> STL = Containers + Iterators + Algorithms. </span>
      <span style="color:#0f766e;">Every container has begin()/end(); every algorithm works on ranges.</span>
   </div>

======================
🚀 C++ STL Cheatsheet
======================

----

📦 Sequence Containers
=======================

.. code-block:: cpp

    vector<int> v;
    v.push_back(x);   // O(1) amortized
    v.pop_back();     // O(1)
    v[i];             // O(1) random access
    v.size();  v.empty();  v.front();  v.back();
    sort(v.begin(), v.end());                    // O(n log n)
    reverse(v.begin(), v.end());                 // O(n)
    v.erase(v.begin() + i);                      // O(n)
    v.insert(v.begin() + i, val);                // O(n)
    vector<int> v(n, 0);                         // n zeros
    vector<vector<int>> mat(n, vector<int>(m,0));// n×m matrix

    deque<int> dq;
    dq.push_front(x); dq.push_back(x);
    dq.pop_front();   dq.pop_back();             // all O(1)

----

🌳 Associative Containers
==========================

.. code-block:: cpp

    // map — sorted keys, O(log n) ops
    map<int,int> mp;
    mp[key] = val;
    mp.count(key);           // 1 or 0
    mp.find(key);            // iterator or mp.end()
    mp.erase(key);
    mp.lower_bound(x);       // first key >= x
    mp.upper_bound(x);       // first key > x
    for (auto& [k,v] : mp) { }   // structured binding (C++17)

    // unordered_map — O(1) average
    unordered_map<int,int> ump;
    ump.reserve(1 << 17);    // avoid rehashing for large inputs
    ump[key]++;

    // set — sorted unique elements
    set<int> s;
    s.insert(x); s.erase(x); s.count(x);
    *s.lower_bound(x);   // first element >= x
    *s.upper_bound(x);   // first element > x

    // unordered_set — O(1) average lookup/insert
    unordered_set<int> us;

----

📚 Adapter Containers
======================

.. code-block:: cpp

    stack<int> st;
    st.push(x); st.pop(); st.top(); st.empty();

    queue<int> q;
    q.push(x); q.pop(); q.front(); q.back();

    // Max-heap (default)
    priority_queue<int> pq;
    pq.push(x); pq.pop(); pq.top();

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minpq;

    // Custom comparator (min-heap by second of pair)
    auto cmp = [](pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

----

🔍 Key Algorithms (<algorithm>)
================================

.. code-block:: cpp

    sort(v.begin(), v.end());
    sort(v.begin(), v.end(), greater<int>());        // descending
    sort(v.begin(), v.end(), [](int a, int b){       // custom
        return a > b;
    });

    // Binary search (requires sorted range)
    binary_search(v.begin(), v.end(), x);            // bool
    auto it = lower_bound(v.begin(), v.end(), x);    // first >= x
    auto it = upper_bound(v.begin(), v.end(), x);    // first > x
    // Count occurrences in sorted array:
    int cnt = upper_bound(v.begin(),v.end(),x) - lower_bound(v.begin(),v.end(),x);

    // Aggregation
    int sum = accumulate(v.begin(), v.end(), 0);
    auto it = min_element(v.begin(), v.end());
    auto it = max_element(v.begin(), v.end());

    // Search
    auto it = find(v.begin(), v.end(), x);
    int c = count(v.begin(), v.end(), x);
    int c = count_if(v.begin(), v.end(), [](int x){ return x > 0; });

    // Permutations
    next_permutation(v.begin(), v.end());
    prev_permutation(v.begin(), v.end());

    // Fill / Generate
    fill(v.begin(), v.end(), 0);
    iota(v.begin(), v.end(), 1);                     // 1, 2, 3, ...
    rotate(v.begin(), v.begin() + k, v.end());       // left rotate by k

    // Remove duplicates (must sort first)
    v.erase(unique(v.begin(), v.end()), v.end());

----

⏱️ Complexity Summary
======================

+-------------------+----------+-----------+-------------------+
| Container         | Access   | Search    | Insert/Delete     |
+===================+==========+===========+===================+
| vector            | O(1)     | O(n)      | O(1)* at end      |
+-------------------+----------+-----------+-------------------+
| deque             | O(1)     | O(n)      | O(1) at ends      |
+-------------------+----------+-----------+-------------------+
| map / set         | O(log n) | O(log n)  | O(log n)          |
+-------------------+----------+-----------+-------------------+
| unordered_map/set | O(1) avg | O(1) avg  | O(1) avg          |
+-------------------+----------+-----------+-------------------+
| priority_queue    | O(1) top | —         | O(log n)          |
+-------------------+----------+-----------+-------------------+

\* amortized

----

💡 Common Patterns
==================

.. code-block:: cpp

    // Frequency map
    unordered_map<int,int> freq;
    for (int x : v) freq[x]++;

    // Sort by frequency descending (ties: smaller value first)
    sort(v.begin(), v.end(), [&](int a, int b){
        return freq[a] != freq[b] ? freq[a] > freq[b] : a < b;
    });

    // Coordinate compression
    vector<int> tmp = v;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int& x : v)
        x = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();

    // Sliding window max (monotonic deque stores indices)
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < (int)v.size(); i++) {
        while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
        while (!dq.empty() && v[dq.back()] <= v[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(v[dq.front()]);
    }
