/*
 * Solution 1: Reverse Linked List
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* reverse(ListNode*h){ListNode*p=nullptr,*c=h;while(c){ListNode*n=c->next;c->next=p;p=c;c=n;}return p;}
int main(){
    ListNode*h=build({1,2,3,4,5}); print(h);
    print(reverse(h)); // 5->4->3->2->1
    return 0;
}
