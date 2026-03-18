/*
 * Example 5: Min Stack
 */
#include <bits/stdc++.h>
using namespace std;
class MinStack{stack<int> st,minSt;
public:
    void push(int v){st.push(v);if(minSt.empty()||v<=minSt.top())minSt.push(v);}
    void pop(){if(st.top()==minSt.top())minSt.pop();st.pop();}
    int top(){return st.top();}
    int getMin(){return minSt.top();}
};
int main(){
    MinStack ms; ms.push(-2);ms.push(0);ms.push(-3);
    cout<<ms.getMin()<<"\n"; // -3
    ms.pop();
    cout<<ms.top()<<"\n";    // 0
    cout<<ms.getMin()<<"\n"; // -2
    return 0;
}
