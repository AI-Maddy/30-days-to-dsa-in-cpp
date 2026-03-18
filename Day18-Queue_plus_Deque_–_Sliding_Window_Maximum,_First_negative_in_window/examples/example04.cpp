/*
 * Example 4: Stack using Queue
 */
#include <bits/stdc++.h>
using namespace std;
// Stack using two queues
class MyStack{queue<int>q1,q2;
public:
    void push(int v){q2.push(v);while(!q1.empty()){q2.push(q1.front());q1.pop();}swap(q1,q2);}
    int pop(){int v=q1.front();q1.pop();return v;}
    int top(){return q1.front();}
    bool empty(){return q1.empty();}
};
int main(){
    MyStack s;s.push(1);s.push(2);s.push(3);
    cout<<s.top()<<"\n"; // 3
    s.pop(); cout<<s.top()<<"\n"; // 2
    return 0;
}
