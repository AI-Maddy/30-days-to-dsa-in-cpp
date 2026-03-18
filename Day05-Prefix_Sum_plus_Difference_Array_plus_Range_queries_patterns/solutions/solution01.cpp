/*
 * Solution 1: Prefix Sum Query (Prefix Sum plus Difference Array plus Range queries patterns)
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; vector<int> a(n); for(int&x:a)cin>>x;
    vector<int> pre(n+1,0); for(int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
    int q; cin>>q; while(q--){int l,r;cin>>l>>r;cout<<pre[r+1]-pre[l]<<"\n";}
    return 0;
}
