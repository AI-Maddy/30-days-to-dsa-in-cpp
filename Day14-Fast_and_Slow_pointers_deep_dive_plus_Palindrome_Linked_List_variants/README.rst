---

# **Day 14 — Fast & Slow Pointers Deep Dive + Palindrome Linked List Variants (README.rst)**  
*30 Days to DSA in C++ — Ultra‑Premium Edition*

---

## **1. Introduction**

Fast & slow pointers (also called **tortoise and hare**) are one of the most elegant and powerful techniques in linked list problems.  
They allow you to solve problems that seem impossible with simple traversal:

- Find middle of list  
- Detect cycle  
- Find cycle start  
- Check if list is palindrome  
- Remove Nth node from end  
- Reorder list  
- Split list into halves  
- Detect intersection patterns  

Today’s goal is to master:

- Fast & slow pointer mechanics  
- Cycle detection & cycle start  
- Palindrome linked list (multiple variants)  
- Reorder list  
- Odd-even linked list  
- Intersection logic  
- Deep intuition behind pointer movement  

This day is extremely important — these patterns appear in almost every FAANG interview.

---

# **2. Fast & Slow Pointer Fundamentals**

### **2.1 Core Idea**

```
slow moves 1 step
fast moves 2 steps
```

This creates a **relative speed difference** that reveals structural properties of the list.

---

## **3. Find Middle of Linked List**

### **3.1 Implementation**

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

If even length → returns second middle.

---

# **4. Detect Cycle (Floyd’s Algorithm)**

### **4.1 Logic**

If fast and slow meet → cycle exists.

### **4.2 Implementation**

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

# **5. Find Start of Cycle**

Once slow == fast:

1. Move slow to head  
2. Move both slow and fast one step  
3. They meet at cycle start  

### **5.1 Implementation**

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

# **6. Palindrome Linked List — Multiple Approaches**

This is one of the most important linked list problems.

---

## **6.1 Approach 1 — Convert to Array (Simple)**

```cpp
vector<int> v;
while (head) {
    v.push_back(head->val);
    head = head->next;
}
return equal(v.begin(), v.begin() + v.size()/2, v.rbegin());
```

Time: O(n)  
Space: O(n)

---

## **6.2 Approach 2 — Reverse Second Half (Optimal)**

### **Steps**

1. Find middle  
2. Reverse second half  
3. Compare halves  
4. Restore list (optional)  

### **Implementation**

```cpp
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: find middle
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: reverse second half
    ListNode* second = reverseList(slow->next);

    // Step 3: compare halves
    ListNode *p1 = head, *p2 = second;
    while (p2) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}
```

Time: **O(n)**  
Space: **O(1)**

---

## **6.3 Approach 3 — Recursion (Elegant but heavy)**

Use recursion to compare front and back.

---

# **7. Reorder List (L0 → Ln → L1 → Ln-1 …)**

### **Steps**

1. Find middle  
2. Reverse second half  
3. Merge two halves  

### **Implementation**

```cpp
void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    // Step 1: middle
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: reverse second half
    ListNode* second = reverseList(slow->next);
    slow->next = NULL;

    // Step 3: merge
    ListNode *first = head;
    while (second) {
        ListNode* t1 = first->next;
        ListNode* t2 = second->next;

        first->next = second;
        second->next = t1;

        first = t1;
        second = t2;
    }
}
```

---

# **8. Odd-Even Linked List**

Group odd index nodes first, then even index nodes.

```cpp
ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;

    ListNode *odd = head, *even = head->next, *evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}
```

---

# **9. Intersection of Two Linked Lists**

### **9.1 Two‑Pointer Switching Trick**

```cpp
ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
    ListNode *p1 = a, *p2 = b;

    while (p1 != p2) {
        p1 = p1 ? p1->next : b;
        p2 = p2 ? p2->next : a;
    }
    return p1;
}
```

Time: **O(n + m)**  
Space: **O(1)**

---

# **10. Deep Intuition Behind Fast & Slow Pointers**

### **10.1 Why do they meet in a cycle?**

Because fast pointer gains 1 node per step relative to slow.  
Eventually, fast “laps” slow.

### **10.2 Why does moving slow to head find cycle start?**

Because:

```
distance(head → cycleStart) = distance(meetingPoint → cycleStart)
```

### **10.3 Why does reversing second half detect palindrome?**

Because linked lists cannot be indexed backward.  
Reversing creates a backward traversal.

---

# **11. Real‑World Examples**

---

### **Example 1 — Check if list is palindrome**  
Reverse second half.

---

### **Example 2 — Detect cycle in network routing**  
Fast‑slow pointer logic.

---

### **Example 3 — Reorder playlist**  
Reorder list pattern.

---

### **Example 4 — Split list into halves**  
Middle pointer.

---

# **12. Interview‑Level Problems**

---

### **Problem 1 — Palindrome Linked List**  
Reverse second half.

---

### **Problem 2 — Reorder List**  
Middle + reverse + merge.

---

### **Problem 3 — Detect Cycle**  
Floyd’s algorithm.

---

### **Problem 4 — Find Cycle Start**  
Reset slow to head.

---

### **Problem 5 — Intersection of Two Lists**  
Two‑pointer switching.

---

# **13. Exercises (Try First)**

---

### **Exercise 1**  
Check if a linked list is palindrome (O(1) space).

---

### **Exercise 2**  
Reorder a linked list.

---

### **Exercise 3**  
Detect cycle and return cycle start.

---

### **Exercise 4**  
Split linked list into two halves.

---

### **Exercise 5**  
Find intersection of two linked lists.

---

# **14. Solutions**

---

### **Solution 1 — Palindrome**  
Use reverse‑second‑half method.

---

### **Solution 2 — Reorder list**  
Use middle + reverse + merge.

---

### **Solution 3 — Cycle start**  
Use Floyd’s algorithm.

---

### **Solution 4 — Split list**  
Use middle pointer.

---

### **Solution 5 — Intersection**  
Use two‑pointer switching.

---
