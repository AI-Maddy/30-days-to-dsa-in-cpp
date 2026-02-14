/*
 * Exercise 5: Find Middle of Linked List
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
    Node* findMiddle(Node* head) {
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    Solution sol;
    Node* mid = sol.findMiddle(head);
    cout << "Middle node value: " << mid->data << endl;
    
    return 0;
}
