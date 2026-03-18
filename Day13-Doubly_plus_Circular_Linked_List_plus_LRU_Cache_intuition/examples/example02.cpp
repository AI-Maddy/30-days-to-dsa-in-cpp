/*
 * Example 2: Circular Linked List Ops
 */
#include <bits/stdc++.h>
using namespace std;
struct Node{int val;Node*next;Node(int x):val(x),next(nullptr){}};
Node* insertCircular(Node*tail,int val){Node*n=new Node(val);if(!tail){n->next=n;return n;}n->next=tail->next;tail->next=n;return n;}
void print(Node*tail,int k){Node*c=tail->next;for(int i=0;i<k;i++){cout<<c->val<<" ";c=c->next;}cout<<"\n";}
bool detectLoop(Node*head){Node*s=head,*f=head;while(f&&f->next){s=s->next;f=f->next->next;if(s==f)return true;}return false;}
int main(){
    Node*tail=nullptr;for(int x:{1,2,3,4,5}) tail=insertCircular(tail,x);
    print(tail,5);
    cout<<"Loop: "<<detectLoop(tail->next)<<"\n"; // 1 (circular IS a loop)
    return 0;
}
