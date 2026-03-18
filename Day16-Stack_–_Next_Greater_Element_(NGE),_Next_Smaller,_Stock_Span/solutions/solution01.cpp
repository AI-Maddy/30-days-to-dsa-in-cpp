/*
 * Solution 1: Next Greater Element
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>t(n);for(int&x:t)cin>>x;stack<int>st;vector<int>res(n,0);for(int i=0;i<n;i++){while(!st.empty()&&t[st.top()]<t[i]){res[st.top()]=i-st.top();st.pop();}st.push(i);}for(int x:res)cout<<x<<" ";cout<<"\n";return 0;}
