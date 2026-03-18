/*
 * Solution 3: Stock Span
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>h(n);for(int&x:h)cin>>x;stack<int>st;int water=0;for(int i=0;i<n;i++){while(!st.empty()&&h[st.top()]<=h[i]){int bot=h[st.top()];st.pop();if(!st.empty()){int dist=i-st.top()-1;water+=dist*(min(h[i],h[st.top()])-bot);}}st.push(i);}cout<<water<<"\n";return 0;}
