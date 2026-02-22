---

# **Day 15 — Merge k Sorted Lists + Sort Linked List + Flatten Multilevel List (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Today’s problems combine:

- **Linked lists**
- **Heaps**
- **Divide & conquer**
- **Recursion**
- **Pointer manipulation**

These are not beginner problems — they are *elite‑level* linked list challenges that test your understanding of:

- Merging sorted structures  
- Recursion vs iteration  
- Priority queues  
- Multilevel pointer flattening  
- Divide‑and‑conquer sorting  

Mastering these unlocks the ability to solve complex linked list systems like:

- LRU/LFU caches  
- Multilevel data structures  
- File system trees  
- Priority‑based scheduling  
- K‑way merging (used in external sorting, MapReduce, etc.)

---

# **2. Merge k Sorted Linked Lists**

This is one of the most important linked list problems ever asked.

---

## **2.1 Problem Statement**

Given `k` sorted linked lists, merge them into one sorted list.

---

## **2.2 Approaches**

### **Approach A — Brute Force (O(N log N))**

Put all values in an array → sort → rebuild list.  
Not recommended.

---

### **Approach B — Merge Lists One by One (O(kN))**

Repeatedly merge two lists.  
Too slow for large k.

---

### **Approach C — Min‑Heap (Priority Queue) — O(N log k)**  
**Most popular interview solution.**

### **Implementation**

```cpp
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

    for (auto node : lists)
        if (node) pq.push(node);

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();

        tail->next = node;
        tail = tail->next;

        if (node->next)
            pq.push(node->next);
    }
    return dummy.next;
}
```

---

### **Approach D — Divide & Conquer (O(N log k))**

Merge lists in pairs:

```
k → k/2 → k/4 → ... → 1
```

### **Implementation**

```cpp
ListNode* mergeTwo(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->val < b->val) {
        a->next = mergeTwo(a->next, b);
        return a;
    } else {
        b->next = mergeTwo(a, b->next);
        return b;
    }
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;

    while (lists.size() > 1) {
        vector<ListNode*> merged;

        for (int i = 0; i < lists.size(); i += 2) {
            ListNode* l1 = lists[i];
            ListNode* l2 = (i + 1 < lists.size()) ? lists[i+1] : NULL;
            merged.push_back(mergeTwo(l1, l2));
        }
        lists = merged;
    }
    return lists[0];
}
```

---

# **3. Sort a Linked List (Merge Sort on Linked List)**

Arrays use quicksort or mergesort.  
Linked lists **must** use mergesort because:

- No random access  
- Splitting is easy  
- Merging is O(1) pointer manipulation  

---

## **3.1 Steps**

1. Find middle  
2. Split list  
3. Recursively sort left and right  
4. Merge sorted halves  

---

## **3.2 Implementation**

```cpp
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    // Step 1: find middle
    ListNode *slow = head, *fast = head, *prev = NULL;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL; // split list

    // Step 2: sort halves
    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);

    // Step 3: merge
    return mergeTwo(left, right);
}
```

Time: **O(n log n)**  
Space: **O(log n)** recursion stack

---

# **4. Flatten a Multilevel Doubly Linked List**

This is a beautiful pointer manipulation problem.

---

## **4.1 Structure**

Each node has:

- `next`
- `prev`
- `child` (points to another list)

Example:

```
1 → 2 → 3
      |
      7 → 8 → 9
          |
          11 → 12
```

Flatten into:

```
1 → 2 → 3 → 7 → 8 → 11 → 12 → 9
```

---

## **4.2 DFS‑Based Solution**

### **Implementation**

```cpp
Node* flatten(Node* head) {
    if (!head) return head;

    Node* curr = head;

    while (curr) {
        if (curr->child) {
            Node* next = curr->next;

            // flatten child
            Node* child = flatten(curr->child);

            curr->next = child;
            child->prev = curr;
            curr->child = NULL;

            // find tail of child list
            while (child->next)
                child = child->next;

            child->next = next;
            if (next) next->prev = child;
        }
        curr = curr->next;
    }
    return head;
}
```

---

# **5. Real‑World Applications**

---

### **Example 1 — External Sorting (Merge K Lists)**  
Used in:

- Databases  
- MapReduce  
- Big data pipelines  

---

### **Example 2 — File System Trees (Flattening)**  
Flattening directory structures.

---

### **Example 3 — Sorting Linked Data Streams**  
Used in:

- Network packet ordering  
- Log merging  
- Event stream processing  

---

### **Example 4 — Priority‑based scheduling**  
Min‑heap merging.

---

# **6. Interview‑Level Problems**

---

### **Problem 1 — Merge k sorted lists**  
Heap or divide‑and‑conquer.

---

### **Problem 2 — Sort linked list**  
Merge sort.

---

### **Problem 3 — Flatten multilevel list**  
DFS pointer manipulation.

---

### **Problem 4 — Merge two sorted lists**  
Classic recursion.

---

### **Problem 5 — Split list into k parts**  
Length calculation + pointer slicing.

---

# **7. Exercises (Try First)**

---

### **Exercise 1**  
Merge k sorted linked lists using a min‑heap.

---

### **Exercise 2**  
Sort a linked list using merge sort.

---

### **Exercise 3**  
Flatten a multilevel doubly linked list.

---

### **Exercise 4**  
Merge two sorted lists (recursive + iterative).

---

### **Exercise 5**  
Split a linked list into k equal parts.

---

# **8. Solutions**

---

### **Solution 1 — Merge k lists**  
Use priority queue.

---

### **Solution 2 — Sort list**  
Use merge sort.

---

### **Solution 3 — Flatten list**  
Use DFS pointer rewiring.

---

### **Solution 4 — Merge two lists**  
Use mergeTwo().

---

### **Solution 5 — Split list**  
Compute length → divide → cut pointers.

---

# **9. Summary**

Today you mastered:

- Merging k sorted lists (heap + divide & conquer)  
- Sorting linked lists using merge sort  
- Flattening multilevel doubly linked lists  
- Advanced pointer manipulation  
- Real‑world applications of linked list merging  
- High‑level interview patterns  

This day marks the end of the linked list trilogy (Days 12–15), and you now have elite‑level mastery over all linked list patterns.

---

.. quality-upgrade-2026-02-20

Quality Upgrade: Active Recall + Practice
-----------------------------------------

Quick Revision Checklist
~~~~~~~~~~~~~~~~~~~~~~~~

- Draw pointer transitions before coding.
- Know dummy-node pattern for head-sensitive operations.
- Apply fast-slow pointer for cycle, middle, palindrome.
- Track ownership/memory safety for node deletion.

Common Mistakes to Avoid
~~~~~~~~~~~~~~~~~~~~~~~~

- Losing next pointer before rewiring.
- Not handling 0/1-node edge cases.
- Incorrect split before merge sort on lists.
- Cycle detection logic that dereferences null.

Practice Ladder (Progressive)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Easy: reverse list, middle node.
- Medium: remove Nth from end, detect cycle.
- Hard: flatten multilevel list, merge k sorted lists.

