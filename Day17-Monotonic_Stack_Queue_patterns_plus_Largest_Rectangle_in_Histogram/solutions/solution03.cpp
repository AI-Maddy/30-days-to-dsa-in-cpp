/*
 * Solution 3: Stock Span
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>p(n);for(int&x:p)cin>>x;vector<int>sp(n);stack<int>st;for(int i=0;i<n;i++){while(!st.empty()&&p[st.top()]<=p[i])st.pop();sp[i]=st.empty()?i+1:i-st.top();st.push(i);}for(int x:sp)cout<<x<<" ";cout<<"\n";return 0;}
