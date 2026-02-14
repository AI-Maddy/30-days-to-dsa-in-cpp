/*
 * Solution 5: Detect and Remove Cycle in Linked List
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(Node* head) {
        if (!head || !head->next) return false;
        
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
    
    void removeCycle(Node* head) {
        if (!head || !head->next) return;
        
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        if (!fast || !fast->next) return;
        
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head->next;
    
    Solution sol;
    cout << "Has cycle: " << (sol.hasCycle(head) ? "Yes" : "No") << endl;
    
    return 0;
}
