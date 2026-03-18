/*
 * Solution 2: Container With Most Water (1D Arrays – Two Pointers and Sliding Window basics)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> h(n); for(int&x:h)cin>>x;
    int l=0,r=n-1,ans=0;
    while(l<r){ans=max(ans,min(h[l],h[r])*(r-l)); if(h[l]<h[r])l++; else r--;}
    cout<<ans<<"\n"; return 0;
}
