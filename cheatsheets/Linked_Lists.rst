.. MEMORY-AID-BLOCK

.. raw:: html

   <div style="border:1px solid #4f46e5; padding:10px; border-radius:8px; background:#eef2ff; margin:12px 0;">
      <strong style="color:#3730a3;">🧠 Memory Aid:</strong>
      <span style="color:#1f2937;"> Use dummy head to simplify edge cases. Fast/slow pointers for middle and cycle detection. </span>
      <span style="color:#0f766e;">Reverse: prev=null, curr=head, save next, rewire, advance.</span>
   </div>

==========================
🔗 Linked Lists Cheatsheet
==========================

----

🏗️ Node Definition
====================

.. code-block:: cpp

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    // Doubly linked list
    struct DNode {
        int val;
        DNode* prev;
        DNode* next;
        DNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    };

    // Helper: build list from vector
    ListNode* build(vector<int> v) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        for (int x : v) { cur->next = new ListNode(x); cur = cur->next; }
        return dummy.next;
    }

----

🔄 Reverse Linked List
=======================

.. code-block:: cpp

    // Iterative — O(n) time O(1) space
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;  // new head
    }

    // Recursive
    ListNode* reverseRec(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseRec(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

----

🐇 Fast & Slow Pointers
========================

.. code-block:: cpp

    // Find middle (slow stops at middle)
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Detect cycle (Floyd's algorithm)
    bool hasCycle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // Find cycle start node
    ListNode* cycleStart(ListNode* head) {
        ListNode* slow = head, *fast = head;
        bool hasCycle = false;
        while (fast && fast->next) {
            slow = slow->next; fast = fast->next->next;
            if (slow == fast) { hasCycle = true; break; }
        }
        if (!hasCycle) return nullptr;
        slow = head;
        while (slow != fast) { slow = slow->next; fast = fast->next; }
        return slow;
    }

----

🔀 Merge Two Sorted Lists
==========================

.. code-block:: cpp

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) { cur->next = l1; l1 = l1->next; }
            else { cur->next = l2; l2 = l2->next; }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }

----

🗑️ Remove Nth from End
=======================

.. code-block:: cpp

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy, *slow = &dummy;
        for (int i = 0; i <= n; i++) fast = fast->next;
        while (fast) { slow = slow->next; fast = fast->next; }
        slow->next = slow->next->next;
        return dummy.next;
    }

----

🏛️ LRU Cache
=============

.. code-block:: cpp

    class LRUCache {
        int cap;
        list<pair<int,int>> lst;          // {key, value}
        unordered_map<int, list<pair<int,int>>::iterator> mp;
    public:
        LRUCache(int cap) : cap(cap) {}

        int get(int key) {
            if (!mp.count(key)) return -1;
            lst.splice(lst.begin(), lst, mp[key]);  // move to front
            return mp[key]->second;
        }

        void put(int key, int val) {
            if (mp.count(key)) {
                mp[key]->second = val;
                lst.splice(lst.begin(), lst, mp[key]);
                return;
            }
            if ((int)lst.size() == cap) {
                mp.erase(lst.back().first);
                lst.pop_back();
            }
            lst.push_front({key, val});
            mp[key] = lst.begin();
        }
    };

----

📌 Common Patterns
==================

.. code-block:: cpp

    // Reverse in groups of k
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) { curr = curr->next; count++; }
        if (count < k) return head;
        ListNode* newHead = reverse(head, k);
        head->next = reverseKGroup(curr, k);
        return newHead;
    }

    // Palindrome check
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMiddle(head);
        ListNode* rev = reverse(mid);
        ListNode* p1 = head, *p2 = rev;
        while (p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next; p2 = p2->next;
        }
        return true;
    }
