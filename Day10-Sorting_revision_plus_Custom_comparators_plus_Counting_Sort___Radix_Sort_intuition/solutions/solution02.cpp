/*
 * Solution 2: Selection Sort Pass
 */
#include <bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&x:a)cin>>x;int mx=*max_element(a.begin(),a.end());vector<int>cnt(mx+1,0);for(int x:a)cnt[x]++;for(int v=0;v<=mx;v++)while(cnt[v]--)cout<<v<<" ";cout<<"\n";return 0;}
