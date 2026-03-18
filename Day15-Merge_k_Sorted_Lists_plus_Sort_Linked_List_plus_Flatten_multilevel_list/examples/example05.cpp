/*
 * Example 5: Intersection of Two LLs
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* getIntersect(ListNode*h1,ListNode*h2){
    ListNode*a=h1,*b=h2;
    while(a!=b){a=a?a->next:h2;b=b?b->next:h1;}
    return a;
}
int main(){
    // Build intersecting lists: 1->2->3->4->5, 6->4->5 (intersect at 4)
    ListNode n1(1),n2(2),n3(4),n4(5),n5(6);
    n1.next=&n2;n2.next=&n3;n3.next=&n4;n5.next=&n3;
    ListNode*inter=getIntersect(&n1,&n5);
    cout<<(inter?inter->val:-1)<<"\n"; // 4
    return 0;
}
