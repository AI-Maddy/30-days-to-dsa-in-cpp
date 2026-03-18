/*
 * Example 5: Queue using Stack
 */
#include <bits/stdc++.h>
using namespace std;
// Queue using two stacks (amortized O(1))
class MyQueue{stack<int>in,out;
    void transfer(){while(!in.empty()){out.push(in.top());in.pop();}}
public:
    void push(int v){in.push(v);}
    int pop(){if(out.empty())transfer();int v=out.top();out.pop();return v;}
    int peek(){if(out.empty())transfer();return out.top();}
    bool empty(){return in.empty()&&out.empty();}
};
int main(){
    MyQueue q;q.push(1);q.push(2);q.push(3);
    cout<<q.peek()<<"\n"; // 1
    cout<<q.pop()<<"\n";  // 1
    cout<<q.peek()<<"\n"; // 2
    return 0;
}
