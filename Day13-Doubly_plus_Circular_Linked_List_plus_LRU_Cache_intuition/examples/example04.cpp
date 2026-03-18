/*
 * Example 4: Sort Doubly Linked List
 */
#include <bits/stdc++.h>
using namespace std;
struct DNode{int val;DNode*prev,*next;DNode(int x):val(x),prev(nullptr),next(nullptr){}};
// Merge sort on DLL
DNode* getMiddle(DNode*h){DNode*s=h,*f=h;while(f->next&&f->next->next){s=s->next;f=f->next->next;}return s;}
DNode* merge(DNode*a,DNode*b){if(!a)return b;if(!b)return a;if(a->val<=b->val){a->next=merge(a->next,b);if(a->next)a->next->prev=a;a->prev=nullptr;return a;}else{b->next=merge(a,b->next);if(b->next)b->next->prev=b;b->prev=nullptr;return b;}}
DNode* mergeSort(DNode*h){if(!h||!h->next)return h;DNode*m=getMiddle(h);DNode*r=m->next;m->next=nullptr;if(r)r->prev=nullptr;return merge(mergeSort(h),mergeSort(r));}
void print(DNode*h){while(h){cout<<h->val<<" ";h=h->next;}cout<<"\n";}
int main(){
    DNode n1(5),n2(1),n3(3),n4(2),n5(4);n1.next=&n2;n2.prev=&n1;n2.next=&n3;n3.prev=&n2;n3.next=&n4;n4.prev=&n3;n4.next=&n5;n5.prev=&n4;
    print(mergeSort(&n1));
    return 0;
}
