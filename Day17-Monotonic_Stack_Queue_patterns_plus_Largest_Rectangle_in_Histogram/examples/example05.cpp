/*
 * Example 5: RPN Evaluate
 */
#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>&tokens){
    stack<long long>st;
    for(auto&t:tokens){if(t=="+"||t=="-"||t=="*"||t=="/"){long long b=st.top();st.pop();long long a=st.top();st.pop();if(t=="+")st.push(a+b);else if(t=="-")st.push(a-b);else if(t=="*")st.push(a*b);else st.push(a/b);}else st.push(stoll(t));}
    return st.top();
}
int main(){
    vector<string> t1={"2","1","+","3","*"}; cout<<evalRPN(t1)<<"\n"; // 9
    vector<string> t2={"4","13","5","/","+"}; cout<<evalRPN(t2)<<"\n"; // 6
    return 0;
}
