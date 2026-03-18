/*
 * Example 3: Cycle Detection
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
bool hasCycle(ListNode*h){ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;if(s==f)return true;}return false;}
ListNode* cycleStart(ListNode*h){ListNode*s=h,*f=h;bool found=false;while(f&&f->next){s=s->next;f=f->next->next;if(s==f){found=true;break;}}if(!found)return nullptr;s=h;while(s!=f){s=s->next;f=f->next;}return s;}
int main(){
    // No cycle
    ListNode*h=build({1,2,3,4,5}); cout<<hasCycle(h)<<"\n"; // 0
    // Create cycle: 5->3
    ListNode*a=build({1,2,3,4,5}); ListNode*c=a; while(c->next->next)c=c->next; ListNode*start=a->next->next; c->next->next=start;
    cout<<hasCycle(a)<<"\n"; // 1
    cout<<cycleStart(a)->val<<"\n"; // 3
    return 0;
}
