/*
 * Example 5: Remove Nth from End
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* removeNth(ListNode*head,int n){ListNode d(0);d.next=head;ListNode*f=&d,*s=&d;for(int i=0;i<=n;i++)f=f->next;while(f){s=s->next;f=f->next;}s->next=s->next->next;return d.next;}
int main(){
    print(removeNth(build({1,2,3,4,5}),2)); // 1->2->3->5
    return 0;
}
