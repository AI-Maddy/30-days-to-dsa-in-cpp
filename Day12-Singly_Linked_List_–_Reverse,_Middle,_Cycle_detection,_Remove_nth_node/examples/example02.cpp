/*
 * Example 2: Find Middle Node
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
ListNode* middle(ListNode*h){ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;}return s;}
int main(){
    print(middle(build({1,2,3,4,5}))); // 3
    print(middle(build({1,2,3,4,5,6}))); // 4
    return 0;
}
