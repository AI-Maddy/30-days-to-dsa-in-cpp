/*
 * Example 3: Flatten Multilevel Doubly LL
 */
#include <bits/stdc++.h>
using namespace std;
struct Node{int val;Node*prev,*next,*child;Node(int v):val(v),prev(nullptr),next(nullptr),child(nullptr){}};
Node* flatten(Node*head){
    if(!head)return head;
    stack<Node*> st;
    Node*c=head;
    while(c){if(c->child){if(c->next)st.push(c->next);c->next=c->child;c->child->prev=c;c->child=nullptr;}
        if(!c->next&&!st.empty()){c->next=st.top();st.top()->prev=c;st.pop();}
        c=c->next;}
    return head;
}
int main(){
    Node a(1),b(2),c(3),d(4),e(5),f(6);
    a.next=&b;b.prev=&a;b.next=&c;c.prev=&b;b.child=&d;d.next=&e;e.prev=&d;e.next=&f;f.prev=&e;
    Node*h=flatten(&a);while(h){cout<<h->val<<" ";h=h->next;}cout<<"\n"; // 1 2 4 5 6 3
    return 0;
}
