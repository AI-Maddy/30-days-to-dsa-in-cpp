---

# **Day 13 — Doubly Linked List + Circular Linked List + LRU Cache Intuition (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Today’s focus is on **advanced linked list structures** that power real‑world systems:

- **Doubly Linked List (DLL)**  
- **Circular Linked List (CLL)**  
- **LRU Cache (DLL + HashMap)**  

These structures are used in:

- Browser history  
- Undo/redo systems  
- Media playlists  
- Task schedulers  
- Cache systems (LRU, LFU)  
- OS memory management  
- Graph adjacency lists  

This day builds the foundation for implementing efficient caches and advanced data structures.

---

# **2. Doubly Linked List (DLL)**

A DLL node contains:

- `prev` pointer  
- `next` pointer  
- `value`  

### **2.1 Node Structure**

```cpp
struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(NULL), next(NULL) {}
};
```

---

## **3. Basic Operations on DLL**

---

### **3.1 Insert at Head**

```cpp
void insertHead(Node* &head, int x) {
    Node* n = new Node(x);
    n->next = head;
    if (head) head->prev = n;
    head = n;
}
```

---

### **3.2 Insert at Tail**

```cpp
void insertTail(Node* &head, int x) {
    Node* n = new Node(x);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}
```

---

### **3.3 Delete a Node**

```cpp
void deleteNode(Node* &head, Node* del) {
    if (!head || !del) return;

    if (head == del) head = del->next;

    if (del->next) del->next->prev = del->prev;
    if (del->prev) del->prev->next = del->next;

    delete del;
}
```

---

## **4. Advantages of DLL**

- Bidirectional traversal  
- Easy deletion (O(1))  
- Easy insertion before/after a node  
- Used in LRU Cache  

---

# **5. Circular Linked List (CLL)**

A circular linked list’s last node points back to the head.

```
head → 1 → 2 → 3 → 4 → (back to head)
```

---

## **6. CLL Node Structure**

Same as singly linked list.

---

## **7. Basic Operations on CLL**

---

### **7.1 Insert at Head**

```cpp
void insertHead(Node* &head, int x) {
    Node* n = new Node(x);

    if (!head) {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) temp = temp->next;

    temp->next = n;
    n->next = head;
    head = n;
}
```

---

### **7.2 Insert at Tail**

```cpp
void insertTail(Node* &head, int x) {
    Node* n = new Node(x);

    if (!head) {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) temp = temp->next;

    temp->next = n;
    n->next = head;
}
```

---

### **7.3 Delete Head**

```cpp
void deleteHead(Node* &head) {
    if (!head) return;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != head) temp = temp->next;

    Node* del = head;
    temp->next = head->next;
    head = head->next;

    delete del;
}
```

---

# **8. Applications of Circular Linked List**

- Round‑robin scheduling  
- Multiplayer games  
- Music playlists  
- Token passing in networks  
- Implementing queues with wrap‑around  

---

# **9. LRU Cache — Intuition & Implementation**

LRU (Least Recently Used) Cache is one of the most important interview problems.

### **9.1 Requirements**

- `get(key)` → O(1)  
- `put(key, value)` → O(1)  
- Remove least recently used item when full  

### **9.2 Data Structures Used**

- **Doubly Linked List** → maintain usage order  
- **HashMap** → store key → node pointer  

---

## **10. LRU Cache Architecture**

```
HashMap: key → DLL node

DLL:
head = most recently used
tail = least recently used
```

Operations:

- Move accessed node to head  
- Insert new node at head  
- Remove tail when capacity full  

---

## **11. LRU Cache Implementation**

```cpp
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void insert(Node* node) {
        Node* p = head->next;
        head->next = node;
        node->prev = head;
        node->next = p;
        p->prev = node;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            remove(mp[key]);
        }

        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            remove(tail->prev);
        }

        Node* node = new Node(value);
        node->key = key;
        insert(node);
        mp[key] = node;
    }
};
```

---

# **12. Real‑World Examples**

---

### **Example 1 — Browser History**

DLL allows:

- Back  
- Forward  
- Insert new page  

---

### **Example 2 — Undo/Redo System**

DLL stores operations.

---

### **Example 3 — Music Playlist**

CLL allows infinite looping.

---

### **Example 4 — LRU Cache in OS**

Used in:

- Page replacement  
- Memory management  
- CPU cache  

---

# **13. Interview‑Level Problems**

---

### **Problem 1 — LRU Cache**  
HashMap + DLL.

---

### **Problem 2 — Flatten multilevel DLL**  
Recursive pointer manipulation.

---

### **Problem 3 — Insert/Delete in DLL**  
Pointer adjustments.

---

### **Problem 4 — Detect cycle in CLL**  
Use fast‑slow pointers.

---

### **Problem 5 — Delete node in CLL**  
Pointer rewiring.

---

# **14. Exercises (Try First)**

---

### **Exercise 1**  
Implement a doubly linked list with insert/delete operations.

---

### **Exercise 2**  
Implement a circular linked list with insert/delete operations.

---

### **Exercise 3**  
Implement LRU Cache with O(1) operations.

---

### **Exercise 4**  
Flatten a multilevel doubly linked list.

---

### **Exercise 5**  
Check if a circular linked list has a cycle (trick question).

---

# **15. Solutions**

---

### **Solution 1 — DLL operations**

Use code from section 3.

---

### **Solution 2 — CLL operations**

Use code from section 7.

---

### **Solution 3 — LRU Cache**

Use implementation from section 11.

---

### **Solution 4 — Flatten DLL**

Recursive pointer merging.

---

### **Solution 5 — Cycle in CLL**

A CLL **always** has a cycle.

---

# **16. Summary**

Today you mastered:

- Doubly linked lists  
- Circular linked lists  
- Efficient insert/delete operations  
- LRU Cache architecture  
- HashMap + DLL integration  
- Real‑world applications  
- Interview‑level linked list patterns  

This day builds the foundation for advanced linked list problems in Days 14 and 15.

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

