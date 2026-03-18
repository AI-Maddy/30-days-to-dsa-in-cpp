/*
 * Solution 2: Next Greater Element
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;vector<int>res(n,-1);stack<int>st;for(int i=0;i<n;i++){while(!st.empty()&&a[st.top()]<a[i]){res[st.top()]=a[i];st.pop();}st.push(i);}for(int x:res)cout<<x<<" ";cout<<"\n";return 0;}
