/*
 * Solution 1: Merge K Sorted Lists
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* mergeK(vector<ListNode*>&lists){
    auto cmp=[](ListNode*a,ListNode*b){return a->val>b->val;};
    priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);
    for(auto l:lists) if(l) pq.push(l);
    ListNode d(0);ListNode*c=&d;
    while(!pq.empty()){c->next=pq.top();pq.pop();c=c->next;if(c->next)pq.push(c->next);}
    return d.next;
}
int main(){
    vector<ListNode*> lists={build({1,4,5}),build({1,3,4}),build({2,6})};
    print(mergeK(lists)); // 1->1->2->3->4->4->5->6
    return 0;
}
