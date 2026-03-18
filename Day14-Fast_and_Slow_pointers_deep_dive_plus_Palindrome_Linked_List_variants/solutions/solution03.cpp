/*
 * Solution 3: Palindrome Linked List
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* rev(ListNode*h){ListNode*p=nullptr,*c=h;while(c){ListNode*n=c->next;c->next=p;p=c;c=n;}return p;}
ListNode* mid(ListNode*h){ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;}return s;}
bool isPalindrome(ListNode*h){
    ListNode*m=mid(h),*r=rev(m);
    ListNode*p1=h,*p2=r; bool ok=true;
    while(p2){if(p1->val!=p2->val){ok=false;break;}p1=p1->next;p2=p2->next;}
    return ok;
}
int main(){
    cout<<isPalindrome(build({1,2,2,1}))<<"\n"; // 1
    cout<<isPalindrome(build({1,2,3}))<<"\n";   // 0
    return 0;
}
