/*
 * Solution 2: Sort Linked List
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* mid(ListNode*h,ListNode*t){ListNode*s=h,*f=h;while(f!=t&&f->next!=t){s=s->next;f=f->next->next;}return s;}
ListNode* merge(ListNode*a,ListNode*b){ListNode d(0);ListNode*c=&d;while(a&&b){if(a->val<=b->val){c->next=a;a=a->next;}else{c->next=b;b=b->next;}c=c->next;}c->next=a?a:b;return d.next;}
ListNode* mergeSort(ListNode*h,ListNode*t){if(h==t||!h)return h;ListNode*m=mid(h,t);ListNode*r=m->next;m->next=nullptr;return merge(mergeSort(h,m),mergeSort(r,t));}
ListNode* sortList(ListNode*h){if(!h||!h->next)return h;ListNode*t=h;while(t->next)t=t->next;return mergeSort(h,t);}
int main(){
    print(sortList(build({4,2,1,3}))); // 1->2->3->4
    return 0;
}
