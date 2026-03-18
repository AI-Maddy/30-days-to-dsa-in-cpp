/*
 * Example 1: Happy Number
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(nullptr){}};
ListNode* build(vector<int>v){ListNode d(0);ListNode*c=&d;for(int x:v){c->next=new ListNode(x);c=c->next;}return d.next;}
void print(ListNode*h){while(h){cout<<h->val;if(h->next)cout<<"->";h=h->next;}cout<<"\n";}
int digitSquareSum(int n){int s=0;while(n){int d=n%10;s+=d*d;n/=10;}return s;}
bool isHappy(int n){int s=n,f=n;do{s=digitSquareSum(s);f=digitSquareSum(digitSquareSum(f));}while(s!=f);return s==1;}
int main(){
    cout<<isHappy(19)<<"\n"; // 1 (happy)
    cout<<isHappy(2)<<"\n";  // 0 (not happy)
    return 0;
}
