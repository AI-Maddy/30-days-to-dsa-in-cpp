/*
 * Example 4: Merge Two Sorted Lists
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* mergeTwoLists(ListNode*a,ListNode*b){ListNode d(0);ListNode*c=&d;while(a&&b){if(a->val<=b->val){c->next=a;a=a->next;}else{c->next=b;b=b->next;}c=c->next;}c->next=a?a:b;return d.next;}
int main(){
    print(mergeTwoLists(build({1,3,5}),build({2,4,6}))); // 1->2->3->4->5->6
    return 0;
}
