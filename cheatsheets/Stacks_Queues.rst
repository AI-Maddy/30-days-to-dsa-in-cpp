.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Monotonic stack: pop when invariant breaks, then push. Store indices, not just values. </span>
      <span style="color:#0f766e;">Deque for sliding window max: pop front (out of window), pop back (smaller than current).</span>
   </div>

=============================
📚 Stacks & Queues Cheatsheet
=============================

----

🔧 STL Operations
==================

.. code-block:: cpp

    stack<int> st;
    st.push(x); st.pop(); st.top(); st.empty(); st.size();

    queue<int> q;
    q.push(x); q.pop(); q.front(); q.back(); q.empty();

    deque<int> dq;
    dq.push_front(x); dq.push_back(x);
    dq.pop_front();   dq.pop_back();
    dq.front(); dq.back(); dq[i];

----

📈 Monotonic Stack — Next Greater Element
==========================================

.. code-block:: cpp

    // For each element, find next greater element to the right
    vector<int> nextGreater(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, -1);
        stack<int> st;  // stores indices
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] < a[i]) {
                res[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    // Next smaller element — change < to >
    // Previous greater element — iterate right to left

----

📉 Stock Span
=============

.. code-block:: cpp

    // Span = number of consecutive days with price <= today
    vector<int> stockSpan(vector<int>& prices) {
        int n = prices.size();
        vector<int> span(n);
        stack<int> st;  // indices of unresolved spans
        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[st.top()] <= prices[i])
                st.pop();
            span[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        return span;
    }

----

🏛️ Largest Rectangle in Histogram
===================================

.. code-block:: cpp

    int largestRect(vector<int>& h) {
        int n = h.size(), maxArea = 0;
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            int cur = (i == n) ? 0 : h[i];
            while (!st.empty() && h[st.top()] > cur) {
                int height = h[st.top()]; st.pop();
                int width  = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

----

🪟 Sliding Window Maximum (Deque)
==================================

.. code-block:: cpp

    vector<int> slidingWindowMax(vector<int>& a, int k) {
        deque<int> dq;  // stores indices, front = max index
        vector<int> res;
        for (int i = 0; i < (int)a.size(); i++) {
            // Remove indices out of window
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            // Maintain decreasing order
            while (!dq.empty() && a[dq.back()] <= a[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(a[dq.front()]);
        }
        return res;
    }

----

✅ Valid Parentheses
====================

.. code-block:: cpp

    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') { st.push(c); }
            else {
                if (st.empty()) return false;
                char top = st.top(); st.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) return false;
            }
        }
        return st.empty();
    }

----

🧮 Evaluate RPN
================

.. code-block:: cpp

    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (auto& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(stoll(t));
            }
        }
        return st.top();
    }

----

📦 Min Stack
=============

.. code-block:: cpp

    class MinStack {
        stack<int> st, minSt;
    public:
        void push(int val) {
            st.push(val);
            if (minSt.empty() || val <= minSt.top()) minSt.push(val);
        }
        void pop() {
            if (st.top() == minSt.top()) minSt.pop();
            st.pop();
        }
        int top() { return st.top(); }
        int getMin() { return minSt.top(); }
    };
