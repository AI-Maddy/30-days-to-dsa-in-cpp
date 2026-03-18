/*
 * Solution 5: RPN Evaluate
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<string>tok(n);for(auto&t:tok)cin>>t;stack<long long>st;for(auto&t:tok){if(t=="+"||t=="-"||t=="*"||t=="/"){long long b=st.top();st.pop();long long a=st.top();st.pop();if(t=="+")st.push(a+b);else if(t=="-")st.push(a-b);else if(t=="*")st.push(a*b);else st.push(a/b);}else st.push(stoll(t));}cout<<st.top()<<"\n";return 0;}
