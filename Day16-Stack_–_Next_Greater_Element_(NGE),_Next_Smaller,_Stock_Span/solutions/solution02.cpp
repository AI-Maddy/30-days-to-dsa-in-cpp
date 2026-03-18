/*
 * Solution 2: Next Smaller Element
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>h(n);for(int&x:h)cin>>x;h.push_back(0);stack<int>st;int ans=0;for(int i=0;i<(int)h.size();i++){while(!st.empty()&&h[st.top()]>h[i]){int ht=h[st.top()];st.pop();int w=st.empty()?i:i-st.top()-1;ans=max(ans,ht*w);}st.push(i);}cout<<ans<<"\n";return 0;}
