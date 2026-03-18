/*
 * Solution 1: Doubly Linked List Ops
 */
#include <bits/stdc++.h>
using namespace std;
struct DNode{int val;DNode*prev,*next;DNode(int x):val(x),prev(nullptr),next(nullptr){}};
DNode* insertFront(DNode*head,int val){DNode*n=new DNode(val);if(head){n->next=head;head->prev=n;}return n;}
DNode* deleteNode(DNode*head,int val){DNode*c=head;while(c&&c->val!=val)c=c->next;if(!c)return head;if(c->prev)c->prev->next=c->next;else head=c->next;if(c->next)c->next->prev=c->prev;return head;}
DNode* reversDLL(DNode*head){DNode*c=head,*last=nullptr;while(c){DNode*n=c->next;c->next=c->prev;c->prev=n;last=c;c=n;}return last;}
void print(DNode*h){while(h){cout<<h->val;if(h->next)cout<<"<->";h=h->next;}cout<<"\n";}
int main(){
    DNode*h=nullptr; for(int x:{5,4,3,2,1}) h=insertFront(h,x); print(h);
    h=deleteNode(h,3); print(h);
    print(reversDLL(h));
    return 0;
}
