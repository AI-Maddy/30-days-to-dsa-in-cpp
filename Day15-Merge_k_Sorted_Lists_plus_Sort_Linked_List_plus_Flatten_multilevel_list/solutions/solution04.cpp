/*
 * Solution 4: Add Two Numbers LL
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* addTwoNumbers(ListNode*l1,ListNode*l2){
    ListNode d(0);ListNode*c=&d;int carry=0;
    while(l1||l2||carry){int s=carry;if(l1){s+=l1->val;l1=l1->next;}if(l2){s+=l2->val;l2=l2->next;}carry=s/10;c->next=new ListNode(s%10);c=c->next;}
    return d.next;
}
int main(){
    print(addTwoNumbers(build({2,4,3}),build({5,6,4}))); // 7->0->8 (342+465=807)
    return 0;
}
