/*
 * Solution 4: Reorder List
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
// Reorder: L0->Ln->L1->Ln-1->...
void reorder(ListNode*h){
    if(!h||!h->next)return;
    ListNode*s=h,*f=h;while(f->next&&f->next->next){s=s->next;f=f->next->next;}
    ListNode*second=s->next; s->next=nullptr;
    ListNode*p=nullptr,*c=second;while(c){ListNode*n=c->next;c->next=p;p=c;c=n;} second=p;
    ListNode*p1=h,*p2=second;
    while(p2){ListNode*n1=p1->next,*n2=p2->next;p1->next=p2;p2->next=n1;p1=n1;p2=n2;}
}
int main(){
    ListNode*h=build({1,2,3,4,5});reorder(h);print(h); // 1->5->2->4->3
    return 0;
}
