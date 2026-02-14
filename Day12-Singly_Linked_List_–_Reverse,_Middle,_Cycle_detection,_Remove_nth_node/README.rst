---

# **Day 12 — Singly Linked List: Reverse, Middle, Cycle Detection, Remove Nth Node (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Singly Linked Lists are the backbone of many advanced data structures:

- Stacks & Queues  
- Hashing (chaining)  
- LRU Cache  
- Graph adjacency lists  
- Custom memory allocators  
- Dynamic data structures  

Today’s goal is to master the **core operations** that appear in almost every interview:

- Creating and traversing a linked list  
- Reversing a linked list (iterative + recursive)  
- Finding the middle node  
- Detecting and removing cycles  
- Removing the Nth node from the end  
- Merging two sorted lists  
- Deleting nodes efficiently  

This day is extremely important — these patterns appear repeatedly in FAANG interviews.

---

# **2. Node Structure**

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

---

# **3. Traversal**

```cpp
void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}
```

---

# **4. Reverse a Linked List (Iterative)**

This is one of the most important interview problems.

### **4.1 Logic**

Use three pointers:

```
prev, curr, next
```

### **4.2 Implementation**

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head;

    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
```

Time: **O(n)**  
Space: **O(1)**

---

# **5. Reverse a Linked List (Recursive)**

```cpp
ListNode* reverseRec(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
```

---

# **6. Find Middle of Linked List (Fast & Slow Pointers)**

### **6.1 Logic**

```
slow moves 1 step
fast moves 2 steps
```

### **6.2 Implementation**

```cpp
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

---

# **7. Detect Cycle (Floyd’s Cycle Detection)**

### **7.1 Logic**

If fast and slow pointers meet → cycle exists.

### **7.2 Implementation**

```cpp
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}
```

---

# **8. Find Start of Cycle**

Once slow == fast:

1. Move slow to head  
2. Move both slow and fast one step at a time  
3. They meet at cycle start  

```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
```

---

# **9. Remove Nth Node from End**

### **9.1 Logic**

Use two pointers:

- Move fast pointer n steps  
- Move both slow and fast until fast reaches end  
- Delete slow->next  

### **9.2 Implementation**

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *slow = &dummy, *fast = &dummy;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy.next;
}
```

---

# **10. Merge Two Sorted Lists**

```cpp
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->val < b->val) {
        a->next = mergeTwoLists(a->next, b);
        return a;
    } else {
        b->next = mergeTwoLists(a, b->next);
        return b;
    }
}
```

---

# **11. Delete Node (Given Only Node Pointer)**

Classic trick:

```cpp
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
```

---

# **12. Real‑World Examples**

---

### **Example 1 — Check if Linked List is Palindrome**

1. Find middle  
2. Reverse second half  
3. Compare halves  

---

### **Example 2 — Remove duplicates from sorted list**

```cpp
ListNode* curr = head;
while (curr && curr->next) {
    if (curr->val == curr->next->val)
        curr->next = curr->next->next;
    else
        curr = curr->next;
}
```

---

### **Example 3 — Intersection of two linked lists**

Use length difference or two‑pointer switching.

---

### **Example 4 — Add two numbers (Linked List)**

Digit‑wise addition with carry.

---

# **13. Interview‑Level Problems**

---

### **Problem 1 — Reverse linked list**  
Iterative + recursive.

---

### **Problem 2 — Detect cycle**  
Floyd’s algorithm.

---

### **Problem 3 — Remove Nth node from end**  
Two‑pointer technique.

---

### **Problem 4 — Merge two sorted lists**  
Classic recursion.

---

### **Problem 5 — Find intersection of two lists**  
Two‑pointer switching.

---

# **14. Exercises (Try First)**

---

### **Exercise 1**  
Reverse a linked list (iterative + recursive).

---

### **Exercise 2**  
Find the middle node.

---

### **Exercise 3**  
Detect cycle and return cycle start.

---

### **Exercise 4**  
Remove Nth node from end.

---

### **Exercise 5**  
Merge two sorted linked lists.

---

# **15. Solutions**

---

### **Solution 1 — Reverse list**

Use code from section 4.

---

### **Solution 2 — Middle node**

Use fast‑slow pointers.

---

### **Solution 3 — Detect cycle**

Use Floyd’s algorithm.

---

### **Solution 4 — Remove Nth node**

Use two‑pointer technique.

---

### **Solution 5 — Merge lists**

Use recursive merge.

---

# **16. Summary**

Today you mastered:

- Linked list fundamentals  
- Reversing (iterative + recursive)  
- Middle node detection  
- Cycle detection + cycle start  
- Removing Nth node from end  
- Merging sorted lists  
- Deleting nodes efficiently  

These operations form the foundation for advanced linked list problems in Days 13–15.

---
