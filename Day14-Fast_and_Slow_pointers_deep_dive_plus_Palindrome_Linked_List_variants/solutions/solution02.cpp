/*
 * Solution 2: Find Cycle Start
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* cycleStart(ListNode*h){
    ListNode*s=h,*f=h; bool found=false;
    while(f&&f->next){s=s->next;f=f->next->next;if(s==f){found=true;break;}}
    if(!found)return nullptr; s=h;
    while(s!=f){s=s->next;f=f->next;}
    return s;
}
int main(){
    // Build list with cycle: 1->2->3->4->5->3
    ListNode*h=build({1,2,3,4,5}); ListNode*c=h; while(c->val!=5)c=c->next;
    ListNode*cs=h; while(cs->val!=3)cs=cs->next; c->next=cs;
    ListNode*start=cycleStart(h);
    cout<<(start?start->val:-1)<<"\n"; // 3
    return 0;
}
